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
using ll = long long;
const int MM = 105;

int t, n, m, a[MM][MM];


int main(){
	scan(t);
	while(t--){
		scan(n, m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scan(a[i][j]);
			}
		}
		ll ans = 0;
		for(int i = 0; i < n/2; i++){
			for(int j = 0; j < m/2; j++){
				vector<ll> v = {a[i][j], a[n-1-i][j], a[i][m-1-j], a[n-1-i][m-1-j]};
				sort(all(v));
				ans += v[3]-v[1] + v[2]-v[1] + v[1]-v[0];
			}
			if(m%2){
				int j = m/2;
				vector<ll> v = {a[i][j], a[n-1-i][j]};
				sort(all(v));
				ans += v[1]-v[0];
			}
		}
		if(n%2){
			int i = n/2;
			for(int j = 0; j < m/2; j++){
				vector<ll> v = {a[i][j], a[i][m-1-j]};
				sort(all(v));
				ans += v[1]-v[0];
			}
		}
		print(ans);
	}
}