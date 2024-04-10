fn read_i32()->i32{
	let mut s = String::new();
	std::io::stdin().read_line(&mut s).unwrap();
	s.trim().parse().unwrap()
}

fn solve(){
	let x = read_i32();
	let mut far: i32 = 0;
	for jumps in 1..{
		far+=jumps;
		if x <= far && x != far-1 {
			println!("{}",jumps);
			return;
		}
	}
}

fn main(){	
	let t: i32 = read_i32();
	for _ in 0..t{
		solve();
	}	
}