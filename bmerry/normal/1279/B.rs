#![allow(non_snake_case, unused_imports, dead_code)]

/* Template code */

use std::io::{self, Cursor, Split, BufRead, Write, BufWriter, Stdout};
use std::str::FromStr;
use std::cmp::Ordering;

struct Scanner {
    fields: Split<Cursor<String>>
}

impl Scanner {
    pub fn new() -> Scanner {
        Scanner { fields: Cursor::new(String::new()).split(b' ') }
    }

    pub fn next<T: FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.fields.next() {
                let bytes = token.unwrap();
                return std::str::from_utf8(&bytes).unwrap().trim().parse().ok().expect("parse failed");
            }

            let mut line = String::new();
            io::stdin().read_line(&mut line).expect("readline failed");
            let cursor = Cursor::new(line);
            self.fields = cursor.split(b' ');
        }
    }
}

fn get_stdout() -> BufWriter<Stdout> {
    return BufWriter::new(io::stdout());
}

/* End template code */

fn main() {
    let mut stdin = Scanner::new();
    let mut stdout = get_stdout();

    let T: i32 = stdin.next();
    for _ in 0..T {
        let n: i32 = stdin.next();
        let s: i64 = stdin.next();
        let mut mx = 0;
        let mut total = 0;
        let mut mxi = -1;
        let mut best = 0;
        let mut ans = -1;
        for i in 0..n {
            let a: i64 = stdin.next();
            total += a;
            if a > mx {
                mx = a;
                mxi = i;
            }
            if total <= s {
                best = i + 1;
                ans = -1;
            }
            if total - mx <= s && best < i {
                best = i;
                ans = mxi;
            }
        }
        writeln!(&mut stdout, "{}", ans + 1).unwrap();
    }
}