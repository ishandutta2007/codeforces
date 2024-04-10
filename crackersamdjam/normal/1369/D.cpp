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
typedef long long ll;
const ll mod = 1e9+7;
const int MM = 2e6+5;

ll dp[MM][3], val[MM];
int t, n;

int main(){
	dp[1][0] = 1;
	for(int i = 2; i < MM; i++){
		dp[i][2] = dp[i-1][1];
		dp[i][1] = dp[i-1][0];
		dp[i][0] = (dp[i-1][1]*2 + dp[i-1][0])%mod;
		val[i] = (dp[i][2]*4 + val[i-3])%mod;
//		print(val[i], dp[i][0], dp[i][1], dp[i][2]);
	}
	scan(t);
	while(t--){
		scan(n);
		print(val[n]);
	}
}