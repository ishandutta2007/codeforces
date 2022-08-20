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
    let T: u32 = stdin.next();
    for _ in 0..T {
        let rgb: Vec<i64> = (0..3).map(|_| stdin.next()).collect();
        let sum: i64 = rgb.iter().sum();
        let max = *rgb.iter().max().unwrap();
        if max > (sum + 1) / 2 {
            writeln!(&mut stdout, "No").unwrap();
        } else {
            writeln!(&mut stdout, "Yes").unwrap();
        }
    }
}