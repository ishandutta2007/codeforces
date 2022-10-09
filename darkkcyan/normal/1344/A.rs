#[allow(unused_imports)]
use std::{
    io::{stdin, stdout, BufReader, BufRead, BufWriter, Write},
    collections
};

fn main() {
// PREPARATION CODES ///////////////////////////////////////////////////////////////// {{{ 
    #[allow(unused)]
    let mut read = {
        let mut read_buf = Vec::<String>::new();
        let mut inp = BufReader::new(stdin());

        move || -> String {
            while read_buf.is_empty() {
                let mut line = String::new();
                inp.read_line(&mut line);
                read_buf = line.split_ascii_whitespace().rev().map(str::to_string).collect();
            }
            read_buf.pop().unwrap()
        }
    };
    let _out = &mut BufWriter::new(stdout());
    #[allow(unused_macros)]
    macro_rules! read {
        () => { read().parse().unwrap(); };
        ($type: ident) => { read().parse::<$type>().unwrap(); }
    };
    #[allow(unused_macros)]
    macro_rules! println { ($($things: expr), *) => { writeln!(_out, $($things),*).ok(); } };
    #[allow(unused_macros)]
    macro_rules! print { ($($things: expr), +) => { write!(_out, $($things),*).ok(); } };
// MAIN PROGRAM START HERES //////////////////////////////////////////////////////// }}}

    let ntest = read!(usize);
    for _testcase in 0..ntest {
        let n = read!(i32);
        let a: Vec<_> = (0..n)
            .map(|i| read!(i32) + i as i32)
            .map(|i| ((i % n) + n) % n)
            .collect();

        let mut has = vec![false; n as usize];
        let mut ans = true;
        for i in a {
            let i = i as usize;
            if has[i] {
                ans = false;
                break;
            }
            has[i] = true;
        }
        println!("{}", if ans { "YES" } else { "NO" });
    }

}

// vim: foldmethod=marker