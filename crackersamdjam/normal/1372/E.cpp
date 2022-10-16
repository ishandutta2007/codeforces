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
const int MM = 105;

int n, m, dp[MM][MM], id[MM][MM], le[MM][MM], re[MM][MM];

int go(int l, int r){
	if(l > r) return 0;
	int &ret = dp[l][r];
	if(~ret) return ret;
	ret = 0;
	for(int i = l; i <= r; i++){ //split at i
		int sum = 0;
		for(int j = 0; j < n; j++){
			if(le[j][i] >= l and re[j][i] <= r)
				sum++;
		}
		ret = max(ret, sum*sum + go(l, i-1) + go(i+1, r));
	}
	// print(l, r, ret);
	return ret;
}

int main(){
	memset(dp, -1, sizeof dp);
	scan(n, m);
	for(int i = 0,k,l,r; i < n; i++){
		scan(k);
		while(k--){
			scan(l, r);
			l--, r--;
			for(int j = l; j <= r; j++){
				le[i][j] = l, re[i][j] = r;
			}
		}
	}
	print(go(0, m-1));
}