fn read_ints() -> Vec<i32> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

fn main() {
    let (n, m): (usize, i32);
    if let [_n, _m] = read_ints()[..] { n = _n as usize; m = _m; } else { panic!("> <"); }
    let a = read_ints();
    assert_eq!(n, a.len());

    let mut b = vec![0; n + 2];
    b[0] = 0;
    for i in 0..n {
        b[i + 1] = a[i];
    }
    b[n + 1] = m;

    let mut s = vec![0; n + 2];
    for i in (0..n + 1).rev() {
        s[i] = s[i + 1];
        if i % 2 == 0 {
            s[i] += b[i + 1] - b[i];
        }
    }

    let mut ans = s[0];
    let mut accum = 0;  // Total time on before current program position
    for i in 0..n + 1 {
        if i % 2 == 1 {
            accum += b[i] - b[i - 1];
        }
        if b[i] < b[i + 1] - 1 {
            let cur = accum + (b[i + 1] - b[i] - 1) + (m - b[i + 1] - s[i + 1]);
            ans = std::cmp::max(ans, cur);
        }
    }

    println!("{}", ans);
}