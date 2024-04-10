#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

// #define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 1e6+5;

int n;
ll r1, r2, r3, d, a[MM], b[MM], ans;
ll pre[MM], suf[MM];
//pre is "normal", suf is turn back

int main(){
	scan(n);
	scan(r1, r2, r3, d);
	if(n == 1){
		scan(a[1]);
		print(a[1]*r1+r3);
		return 0;
	}

	for(int i = 1; i <= n; i++){
		scan(a[i]);
		pre[i] = pre[i-1] + min(a[i]*r1 + min(2*r1 + 2*d, r3), r2+2*d+r1);
		if(i >= 2){
			pre[i] = min(pre[i], pre[i-2] + min(a[i]*r1 + r1*2, r2+r1) + min(a[i-1]*r1 + r1*2, r2+r1) + 2*d);
			//take last two together
		}
		// pr("pre", i, pre[i]);
	}
	ans = pre[n];
	suf[n] = min(a[n]*r1 + min(2*r1 + 2*d, r3), r2+2*d+r1);;

	// pr(n, ans, suf[n]);
	for(int i = n-1; i; i--){
		suf[i] = suf[i+1] + d + min(a[i]*r1 + min(2*r1, r3), r2+r1);
		ans = min(ans, pre[i-1]+suf[i]);
		// pr(i, pre[i-1], suf[i]);
	}
	print(ans + (n-1)*d);
	// pr(ans, (n-1)*d);
}