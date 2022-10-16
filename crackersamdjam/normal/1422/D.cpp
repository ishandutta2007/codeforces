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
using str = array<ll, 3>;
using pii = pair<ll, int>;
const int MM = 1e5+5;

int n, m;
ll x[MM], y[MM], dis[MM], ans;

set<str> sx, sy;
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
	scan(n, m);
	scan(x[0], y[0], x[1], y[1]);
	for(int i = 2; i <= m+1; i++){
		scan(x[i], y[i]);
		sx.insert({x[i], y[i], i});
		sy.insert({y[i], x[i], i});
	}

	//avoid edge cases later on
	sx.insert({x[0], y[0], 0});
	sy.insert({y[0], x[0], 0});

	memset(dis, 0x3f, sizeof dis);
	ans = dis[0];
	q.emplace(dis[0] = 0, 0);

	while(size(q)){
		ll d, i; tie(d, i) = q.top(); q.pop();
		if(d > dis[i])
			continue;
		ans = min(ans, d+abs(x[i]-x[1]) + abs(y[i]-y[1]));
		int a = x[i], b = y[i];
		// pr(i, a, b, d);
		
		auto it = sx.upper_bound({a, b, i});
		if(it != sx.end()){
			auto u = *it;
			ll dd = abs(u[0]-a);
			// pr("dd1", dd, u[2]);
			if(d+dd < dis[u[2]]){
				q.emplace(dis[u[2]] = d+dd, u[2]);
			}
		}
		if(--it != sx.begin()){
			auto u = *--it;
			ll dd = abs(u[0]-a);
			// pr("dd2", dd, u[2]);
			if(d+dd < dis[u[2]]){
				q.emplace(dis[u[2]] = d+dd, u[2]);
			}
		}

		swap(a, b);
		it = sy.upper_bound({a, b, i});
		if(it != sy.end()){
			auto u = *it;
			ll dd = abs(u[0]-a);
			// pr("dd3", dd, u[2]);
			if(d+dd < dis[u[2]]){
				q.emplace(dis[u[2]] = d+dd, u[2]);
			}
		}
		if(--it != sy.begin()){
			auto u = *--it;
			ll dd = abs(u[0]-a);
			// pr("dd4", dd, u[2]);
			if(d+dd < dis[u[2]]){
				q.emplace(dis[u[2]] = d+dd, u[2]);
			}
		}
	}
	print(ans);
}