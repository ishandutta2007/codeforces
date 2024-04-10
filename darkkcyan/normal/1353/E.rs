#![allow(unused_imports)] #![allow(dead_code)] #![allow(unused_macros)]
use std::{
    cmp::{min, max},
    io::{stdin, stdout, BufRead, BufWriter, Write, StdoutLock},
    str::FromStr,
    rc::Rc,
    collections::*,
};

// PREPARATION CODES ///////////////////////////////////////////////////////////////// 
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
// ACTUAL SOLUTION STARTS HERE //////////////////////////////////////////////////////// 

fn solve(
    #[allow(unused_variables)] inp: &mut impl StringIterParser,
    #[allow(unused_variables)] out: &mut impl Write
) {

    for _testcase in 0..inp.np::<usize>() {
        let (n, k) = (inp.np::<usize>(), inp.np::<usize>());
        let s = inp.np::<String>();
        let s = s.as_bytes().iter().map(|&ch| ch - b'0').collect::<Vec<_>>();
        let mut pref_sum = vec![0; n + 1];
        for i in 0..n {
            pref_sum[i + 1] = pref_sum[i] + s[i] as usize;
        }

        let mut ans = pref_sum[n];
        for i in 0..k {
            let mut first = i;
            let mut last = ((n - 1 - i) / k * k + i) as i32;
            while s.get(first) == Some(&0) {
                first += k;
            }
            while last >= 0 && s[last as usize] == 0 {
                last -= k as i32;
            }
            if first as i32 > last {
                continue;
            }
            let mut cur_sum = 0i32;
            let mut max_sum = 0i32;
            let mut cur_ans = n as i32;
            for i in (first..=last as usize).step_by(k).map(|pos| if s[pos] == 0 {1i32} else {-1i32} ) {
                cur_sum += i;
                cur_ans = min(cur_ans, cur_sum - max_sum);
                max_sum = max(max_sum, cur_sum);
            }
            cur_ans += pref_sum[n] as i32;
            ans = min(ans, cur_ans as usize);
        }
        writeln!(out, "{}", ans).ok();
     }
}

// vim: foldmethod=marker