
#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define all(v) v.begin(), v.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

vector<pi> a, b;
vi G[512];
bool vis[512];
int d[512];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		int t;
		cin >> t;
		if(t == 1)
			b.EB(t, i);
		else
			a.EB(t, i);
	}
	
	for(int i=0;i<(int)a.size()-1;i++) {
		G[a[i].S].PB(a[i+1].S);
		a[i].F--;
		a[i+1].F--;
	}
	if(a.size() == 0) {
		if(b.size() <= 2) {
			cout << "YES " << b.size() - 1 << endl;
			if(b.size() == 1) {
				cout << 0 << endl; 
			} else {
				cout << 1 << endl;
				cout << 1 << "@" << 2 << endl; 
			}
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}
	int di = a.size();
	if(b.size()) {
		int x = b.back().S;
		b.pop_back();
		G[x].PB(a[0].S);
		a[0].F--;
		di++;
	}
	if(b.size()) {
		int x = b.back().S;
		b.pop_back();
		G[x].PB(a.back().S);
		a.back().F--;
		di++;
	}
	for(int i=0;i<a.size();i++) {
		while(a[i].F && b.size()) {
			int x = b.back().S;
			b.pop_back();
			G[x].PB(a[i].S);
			a[i].F--;
		}
	}
	if(b.size() > 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << " ";
	cout << di-1 << endl;
	cout << n -1 << endl; 
	for(int u=1;u<=n;u++) {
		for(int v:G[u]){
			cout << u << " " << v << endl;
		}
	}
}