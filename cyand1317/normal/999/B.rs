fn read_ints() -> Vec<i32> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

fn read_line() -> String {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    String::from(ln.trim_right())
}

fn main() {
    let n = read_ints()[0] as usize;
    let mut s = read_line();
    assert_eq!(n, s.len());

    for i in 2..=n {
        if n % i == 0 {
            let t = s.split_off(i);
            s = s.chars().rev().collect();
            s.push_str(&t);
        }
    }
    println!("{}", s);
}