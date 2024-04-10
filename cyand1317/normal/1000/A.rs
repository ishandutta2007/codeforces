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

fn id(s: &str) -> usize {
    match s {
        "XXXS" => 0,
         "XXS" => 1,
          "XS" => 2,
           "S" => 3,
           "M" => 4,
           "L" => 5,
          "XL" => 6,
         "XXL" => 7,
        "XXXL" => 8,
        _ => 0
    }
}

fn main() {
    let n: i32;
    n = read_ints()[0];

    let mut a = [0i32; 9];
    let mut b = [0i32; 9];

    for _ in 0..n {
        a[id(&read_line())] += 1;
    }

    for _ in 0..n {
        b[id(&read_line())] += 1;
    }

    let ans =
        (a[0] - b[0]).abs() +
        (a[1] - b[1]).abs() +
        (a[2] - b[2]).abs() +
        std::cmp::max(
            (a[3] - b[3]).abs(),
            std::cmp::max(
                (a[4] - b[4]).abs(),
                (a[5] - b[5]).abs()
            )
        );

    println!("{}", ans);
}