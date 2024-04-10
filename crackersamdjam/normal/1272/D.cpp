#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+5;

int n, a[MM], pre[MM], suf[MM], ans;

int main(){
	scan(n);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		if(a[i] > a[i-1])
			pre[i] = pre[i-1]+1;
		else
			pre[i] = 1;
	}
	a[n+1] = 1e9+2;
	for(int i = n; i; i--){
		if(a[i] < a[i+1])
			suf[i] = suf[i+1]+1;
		else
			suf[i] = 1;
	}

	for(int i = 0; i <= n; i++){
		if(a[i] < a[i+2])
			ans = max(ans, pre[i]+suf[i+2]);
		ans = max(ans, pre[i]);
		ans = max(ans, suf[i]);
	}

	print(ans);
}