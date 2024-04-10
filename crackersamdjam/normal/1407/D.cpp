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
const int MM = 3e5+5;

int n, a[MM], dp[MM];
stack<int> hi, lo;
//first higher, lower

int main(){
	scan(n);
	for(int i = 1; i <= n; i++)
		scan(a[i]);
	hi.emplace(n);
	lo.emplace(n);
	for(int i = n-1; i; i--){
		dp[i] = 1e9;
		while(size(hi) and a[hi.top()] < a[i]){
			dp[i] = min(dp[i], dp[hi.top()]+1);
			hi.pop();
		}
		if(size(hi))
			dp[i] = min(dp[i], dp[hi.top()]+1);
		while(size(hi) and a[i] == a[hi.top()])
			hi.pop();
		hi.push(i);

		while(size(lo) and a[lo.top()] > a[i]){
			dp[i] = min(dp[i], dp[lo.top()]+1);
			lo.pop();
		}
		if(size(lo))
			dp[i] = min(dp[i], dp[lo.top()]+1);
		while(size(lo) and a[i] == a[lo.top()])
			lo.pop();
		lo.push(i);
	}
	print(dp[1]);
}