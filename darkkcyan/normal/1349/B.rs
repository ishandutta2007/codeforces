#![allow(unused_imports)] #![allow(dead_code)] #![allow(unused_macros)]
use std::{
    cmp::{min, max},
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
    inp: &mut impl StringIterParser,
    out: &mut impl Write
) {

    for _testcase in 0..inp.np::<usize>() {
        let n = inp.np::<usize>();
        let k = inp.np::<i32>();
        let a = (0..n).map(|_| inp.np::<i32>()).collect::<Vec<_>>();

        let mut ans = n == 1 && a[0] == k;
        let mut has_k = false;

        let mut pref_sum = vec![0; n + 1];
        for (idx, x) in a.iter().enumerate() {
            if *x == k {
                has_k = true;
            }
            let val = if *x >= k { 1 } else {-1};
            pref_sum[idx + 1] = pref_sum[idx] + val;
        }

        if has_k {
            let mut cur_min_sum = 0;
            for (idx, s) in pref_sum.iter().enumerate().skip(2) {
                if *s > cur_min_sum {
                    ans = true;
                    break;
                }
                cur_min_sum = std::cmp::min(cur_min_sum, pref_sum[idx - 1]);
            }
        }
        writeln!(out, "{}", if ans { "YES" } else { "NO" }).ok();
    }
}

// vim: foldmethod=marker