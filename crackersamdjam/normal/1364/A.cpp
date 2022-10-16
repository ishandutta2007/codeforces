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
const int MM = 1e5+5;

int t, n, x, a[MM];


int main(){
	scan(t);
	while(t--){
		long long s = 0;
		scan(n, x);
		for(int i = 0; i < n; i++){
			scan(a[i]);
			s += a[i];
		}
		if(s % x){
			print(n);
			continue;
		}
		int l = 0, r = n-1;
		while(l < n and a[l] % x == 0)
			l++;
		while(r >= 0 and a[r] % x == 0)
			r--;
		//need to move one of them...
		int ans = max(n-l-1, r);
		// if(ans == 0)
			// ans = -1;
		print(ans);
	}
	
	
	
}