#![allow(unused_imports)] #![allow(dead_code)] #![allow(unused_macros)]
use std::{
    io::{stdin, stdout, BufRead, BufWriter, Write, StdoutLock},
    str::FromStr,
    collections::*,
    rc::Rc,
    cell::{Cell},
    ops::*
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

my_enum!(NodeState: Unvisited, Visiting, Visited);

#[derive(Default, Debug)]
struct Node {
    assignment: Rc<Cell<char>>,
    state: NodeState,
    adj: Rc<Vec<usize>>,
}

type Graph = Vec<Node>;

fn dfs(gr: &mut Graph, u: usize) -> bool {
    gr[u].state = Visiting;
    for v in gr[u].adj.clone().iter() {
        match gr[*v].state { 
            Unvisited => {
                gr[*v].assignment.set('E');
                if dfs(gr, *v) { return true; }
            },
            Visiting => return true,
            _ => continue
        }
    }
    gr[u].state = Visited;
    false
}

fn solve(
    #[allow(unused_variables)] inp: &mut impl StringIterParser,
    #[allow(unused_variables)] out: &mut impl Write
) {
    let (n, m) = (inp.np::<usize>(), inp.np::<usize>()); 
    let mut gr = (0..n).map(|_| Node::default()).collect::<Graph>();
    let mut rgr = (0..n).map(|u| Node { 
        assignment: gr[u].assignment.clone(),
        ..Default::default()
    }).collect::<Graph>();

    for _i in 0..m {
        let (u, v) = (inp.np::<usize>() - 1, inp.np::<usize>() - 1);
        gm(&mut gr[u].adj).push(v);
        gm(&mut rgr[v].adj).push(u);
    }

    let mut cnt_a = 0;
    for u in 0..n { 
        assert!(gr[u].state != Visiting); 
        if gr[u].state != Visited && rgr[u].state != Visited { 
            gr[u].assignment.set('A');
            cnt_a += 1;
        }
        if dfs(&mut gr, u) || dfs(&mut rgr, u) { 
            write!(out, "-1").ok(); 
            return ; 
        } 
    } 
    writeln!(out, "{}", cnt_a).ok();
    writeln!(out, "{}", (0..n).map(|u| gr[u].assignment.get()).collect::<String>()).ok();
}

// vim: foldmethod=marker