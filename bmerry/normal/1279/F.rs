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

/* End template code */

fn solve1(v: &[i64], L: usize, mid: i64, dp: &mut [i64], need: &mut [usize]) -> (i64, usize) {
    let N = v.len() - 1;
    for i in 1..N + 1 {
        let prev = i.saturating_sub(L);
        let dp2 = dp[prev] + (v[i] - v[prev]) - mid;
        let need2 = need[prev] + 1;
        if dp2 > dp[i - 1] || (dp2 == dp[i - 1] && need2 < need[i - 1]) {
            dp[i] = dp2;
            need[i] = need2;
        } else {
            dp[i] = dp[i - 1];
            need[i] = need[i - 1];
        }
    }
    (dp[N], need[N])
}

fn solve(v: &[i64], K: usize, L: usize) -> i64 {
    let N = v.len() - 1;
    if K.saturating_mul(L) >= N {
        return 0;
    }
    let mut lo = -1;
    let mut hi = L as i64;
    let mut dp = vec![0i64; N + 1];
    let mut need = vec![0usize; N + 1];
    while hi - lo > 1 {
        let mid = lo + (hi - lo) / 2;
        let (_, n) = solve1(v, L, mid, &mut dp, &mut need);
        if n <= K {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    let (d, n) = solve1(v, L, hi, &mut dp, &mut need);
    assert!(n <= K);
    let fix = d + K as i64 * hi;
    assert!(fix <= v[N]);
    v[N] - fix
}

fn main() {
    let mut stdin = Scanner::new();

    let N: usize = stdin.next();
    let K: usize = stdin.next();
    let L: usize = stdin.next();
    let S: String = stdin.next();
    let mut v = vec![0; N + 1];
    for (i, c) in S.chars().enumerate() {
        v[i + 1] = v[i] + ('a' <= c && c <= 'z') as i64;
    }

    let ans1 = solve(&v, K, L);
    for (i, x) in v.iter_mut().enumerate() {
        *x = i as i64 - *x;
    }
    let ans2 = solve(&v, K, L);
    let ans = ans1.min(ans2);
    println!("{}", ans);
}