#![allow(non_snake_case)]

use std::io;
use std::str::FromStr;
use std::fmt::Debug;

struct Scanner {
    buffer: Vec<String>,
    pos: usize
}

impl Scanner {
    pub fn new() -> Scanner {
        Scanner { buffer: Vec::new(), pos: 0 }
    }

    pub fn next<T: FromStr + Copy + Debug>(&mut self) -> io::Result<T> {
        loop {
            if let Some(token) = self.buffer.get(self.pos) {
                self.pos += 1;
                return Ok(token.parse().ok().unwrap());
            }

            let mut line = String::new();
            io::stdin().read_line(&mut line)?;
            self.buffer = line.split_whitespace().map(String::from).collect();
            self.pos = 0;
        }
    }
}

fn main() -> io::Result<()> {
    let mut scan = Scanner::new();
    let T: i32 = scan.next()?;
    for _ in 0..T {
        let n: i64 = scan.next()?;
        let d: i64 = scan.next()?;
        let mut prev: i64 = std::i64::MAX;
        let mut x = 0;
        let found = loop {
            let cur = x + (d + x) / (x + 1);
            if cur <= n {
                break true;
            } else if cur > prev {
                break false;
            }
            prev = cur;
            x += 1;
        };
        if found {
            println!("YES");
        } else {
            println!("NO");
        }
    }
    Ok(())
}