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

string x, y;
set<string> vis, ok;
int n, m;
queue<string> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	ll xx, yy;
	cin>>xx>>yy;
	x = bitset<64>(xx).to_string();
	y = bitset<64>(yy).to_string();
	while(x[0] == '0')
		x = x.substr(1);
	while(y[0] == '0')
		y = y.substr(1);
	// pr(x, y);

	n = size(x), m = size(y);
	for(int i = 0; i < m; i++){
		for(int j = 1; i+j <= m; j++){
			string s = y.substr(i, j);
			while(size(s) and s[0] == '0')
				s = s.substr(1);
			// pr(s);
			ok.insert(s);
			reverse(all(s));
			ok.insert(s);
		}
	}
	// pr("_________");
	vis.insert(x);
	q.emplace(x);
	while(size(q)){
		auto cur = q.front(); q.pop();
		if(cur == y){
			cout<<"YES\n";
			return 0;
		}
		auto nx = cur+"0";
		while(nx.back() == '0')
			nx.pop_back();
		reverse(all(nx));
		if(ok.count(nx) and !vis.count(nx)){
			// pr(cur, nx);
			vis.insert(nx);
			q.emplace(nx);
		}
		nx = cur+"1";
		while(nx.back() == '0')
			nx.pop_back();
		reverse(all(nx));
		if(ok.count(nx) and !vis.count(nx)){
			// pr(cur, nx);
			vis.insert(nx);
			q.emplace(nx);
		}
	}
	cout<<"NO\n";
}