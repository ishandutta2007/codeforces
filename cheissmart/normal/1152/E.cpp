#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int b[100005], c[100005], e[100005];
vi G[100005];
vi p;

bool dfs(int u) {
	while(G[u].size()) {
		int i = G[u].back();
		G[u].pop_back();
		if(e[i] != -1) {
			int v = u ^ e[i]; 
			e[i] = -1;
			dfs(v);
		}
	}
	p.PB(u);
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi v;
	for(int i=0;i<n-1;i++) {
		cin >> b[i];
		v.PB(b[i]);
	}
	for(int i=0;i<n-1;i++) {
		cin >> c[i];
		if(b[i] > c[i]) {
			cout << -1 << endl;
			return 0;
		}
		v.PB(c[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	if(v.size() > n) {
		cout << -1 << endl;
		return 0;
	}
	for(int i=0;i<n-1;i++) {
		b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
		c[i] = lower_bound(v.begin(), v.end(), c[i]) - v.begin();
	}
	for(int i=0;i<n-1;i++) {
		e[i] = c[i] ^ b[i];
		G[b[i]].PB(i);
		G[c[i]].PB(i);
	}
	vi odd;
	for(int i=0;i<v.size();i++) {
		if(G[i].size() % 2)
			odd.PB(i);
	}
	if(odd.size() !=2 && odd.size() != 0) {
		cout << -1 << endl;
		return 0;
	}
	int s = 0;
	if(odd.size()) 
		s = odd[0];
	dfs(s);
	if(p.size() != n)  {
		cout << -1 << endl;
		return 0;
	}
	for(int i:p)
		cout << v[i] << " "; 
}