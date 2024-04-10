fn read_ints() -> Vec<i32> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

fn main() {
    let (n, m): (usize, usize);
    if let [_n, _m] = read_ints()[..] { n = _n as usize; m = _m as usize; } else { panic!("> <"); }
    let mut a = read_ints();
    assert_eq!(n, a.len());
    assert!(n % m == 0);

    let mut pos: Vec<Vec<usize>> = vec![vec![]; m];
    for (id, &el) in a.iter().enumerate() {
        pos[el as usize % m].push(id);
    }

    let mut ans = 0u64;
    let mut coll: Vec<usize> = vec![];
    for _ in 0..2 {
        for i in 0..m {
            ans += coll.len() as u64;
            if pos[i].len() > n / m {
                for _ in 0..(pos[i].len() - n / m) {
                    coll.push(pos[i].pop().unwrap());
                }
            } else {
                for _ in 0..std::cmp::min(n / m - pos[i].len(), coll.len()) {
                    pos[i].push(coll.pop().unwrap());
                }
            }
        }
    }
    assert!(coll.is_empty());

    for (id, ref el) in pos.iter().enumerate() {
        for &p in el.iter() {
            let m = m as i32;
            a[p] += (id as i32 - a[p] % m + m) % m;
        }
    }

    println!("{}", ans);
    println!("{}", a.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(" "));
}