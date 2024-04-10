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
    let N = scan.next();
    let M = scan.next();
    let M2 = 1 << (M as i32);
    let mut a = vec![vec![0; M]; N];
    for i in 0..N {
        for j in 0..M {
            a[i][j] = scan.next();
        }
    }

    let mut lo = 0;
    let mut hi = 1000000001;
    let mut ans = [0, 0];
    let mut b = vec![0; M2];
    while hi - lo > 1 {
        for x in b.iter_mut() {
            *x = -1;
        }
        let mid = lo + (hi - lo) / 2;
        for i in 0..N {
            let mut mask = 0;
            for j in 0..M {
                if a[i][j] >= mid {
                    mask |= 1 << j;
                }
            }
            b[mask] = i as i32;
        }

        let mut found = false;
        'outer: for i in 0..M2 {
            if b[i] == -1 {
                continue;
            }
            let mut j = i;
            loop {
                let other = (M2 - 1 - i) | j;
                if b[other] != -1 {
                    ans[0] = b[i];
                    ans[1] = b[other];
                    found = true;
                    break 'outer;
                }
                if j == 0 {
                    break;
                }
                j = (j - 1) & i;
            }
        }
        if found {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    ans.sort();
    println!("{} {}", ans[0] + 1, ans[1] + 1);
}