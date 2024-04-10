#![allow(unused_imports)] #![allow(dead_code)] #![allow(unused_macros)]
use std::{
    io::{stdin, stdout, BufRead, BufWriter, Write, StdoutLock},
    str::FromStr,
    rc::Rc,
    collections::*,
};

// PREPARATION CODES ///////////////////////////////////////////////////////////////// {{{
macro_rules! my_enum {
    ($name: ident : $defaultValue: ident, $($rests: ident),*) => {
        #[derive(Clone, Copy, Debug, PartialEq)]
        enum $name { $defaultValue, $($rests),* }
        impl Default for $name { fn default() -> Self { Self::$defaultValue } }
        use $name::*;
    }
}

#[inline] fn gm<T>(thing: &mut Rc<T>) -> &mut T { Rc::get_mut(thing).unwrap() }

trait StringIterParser {
    fn next_parse<T: FromStr>(&mut self) -> Option<T>;
    fn np<T: FromStr>(&mut self) -> T;  // short version for CP
}

impl<I: Iterator<Item=String>> StringIterParser for I {
    #[inline] fn next_parse<T: FromStr>(&mut self) -> Option<T> {
        self.next().unwrap().parse::<T>().ok()
    }
    #[inline] fn np<T: FromStr>(&mut self) -> T { self.next_parse::<T>().unwrap() }
}

fn main() {
    let (mut _stdin, mut _stdout) = (stdin(), stdout());
    let mut inp_tokens = _stdin.lock().lines()     // note: if the problem need to read the whole
                                                   // line (e.g. a string lines with spaces)
                                                   // then maybe just need to stop on this line
                                                   // and parse the number more manually.
        .map(|rs| String::from(rs.ok().expect("Error line reading")))
        .flat_map(|s| s.split_ascii_whitespace().map(str::to_string).collect::<Vec<_>>());
    let out = &mut BufWriter::new(_stdout.lock());
    solve(&mut inp_tokens, out);
}
// ACTUAL SOLUTION STARTS HERE //////////////////////////////////////////////////////// }}}

fn solve(
    #[allow(unused_variables)] inp: &mut impl StringIterParser,
    #[allow(unused_variables)] out: &mut impl Write
) {

    const MAXN: usize= 202020;
    let mut prime_div = [0; MAXN];
    for i in 2..MAXN {
        if prime_div[i] != 0 {
            continue;
        }
        for f in (i..MAXN).step_by(i) {
            prime_div[f] = i;
        }
    }

    let mut min_exp = [(MAXN, MAXN); MAXN];
    let mut cnt_having = [0; MAXN];

    let n = inp.np::<usize>();
    for _i in 0..n {
        let mut a = inp.np::<usize>();
        while a > 1 {
            let p = prime_div[a];
            let mut cnt = 0;
            while a % p == 0 {
                cnt += 1;
                a /= p;
            }
            cnt_having[p] += 1;

            if cnt < min_exp[p].0 {
                std::mem::swap(&mut cnt, &mut min_exp[p].0);
            }

            if cnt < min_exp[p].1 {
                min_exp[p].1 = cnt;
            }
        }
    }

    let mut ans = 1i64;
    for i in 1..MAXN {
        let exp = if cnt_having[i] == n {
            min_exp[i].1
        } else if cnt_having[i] == n - 1{
            min_exp[i].0
        } else { 0 };
        for _x in 0..exp { 
            ans = ans * (i as i64);
        }
    }
    write!(out, "{}", ans).ok();
}

// vim: foldmethod=marker