fn read_ints() -> Vec<usize> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

use std::collections::VecDeque;

fn bfs(e: &Vec<Vec<usize>>, s: usize) -> Vec<bool> {
    let n = e.len();
    let mut vis = vec![false; n];
    let mut q: VecDeque<usize> = VecDeque::new();

    vis[s] = true;
    q.push_back(s);

    while !q.is_empty() {
        let u = q.pop_front().unwrap();
        for &v in e[u].iter() {
            if !vis[v] {
                vis[v] = true;
                q.push_back(v);
            }
        }
    }

    vis
}

fn main() {
    let (n, m, s);
    if let [_n, _m, _s] = read_ints()[..] { n = _n; m = _m; s = _s - 1; } else { panic!("> <"); }
    assert!(s < n);

    let mut e: Vec<Vec<usize>> = vec![vec![]; n];
    let mut indeg = vec![0; n];
    for _ in 0..m {
        if let [u, v] = read_ints()[..] {
            e[u - 1].push(v - 1); indeg[v - 1] += 1;
        } else { panic!("T^T"); }
    }

    let vis = bfs(&e, s);
    let unvis: Vec<usize> = (0..n).filter(|&x| !vis[x]).collect();
    let mut candid = vec![true; n];

    let mut after;
    for &u in unvis.iter() {
        if candid[u] {
            e[s].push(u);
            after = bfs(&e, s);
            e[s].pop();
            for &v in unvis.iter() {
                if u != v && after[v] {
                    candid[v] = false;
                }
            }
        }
    }

    let mut ans = 0;
    for &u in unvis.iter() {
        if candid[u] {
            ans += 1;
        }
    }

    println!("{}", ans);
}