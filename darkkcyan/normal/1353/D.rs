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
    for _testcase in 0..inp.np::<usize>() {
        let n = inp.np::<usize>();
        let mut ans = vec![0; n];
        let mut ranges = vec![Vec::<(usize, usize)>::new(); n + 1];
        ranges[n].push((0, n - 1));
        let mut cur = 1;
        for i in (1..=n).rev() {
            let mut x = ranges[i].clone();
            x.sort_by_key(|p| p.0);
            for (l, r) in x {
                let mid = (l + r) / 2;
                ans[(l + r) / 2] = cur;
                cur += 1;
                ranges[mid - l].push((l, mid - 1));
                ranges[r - mid].push((mid + 1, r));
            }
        }
        for i in ans {
            write!(out, "{} ", i).ok();
        }
        writeln!(out).ok();
    }
}

// vim: foldmethod=marker