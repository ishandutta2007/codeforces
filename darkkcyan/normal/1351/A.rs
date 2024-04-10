#![allow(unused_imports)] #![allow(dead_code)] #![allow(unused_macros)]
use std::{
    io::{stdin, stdout, BufReader, BufRead, BufWriter, Write},
    collections
};

macro_rules! my_enum { // {{{
    ($name: ident : $defaultValue: ident, $($rests: ident),*) => {
        #[derive(Clone)]
        enum $name { $defaultValue, $($rests),* }
        impl Default for $name { fn default() -> Self { Self::$defaultValue } }
        use $name::*;
    }
} // }}}

fn main() {
// PREPARATION CODES /////////////////////////////////////////////////////////////////    {{{
    #[allow(unused_mut)] #[allow(unused_variables)]
    let mut read = {
        let mut read_buf = Vec::<String>::new();
        let mut inp = BufReader::new(stdin());

        move || -> String {
            while read_buf.is_empty() {
                let mut line = String::new();
                inp.read_line(&mut line).ok().expect("Error line reading");
                read_buf = line.split_ascii_whitespace().rev().map(str::to_string).collect();
            }
            read_buf.pop().unwrap()
        }
    };
    let _out = &mut BufWriter::new(stdout());
    macro_rules! read {
        () => { read().parse().unwrap(); };
        ($type: ident) => { read().parse::<$type>().unwrap(); }
    };
    macro_rules! println { ($($things: expr), *) => { writeln!(_out, $($things),*).ok(); } };
    macro_rules! print { ($($things: expr), +) => { write!(_out, $($things),*).ok(); } };
// MAIN PROGRAM START HERES ////////////////////////////////////////////////////////       }}}

    for _testcase in 0..read!(usize) {
        println!("{}", read!(i32) + read!(i32));
    }
}

// vim: foldmethod=marker