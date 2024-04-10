#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
int const MM = 4e5+5, LOG = 20;

int n, m, h[MM], q, sp[LOG][MM];

int query(int l, int r){
	int k = __lg(r-l+1);
	return max(sp[k][l], sp[k][r-(1<<k)+1]);
}

bool run(){
	int a, b, c, d, k;
	cin>>b>>a>>d>>c>>k;
	if(abs(a-c)%k or abs(b-d)%k){
		// pr("NO");
		return 0;
	}
	if(a == c) return 1;

	int mx = query(min(a, c), max(a, c));
	ll add = (n-b)/k;
	ll go = b+add*k;
	// pr(go > mx ? "YES" : "NO");
	return go > mx;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		cin>>h[i];
		sp[0][i] = h[i];
	}
	for(int i = 1; i < LOG; i++){
		for(int j = 0; j+(1<<i) <= m; j++){
			sp[i][j] = max(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
		}
	}
	cin>>q;
	while(q--){
		cout<<(run()?"YES\n":"NO\n");
	}
}