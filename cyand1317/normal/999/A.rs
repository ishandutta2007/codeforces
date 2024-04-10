fn read_ints() -> Vec<i32> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

fn main() {
    let (n, k): (usize, i32);
    if let [_n, _k] = read_ints()[..] { n = _n as usize; k = _k; } else { panic!("> <"); }
    let a = read_ints();
    assert_eq!(n, a.len());

    let mut ans = 0;
    for &el in a.iter() {
        if el <= k { ans += 1; } else { break; }
    }
    for &el in a.iter().rev() {
        if el <= k { ans += 1; } else { break; }
    }

    if ans == n * 2 { ans = n; }
    println!("{}", ans);
}