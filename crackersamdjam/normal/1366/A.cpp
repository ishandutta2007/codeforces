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

int main(){
	int t, a, b;
	scan(t);
	while(t--){
		scan(a, b);
		if(a < b)
			swap(a, b);
		int d = a-b;
		int sub = min({a/2, b, d});
		a -= sub*2, b -= sub;

		int ans = sub;
		int r = min(a/3, b/3);
		ans += r*2;

		a -= r*3, b -= r*3;
		if(a < b)
			swap(a, b);
		if(a >= 2 and b >= 1){
			ans++;
			a -= 2;
			b--;
		}
		if(a < b)
			swap(a, b);
		if(a >= 2 and b >= 1){
			ans++;
			a -= 2;
			b--;
		}
		// print(sub, r);
		print(ans);
	}	
	
}