fn read_ints() -> Vec<i32> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

fn main() {
    let _n = read_ints()[0];
    let mut a = read_ints();
    a.sort();
    a.dedup();
    println!("{}", a.len() - a.contains(&0) as usize);
}