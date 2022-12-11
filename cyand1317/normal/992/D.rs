fn read_ints() -> Vec<i32> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

const LOG_SUM: i32 = 62;
const MAX_SUM: i64 = 1 << LOG_SUM;

fn main() {
    let (n, k);
    if let [_n, _k] = read_ints()[..] { n = _n; k = _k; } else { panic!("> <"); }
    let n = n as usize;
    let k = k as i64;

    let a = read_ints();
    assert_eq!(n, a.len());

    let mut b: Vec<usize> = vec![];
    let mut s = vec![0i64];
    for (id, &el) in a.iter().enumerate() {
        if el != 1 { b.push(id); }
        let mut x = *s.last().unwrap();
        s.push(x + el as i64);
    }
    b.push(n);

    let mut ans = 0;
    let mut p = 0usize;
    for i in 0..n as usize {
        if let Some(&q) = b.get(p) {
            if q <= i { p += 1; }
        }
        let mut last = i;
        let mut prod = 1;
        for j in 0..LOG_SUM as usize {
            if let Some(&q) = b.get(p + j) {
                let min_sum = s[last + 1] - s[i];
                let max_sum = s[q] - s[i];
                if prod > MAX_SUM / a[last] as i64 {
                    break;
                }
                prod *= a[last] as i64;
                if prod % k == 0 && min_sum * k <= prod && max_sum * k >= prod {
                    ans += 1;
                }
                last = q;
            } else {
                break;
            }
        }
    }
    println!("{}", ans);
}