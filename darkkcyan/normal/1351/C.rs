#![allow(unused_imports)] #![allow(dead_code)] #![allow(unused_macros)]
use std::{
    io::{stdin, stdout, BufReader, BufRead, BufWriter, Write},
    collections::*
};

macro_rules! my_enum {
    ($name: ident : $defaultValue: ident, $($rests: ident),*) => {
        #[derive(Clone)]
        enum $name { $defaultValue, $($rests),* }
        impl Default for $name { fn default() -> Self { Self::$defaultValue } }
        use $name::*;
    }
}

fn main() {
// PREPARATION CODES /////////////////////////////////////////////////////////////////  {{{
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
// MAIN PROGRAM START HERES ////////////////////////////////////////////////////////    }}}

    let mut dir: HashMap<char, (i32, i32)> = HashMap::new();
    dir.insert('N', (0, -1));
    dir.insert('S', (0, 1));
    dir.insert('W', (-1, 0));
    dir.insert('E', (1, 0));

    let mut compl: HashMap<char, char> = HashMap::new();
    for (u, v) in &[('N', 'S'), ('W', 'E')] {
        compl.insert(*u, *v);
        compl.insert(*v, *u);
    }

    for _testcase in 0..read!(usize) {
        let path = read();
        let mut visited: HashSet<(i32, i32, char)> = HashSet::new();

        let (mut x, mut y) = (0, 0);
        let mut ans = 0;
        for ch in path.as_bytes() {
            let ch = *ch as char;
            let (dx, dy) = dir.get(&ch).unwrap();
            let (nx, ny) = (x + dx, y + dy);

            if !visited.contains(&(x, y, ch)) {
                ans += 5;
                visited.insert((x, y, ch));
                visited.insert((nx, ny, *compl.get(&ch).unwrap()));
            } else {
                ans += 1;
            }
            x = nx;
            y = ny;
        }
        println!("{}", ans);
    }

}

// vim: foldmethod=marker