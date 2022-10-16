#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 2e5+5;
const ll mod = 1e9+7;
using pii = pair<int, int>;

struct stt{
	int dis = 1e9; ll dp;
	bool operator<(const stt &o) const{
		return dis < o.dis;
	}
};
stt t[MM*4];

#define lc rt<<1
#define rc rt<<1|1
#define nm ((nl+nr)/2)
#define npm int nl = 0, int nr = MM, int rt = 1
#define lpm nl, nm, lc
#define rpm nm+1, nr, rc

stt merge(stt a, stt b){
	if(a.dis != b.dis)
		return min(a, b);
	a.dp += b.dp;
	a.dp %= mod;
	return a;
}

void pull(int rt){
	t[rt] = merge(t[lc], t[rc]);
}

void update(int i, stt x, npm){
	if(nl == nr){
		t[rt] = merge(t[rt], x);
		// will overwrite older one (subset with current doll removed) because that one needs to travel further?
		return;
	}
	i <= nm ? update(i, x, lpm) : update(i, x, rpm);
	pull(rt);
}

stt query(int l, int r, npm){
	if(r < nl or nr < l)
		return {0, 0};
	if(l <= nl and nr <= r)
		return t[rt];
	return merge(query(l, r, lpm), query(l, r, rpm));
}

struct opst{
	int op, x, i;
	bool operator<(const opst &o){
		if(x != o.x)
			return x < o.x;
		return op > o.op;
		//update, then qu
	}
};

vector<opst> v;
int n;
stt dp[MM];
// {extra dis, # of ways}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	for(int i = 1,l,r; i <= n; i++){
		cin>>r>>l;
		v.push_back({0, l, i});
		v.push_back({1, r, i});
	}
	
	int in = 0;
	ll best = LLONG_MAX, ans = 0;

	update(0, {-1, 1});

	sort(all(v));
	for(auto [op, x, i]: v){
		if(!op){
			in++;
			dp[i] = query(0, x);
			dp[i].dis += x;
		}
		else{
			if(in < n)
				update(x, {dp[i].dis - x, dp[i].dp});
			else{
				if(dp[i].dis < best){
					best = dp[i].dis;
					ans = dp[i].dp;
				}
				else if(dp[i].dis == best){
					ans += dp[i].dp;
					ans %= mod;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
/*
I'm supposed to need coordinate compression but this passes for some reason???

*/