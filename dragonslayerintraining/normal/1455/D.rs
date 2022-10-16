fn read_str()->String{
	let mut s = String::new();
	std::io::stdin().read_line(&mut s).unwrap();
	s
}

fn is_sorted(a:&Vec::<i32>)->bool{
	for i in 0..a.len()-1{
		if a[i]>a[i+1]{
			return false;
		}
	}
	return true;
}

fn solve(){
	let vs :Vec<i32> = read_str().split_whitespace().map(|x| x.parse::<i32>()).collect::<Result<Vec<i32>,_>>().unwrap();
	let _n = vs[0];
	let mut x = vs[1];
	let mut arr = read_str().split_whitespace().map(|x| x.parse::<i32>()).collect::<Result<Vec<i32>,_>>().unwrap();
	let mut cnt = 0;
	for i in 0..arr.len(){
		if is_sorted(&arr){
			println!("{}",cnt);
			return;
		}
		if arr[i]>x{
			let tmp = arr[i];
			arr[i]=x;
			x=tmp;
			cnt+=1;
		}
	}
	if is_sorted(&arr){
		println!("{}",cnt);
		return;
	}
	println!("-1");
}

fn main(){
	let t = read_str().trim().parse().unwrap();
	for _ in 0..t{
		solve();
	}
}