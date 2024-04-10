fn read_ints() -> Vec<i64> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

const MODULUS: i64 = 1000000007;
const NEG_INV2: i64 = (MODULUS - 1) / 2;

fn qpow(mut base: i64, mut exp: i64) -> i64 {
    let mut ans = 1i64;
    while exp > 0 {
        if exp % 2 == 1 { ans = (ans * base) % MODULUS; }
        base = (base * base) % MODULUS;
        exp >>= 1;
    }
    ans
}

fn main() {
    let (x, k);
    if let [_x, _k] = read_ints()[..] { x = _x; k = _k; } else { panic!("> <"); }

    if x == 0 {
        println!(0);
    } else {
        println!("{}", ((x % MODULUS + NEG_INV2) * qpow(2, k + 1) + 1) % MODULUS);
    }
}