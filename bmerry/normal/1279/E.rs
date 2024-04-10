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
        let N: usize = stdin.next();
        let mut k: i64 = stdin.next::<i64>() - 1;

        let mut fact = vec![0i64; N + 1];
        fact[0] = 1;
        for i in 1..N + 1 {
            fact[i] = fact[i - 1].saturating_mul(i as i64);
        }

        let mut piece = vec![0i64; N + 1];
        piece[0] = 1;
        piece[1] = 1;
        for i in 2..N + 1 {
            piece[i] = fact[i - 2];
        }

        let mut nperms = vec![0i64; N + 1];
        nperms[0] = 1;
        for i in 1..N + 1 {
            nperms[i] = piece[i];
            for j in 1..i {
                nperms[i] = nperms[i].saturating_add(piece[j].saturating_mul(nperms[i - j]));
            }
        }

        let mut pos = 0;
        let mut ans = vec![0; N];
        let mut chain: Vec<_> = (0..N).collect();
        let mut rchain: Vec<_> = (0..N).collect();
        while pos < N {
            let mut s = 1;
            let rem = N - pos;
            while s <= rem {
                let cur = piece[s].saturating_mul(nperms[rem - s]);
                if k < cur {
                    break;
                }
                k -= cur;
                s += 1;
            }
            if s > rem {
                break;
            }
            let tail = nperms[rem - s];
            let end = pos + s;
            ans[pos] = end - 1;

            chain[pos] = end - 1;
            rchain[end - 1] = pos;
            ans[pos] = end - 1;
            for i in pos + 1..end {
                for j in pos..end - 1 {
                    if rchain[j] != j || i == j || (chain[j] == i && i != end - 1) {
                        continue;
                    }
                    let sz = fact[end.saturating_sub(i + 2)].saturating_mul(tail);
                    if k < sz {
                        ans[i] = j;
                        chain[i] = chain[j];
                        rchain[j] = rchain[i];
                        chain[rchain[i]] = chain[j];
                        rchain[chain[j]] = rchain[i];
                        break;
                    }
                    k -= sz;
                }
            }
            pos = end;
        }

        if pos < N {
            writeln!(&mut stdout, "-1").unwrap();
        } else {
            for v in ans.iter() {
                write!(&mut stdout, "{} ", v + 1).unwrap();
            }
            writeln!(&mut stdout).unwrap();
        }
    }
}