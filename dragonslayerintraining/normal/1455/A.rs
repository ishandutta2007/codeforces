fn main(){
	let mut s = String::new();
	std::io::stdin().read_line(&mut s).expect("failed to read from stdin");
	let t: i32 = s.trim().parse().expect("invalid input");
	for _ in 0..t{
		let mut s = String::new();
		std::io::stdin().read_line(&mut s).expect("failed to read from stdin");
		println!("{}",s.trim().len());
	}
}