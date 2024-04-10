#[allow(unused_imports)]
use std::{
    io::{stdin, stdout, BufReader, BufRead, BufWriter, Write},
    collections::*
};

fn main() {
// PREPARATION CODES /////////////////////////////////////////////////////////////////   {{{
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
// MAIN PROGRAM START HERES ////////////////////////////////////////////////////////    }}}

    let (n, m) = (read!(usize), read!(usize));

    let board: Vec<_> = (0..n).map(|_| Vec::from(read().as_bytes())).collect();
    // let vis = vec![vec![false; m as usize]; n as usize]; 
    
    let has_empty_row = (0..n).any(|r| board[r].iter().all(|ch| *ch == b'.'));
    let has_empty_col = (0..m).any(|c| (0..n).all(|r| board[r][c] == b'.'));
    if has_empty_row != has_empty_col {
        println!("-1");
        return ;
    }

    for i in 0..n {
        let ok = board[i].iter()
            .skip_while(|&&ch| ch == b'.')
            .skip_while(|&&ch| ch == b'#')
            .all(|&ch| ch == b'.');
        if !ok {
            println!("-1");
            return ;
        }
    }

    for c in 0..m {
        let ok = (0..n)
            .skip_while(|&r| board[r][c] == b'.')
            .skip_while(|&r| board[r][c] == b'#')
            .all(|r| board[r][c] == b'.');
        if !ok {
            println!("-1");
            return ;
        }
    }

    let mut ans = 0;
    let mut vis = vec![vec![false; m]; n];
    for r in 0..n {
        for c in 0..m {
            if board[r][c] == b'.' || vis[r][c] {
                continue;
            }
            ans += 1;
            let mut qu = VecDeque::<(usize, usize)>::new();
            vis[r][c] = true;
            qu.push_back((r, c));
            while let Some((cr, cc)) = qu.pop_front() {
                for (dr, dc) in &[(-1, 0), (0, -1), (0, 1), (1, 0)] {
                    let (nr, nc) = (cr as i32 + dr, cc as i32 + dc);
                    if nr < 0 || nc < 0 || nr >= n as i32 || nc >= m as i32 {
                        continue
                    }
                    let nr = nr as usize;
                    let nc = nc as usize;
                    if board[nr][nc] == b'.' || vis[nr][nc] {
                        continue;
                    }
                    vis[nr][nc] = true;
                    qu.push_back((nr, nc));
                }
            }
        }
    }
    println!("{}", ans);

}

// vim: foldmethod=marker