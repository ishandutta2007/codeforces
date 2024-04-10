#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

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
const int MM = 5e5+5;
const ll mod = 1e9+7;

int t, n;
int cnt[69];
ll a[MM];

int main(){
	scan(t);
	while(t--){
		memset(cnt, 0, sizeof cnt);
		ll ans = 0;
		scan(n);
		for(int i = 0; i < n; i++){
			scan(a[i]);
			for(int j = 0; j < 63; j++){
				if(a[i]&(1LL<<j))
					cnt[j]++;
			}
		}

		for(int i = 0; i < n; i++){
			ll ls = 0, rs = 0;
			for(int j = 0; j < 63; j++){
				ll v = (1LL<<j)%mod;
				ll on = cnt[j];
				if(a[i]&(1LL<<j)){
					ls = (ls+on*v)%mod;
					rs = (rs+n*v)%mod;
				}
				else{
					rs = (rs+on*v)%mod;
				}
			}
			ans = (ans + ls*rs)%mod;
			// pr(i, ls, rs, ls*rs%mod);
		}

		print(ans);
	}
}