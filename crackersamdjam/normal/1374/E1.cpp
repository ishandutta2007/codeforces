#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+5;

int n, k;
deque<int> a, b, ab;

int main(){
	scan(n, k);
	for(int i = 0,t,aa,bb; i < n; i++){
		scan(t, aa, bb);
		if(aa and bb)
			ab.emplace_back(t);
		else if(aa)
			a.emplace_back(t);
		else if(bb)
			b.emplace_back(t);
	}
	sort(all(ab));
	sort(all(a));
	sort(all(b));
	while(a.size() > k)
		a.pop_back();
	while(b.size() > k)
		b.pop_back();

	int ans = 0;
	for(int i: ab){
		if(a.size() < k or b.size() < k or i < a.back()+b.back()){
			ans += i;
			a.push_front(0);
			b.push_front(0);
			if(a.size() > k)
				a.pop_back();
			if(b.size() > k)
				b.pop_back();
		}
	}
	for(int i: a)
		ans += i;
	for(int i: b)
		ans += i;

	if(a.size() < k or b.size() < k)
		print(-1);
	else
		print(ans);
}