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
const int MM = 1e5+5;

int t, n, cnt[MM];
ll a[MM];
vector<ll> v;

int main(){
	scan(t);
	while(t--){
		scan(n);
		for(int i = 1; i <= n; i++)
			scan(a[i]);
		
		for(int i = 0,u,v; i < n-1; i++){
			scan(u, v);
			cnt[u]++;
			cnt[v]++;
		}

		ll sum = 0;
		for(int i = 1; i <= n; i++){
			cnt[i]--;
			sum += a[i];
			while(cnt[i]--){
				v.emplace_back(a[i]);
			}
		}
		sort(all(v));
		reverse(all(v));
		printf("%lld ", sum);
		for(int i = 0; i < size(v); i++){
			sum += v[i];
			printf("%lld ", sum);
		}
		pc(10);

		v.clear();
		for(int i = 1; i <= n; i++)
			cnt[i] = 0;
	}
}