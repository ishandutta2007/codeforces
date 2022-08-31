#![allow(non_snake_case)]

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

#[derive(Default)]
struct BIT<T: Copy, Op: Fn(&T, &T) -> T>
{
    values: Vec<T>,
    op: Op,
    identity: T
}

impl<T: Copy, Op: Fn(&T, &T) -> T> BIT<T, Op> {
    pub fn new(size: usize, op: Op, identity: T) -> BIT<T, Op> {
        BIT { values: vec![identity; size + 1], op, identity }
    }

    pub fn len(&self) -> usize {
        self.values.len() - 1
    }

    pub fn add(&mut self, idx: usize, delta: T) {
        let mut idx = idx + 1;
        while idx < self.values.len() {
            self.values[idx] = (self.op)(&self.values[idx], &delta);
            idx += idx & !(idx - 1);
        }
    }

    // Sum of values up to and including idx
    pub fn sum(&self, idx: usize) -> T {
        let mut ans = self.identity;
        let mut idx = idx + 1;
        while idx > 0 {
            ans = (self.op)(&ans, &self.values[idx]);
            idx &= idx - 1;
        }
        ans
    }

    pub fn sum_exclusive(&self, idx: usize) -> T {
        match idx {
            0 => self.identity.clone(),
            _ => self.sum(idx - 1)
        }
    }
}

#[derive(Eq)]
struct Query {
    l: usize,
    r: usize,
    m: isize,
    id: usize
}

impl PartialEq for Query {
    fn eq(&self, other: &Query) -> bool {
        self.m == other.m
    }
}

impl PartialOrd for Query {
    fn partial_cmp(&self, other: &Query) -> Option<Ordering> {
        self.m.partial_cmp(&other.m)
    }
}

impl Ord for Query {
    fn cmp(&self, other: &Query) -> Ordering {
        self.m.cmp(&other.m)
    }
}

fn main() {
    let mut scan = Scanner::new();
    let N = scan.next();
    let M: usize = scan.next();
    let mut last = vec![0; N];
    for i in 0..N {
        last[i] = N - 1 - i;
    }
    let mut queries = vec![];
    let mut values: Vec<(isize, usize)> = (0..N).map(|i| (-1, i)).collect();
    for i in N..M + N {
        let a: usize = scan.next();
        let a = a - 1;
        queries.push(Query { l: last[a] + 1, r: i, m: last[a] as isize, id: a});
        values.push((last[a] as isize, i));
        last[a] = i;
    }
    for i in 0..N {
        queries.push(Query { l: last[i] + 1, r: M + N, m: last[i] as isize, id: i });
    }

    queries.sort();
    values.sort();
    let mut p = 0;
    let mut cnt = BIT::new(N + M + 1, |x, y| x + y, 0i32);
    let mut high = vec![0; N];
    for q in queries.iter() {
        while p < values.len() && values[p].0 < q.m {
            cnt.add(values[p].1, 1);
            p += 1;
        }
        let v = cnt.sum_exclusive(q.r) - cnt.sum_exclusive(q.l);
        high[q.id] = high[q.id].max(v);
    }

    let mut stdout = get_stdout();
    for i in 0..N {
        let low = if last[i] < N { i } else { 0 };
        writeln!(&mut stdout, "{} {}", low + 1, high[i] + 1).unwrap();
    }
}