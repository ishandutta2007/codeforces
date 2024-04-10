#![allow(non_snake_case, unused_imports, dead_code)]

/* Template code */

use std::io::{self, Cursor, Split, BufRead, Write, BufWriter, Stdout};
use std::str::FromStr;
use std::cmp::Ordering;
use std::collections::HashMap;
use std::convert::TryInto;
use std::fmt;
use std::ops::*;

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

fn wrap_pos<T: PartialOrd + Add<Output = T> + Default>(a: T, m: T) -> T {
    if a >= <T as Default>::default() { a } else { a + m }
}

fn wrap_sum<T: PartialOrd + Sub<Output = T> + Default>(a: T, m: T) -> T {
    if a < m { a } else { a - m }
}

fn modulus<T: PartialOrd + Add<Output = T> + Rem<Output = T> + Default + Copy>(x: T, y: T) -> T {
    wrap_pos(x % y, y)
}

fn inverse2<T: PartialOrd + Add<Output = T> + Sub<Output = T> + Rem<Output = T> + Div<Output = T> + Mul<Output = T> + From<i32> + Copy + Default>(a: T, m: T) -> T {
    let one: T = 1.into();
    if a <= one {
        a
    } else {
        modulus((one - inverse2(m % a, a) * m) / a, m)
    }
}

fn inverse<T: PartialOrd + Add<Output = T> + Sub<Output = T> + Rem<Output = T> + Div<Output = T> + Mul<Output = T> + From<i32> + Copy + Default>(a: T, m: T) -> T {
    inverse2(modulus(a, m), m)
}

type ModRingT = i32;
type ModRingC = i64;

const MOD: ModRingT = 998244353;

#[derive(Default, Copy, Clone)]
struct ModRing(ModRingT);

impl ModRing {
    fn inverse(&self) -> ModRing {
        ModRing(inverse(self.0 as ModRingC, MOD as ModRingC).try_into().unwrap())
    }
}

impl<T: From<ModRingT> + TryInto<ModRingT> + Rem<Output = T>> From<T> for ModRing {
    fn from(value: T) -> ModRing {
        let mod_t: T = MOD.into();
        ModRing(wrap_pos((value % mod_t).try_into().ok().unwrap(), MOD))
    }
}

impl Add for ModRing {
    type Output = Self;

    fn add(self, value: Self) -> Self {
        ModRing(wrap_sum(self.0 + value.0, MOD))
    }
}

impl Sub for ModRing {
    type Output = Self;

    fn sub(self, value: Self) -> Self {
        ModRing(wrap_pos(self.0 - value.0, MOD))
    }
}

impl Mul for ModRing {
    type Output = Self;

    fn mul(self, value: Self) -> Self {
        let prod = (self.0 as ModRingC) * (value.0 as ModRingC);
        ModRing((prod % (MOD as ModRingC)) as ModRingT)
    }
}

impl Div for ModRing {
    type Output = Self;

    fn div(self, value: Self) -> Self {
        self * value.inverse()
    }
}

impl fmt::Display for ModRing {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.0)
    }
}

fn main() {
    let mut stdin = Scanner::new();
    let mut stdout = get_stdout();

    let N = stdin.next();
    let mut a: Vec<Vec<i32>> = vec![vec![0; 0]; N];
    let mut hits: HashMap<i32, usize> = HashMap::new();
    for i in 0..N {
        let k: usize = stdin.next();
        for _ in 0..k {
            let v = stdin.next();
            a[i].push(v);
            *hits.entry(v).or_default() += 1;
        }
    }

    let mut ans: ModRing = ModRing::default();
    let Nm: ModRing = (N as i32).into();
    for i in 0..N {
        for v in a[i].iter() {
            let hm: ModRing = (hits[v] as i32).into();
            let num = Nm - hm;
            let den = Nm * Nm * ModRing::from(a[i].len() as i32);
            ans = ans + num / den;
        }
    }

    ans = ModRing::from(1) - ans;
    writeln!(&mut stdout, "{}", ans).unwrap();
}