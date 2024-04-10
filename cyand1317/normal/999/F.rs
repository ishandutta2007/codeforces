fn read_ints() -> Vec<i32> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

const MAXC: usize = 100001;

fn main() {
    let (n, k);
    if let [_n, _k] = read_ints()[..] { n = _n as usize; k = _k as usize; } else { panic!("QuQ"); }
    let c = read_ints();
    let f = read_ints();
    let mut h = vec![0]; h.append(&mut read_ints());
    assert_eq!(k * n, c.len());
    assert_eq!(n, f.len());
    assert_eq!(k + 1, h.len());

    let mut cards = vec![0; MAXC];
    let mut flwrs = vec![0; MAXC];
    for &el in c.iter() { cards[el as usize] += 1; }
    for &el in f.iter() { flwrs[el as usize] += 1; }

    let mut ans = 0i32;
    for i in 0..MAXC {
        let c = cards[i];
        let f = flwrs[i];
        let mut g = vec![std::i32::MIN; c + 1];
        g[0] = 0;
        for _ in 0..f {
            for j in (0..=c).rev() {
                for t in 0..=std::cmp::min(j as usize, k) {
                    g[j as usize] = std::cmp::max(
                        g[j as usize],
                        g[j as usize - t] + h[t as usize]
                    );
                }
            }
        }
        ans += g.iter().max().unwrap();
    }

    println!("{}", ans);
}