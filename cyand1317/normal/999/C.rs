fn read_ints() -> Vec<usize> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

fn read_line() -> String {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    String::from(ln.trim_right())
}

const ALPHABET: usize = 26;

fn main() {
    let (n, mut k);
    if let [_n, _k] = read_ints()[..] { n = _n; k = _k; } else { panic!("> <"); }
    let s = read_line();
    assert_eq!(n, s.len());
    assert!(k <= n);

    let mut p: Vec<Vec<usize>> = vec![vec![]; ALPHABET];
    for (id, ch) in s.chars().enumerate() {
        p[ch as usize - 'a' as usize].push(id);
    }

    let mut rm: Vec<bool> = vec![false; n];
    for i in 0..ALPHABET {
        let cnt = std::cmp::min(k, p[i].len());
        k -= cnt;
        for &j in p[i].iter().take(cnt) { rm[j] = true; }
    }

    println!("{}", s.chars().enumerate().filter_map(|(id, ch)|
        if rm[id] { None } else { Some(ch) }
    ).collect::<String>());
}