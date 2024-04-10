fn read_string()->String{
	let mut s = String::new();
	std::io::stdin().read_line(&mut s).unwrap();
	s
}

fn main(){
	let t = read_string().trim().parse::<i32>().unwrap();
	for _ in 0..t{
		let a: Vec<i32> = read_string().split_whitespace().map(|x|x.parse::<i32>().unwrap()).collect();
		let total: i32 = a.iter().sum();
		if total%9==0 && a.iter().all(|&x|x>=total/9){
			println!("YES");
		}else{
			println!("NO");
		}
	}
}