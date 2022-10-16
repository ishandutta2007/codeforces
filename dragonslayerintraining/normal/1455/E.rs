use std::convert::TryInto;

fn read_str()->String{
	let mut s = String::new();
	std::io::stdin().read_line(&mut s).unwrap();
	s
}

fn search<F>(low: i32, high: i32, f: &F) -> i64 where F: Fn(i32) -> i64{
	let mut lo = low;
	let mut hi = high;
	let mut lo_cost = f(lo);
	let mut lo_slope = f(lo+1)-lo_cost;
	let mut hi_cost = f(hi);
	let mut hi_slope = hi_cost-f(hi-1);

	while lo<hi {
		if hi_slope<=0 {
			return hi_cost;
		}
		if lo_slope>=0 {
			return lo_cost;
		}
		if hi-lo==2 {
			return f((lo+hi)/2);
		}
		let mut lm = ((((hi as i64)*hi_slope-(lo as i64)*lo_slope)-(hi_cost-lo_cost))/(hi_slope-lo_slope)).try_into().unwrap();
		if lm==lo{
			lm+=1;
		}
		if lm+1==hi{
			lm-=1;
		}
		let hm = lm+1;

		assert!(lo<=lm);
		assert!(hm<=hi);

		let lm_cost = f(lm);
		let hm_cost = f(hm);
		let m_slope = hm_cost-lm_cost;
		if m_slope>0 {
			hi = hm;
			hi_cost = hm_cost;
			hi_slope = m_slope;
		}else{
			lo = lm;
			lo_cost = lm_cost;
			lo_slope = m_slope;
		}
	}
	f(lo)
}

struct PermutationIterator<T:Ord+Clone>{
	arr: Option<Vec<T>>
}

impl<T:Ord+Clone> Iterator for PermutationIterator<T> {
	type Item = Vec<T>;
	fn next(&mut self) -> Option<Self::Item> {
		if let Some(a) = &mut self.arr{
			let old = a.clone();
			let len = a.len();
			for i in (1..len).rev() {
				if a[i-1]<a[i] {
					a[i..len].reverse();
					for j in i..len{
						if a[j]>a[i-1]{
							a.swap(i-1,j);
							break;
						}
					}
					return Some(old);
				}
			}
			self.arr=None;
			return Some(old)
		}
		None
	}
}

fn dist(px:i32,py:i32,qx:i32,qy:i32)->i64{
	(px-qx).abs() as i64 +(py-qy).abs() as i64
}

fn score(ps:Vec<Vec<i32>>)->i64{
	let cost = search(0,1_000_000_000,&|s| {search(0,1_000_000_000,&|x| search(0,1_000_000_000,& |y| 
		dist(ps[0][0],ps[0][1],x,y)+dist(ps[1][0],ps[1][1],x,y+s)+dist(ps[2][0],ps[2][1],x+s,y)+dist(ps[3][0],ps[3][1],x+s,y+s)))});
	cost
}

fn solve(){
	let mut points:Vec<Vec<i32>> = (0..4).map(|_| read_str().split_whitespace().map(|s|s.parse::<i32>().unwrap()).collect::<Vec<i32>>()).collect();
	points.sort();
	let ans = PermutationIterator{arr:Some(points)}.map(score).fold(std::i64::MAX,std::cmp::min);
	println!("{}",ans);

}

fn main(){
	let t = read_str().trim().parse().unwrap();
	for _ in 0..t{
		solve();
	}
}