fn read_string()->String{
	let mut s = String::new();
	std::io::stdin().read_line(&mut s).unwrap();
	s
}

fn main(){
	let t = read_string().trim().parse::<i32>().unwrap();
	for _ in 0..t{
		let _n = read_string().trim().parse::<i32>().unwrap();
		let a: Vec<i32> = read_string().split_whitespace().map(|x|x.parse::<i32>().unwrap()).collect();
		let b: Vec<i32> = a.iter().enumerate().map(|(i,e)| if i%2==0 { e.clone() } else { 1 }).collect();
		let c: Vec<i32> = a.iter().enumerate().map(|(i,e)| if i%2==1 { e.clone() } else { 1 }).collect();
		fn cost(a: &Vec<i32>,v: &Vec<i32>)->i64{
			a.iter().zip(v.iter()).map(|(x,y)| (x-y) as i64).sum::<i64>()
		}
		if cost(&a,&b)<cost(&a,&c){
			for v in b{
				print!("{} ",v);
			}
			println!();
		}else{
			for v in c{
				print!("{} ",v);
			}
			println!();
		}
	}
}