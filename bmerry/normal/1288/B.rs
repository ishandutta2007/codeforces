#![allow(non_snake_case)]

/* Template code */

use std::io::{self, Cursor, Split, BufRead};
use std::str::FromStr;

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

/* End template code */

fn main() {
    let mut scan = Scanner::new();
    let T: i32 = scan.next();
    for _ in 1..=T {
        let A: i64 = scan.next();
        let B: i64 = scan.next();
        let mut b = 9;
        let mut m = 0;
        while b <= B {
            b = b * 10 + 9;
            m += 1;
        }
        println!("{}", A * m);
    }
}