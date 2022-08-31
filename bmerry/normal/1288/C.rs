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

const MOD: i32 = 1000000007;

fn main() {
    let mut scan = Scanner::new();
    let n: usize = scan.next();
    let m: i32 = scan.next();
    let m = 2 * m;
    let mut dp = vec![1; n];
    for _ in 0..m {
        for j in (0..n - 1).rev() {
            dp[j] = (dp[j] + dp[j + 1]) % MOD;
        }
    }
    println!("{}", dp[0]);
}