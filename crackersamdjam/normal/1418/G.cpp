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
using ll = __int128;
const int MM = 5e5+5;
// const ll base = 500009, mod = 1e15+37;

mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());

int n, a[MM], cnt[MM], last = 0;
ll f[MM], val[MM], ans;
map<ll, ll> mp;
vector<int> in[MM];

int main(){
	scan(n);
	for(int i = 1; i <= n; i++){
		f[i] = g();
	}
	mp[0] = 1;
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		in[a[i]].emplace_back(i);
		cnt[a[i]]++;
		val[i] = val[i-1] + f[a[i]];
		if(cnt[a[i]] == 3){
			cnt[a[i]] = 0;
			val[i] -= 3*f[a[i]];

			int sz = size(in[a[i]]);
			int r = sz > 3 ? in[a[i]][sz-1-3] : -1;
			while(last < r){
				mp[val[last]]--;
				last++;
			}
			//erase all those from before
		}

		// print(i, val[i], mp[val[i]]);
		ans += mp[val[i]]++;
	}
	print(ans);
}