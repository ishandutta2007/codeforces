fn read_ints() -> Vec<i32> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

fn gcd(x: i32, y: i32) -> i32 {
    if y == 0 { x } else { gcd(y, x % y) }
}

fn main() {
    let (mut l, mut r, mut x, mut y) = (0, 0, 0, 0);
    if let [_l, _r, _x, _y] = read_ints()[..] { l = _l; r = _r; x = _x; y = _y; }

    if y % x != 0 {
        println!(0);
        return;
    }
    l = (l + x - 1) / x;
    r /= x;
    y /= x;

    let mut ans = 0i64;
    for i in 1..=(y as f64).sqrt() as i32 {
        if y % i == 0 && gcd(i, y / i) == 1 &&
            i >= l && i <= r &&
            y / i >= l && y / i <= r
        {
            ans += 2 - (i * i == y) as i64;
        }
    }
    println!("{}", ans);
}