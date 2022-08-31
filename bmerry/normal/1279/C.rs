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

    let T = stdin.next();
    for _ in 0..T {
        let N: usize = stdin.next();
        let M: usize = stdin.next();
        let mut pos = vec![0u32; N];
        for i in 0..N {
            let a: usize = stdin.next();
            let a = a - 1;
            pos[a] = i as u32;
        }
        let mut deep = 0;
        let mut ans: u64 = 0;
        for i in 0..M {
            let b: usize = stdin.next();
            let b = b - 1;
            let p = pos[b];
            if p > deep {
                ans += (2 * (p - i as u32) + 1) as u64;
                deep = p;
            } else {
                ans += 1;
            }
        }
        writeln!(&mut stdout, "{}", ans).unwrap();
    }
}