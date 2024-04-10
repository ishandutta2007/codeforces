#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, m, q;
string s[MAXN];
map<string, int> mp;
int par[MAXN], col[MAXN], sz[MAXN];

int getPar(int v){return par[v]==v?v:getPar(par[v]);}
int getCol(int v){return par[v]==v?col[v]:getCol(par[v])^col[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)	cin >> s[i], mp[s[i]] = i;
	iota(par, par + n, 0);
	fill(sz, sz + n, 1);
	while (m--){
		int a, b, type;
		{
			string s, t; cin >> type >> s >> t;	type--;
			a = mp[s], b = mp[t];
		}
		
		int pa = getPar(a), pb = getPar(b);
		if (sz[pa] > sz[pb]) 
			swap(a, b), swap(pa, pb);

		bool done = 0;
		if (type){
			if (pa ^ pb){
				sz[pb] += sz[pa];
				par[pa] = pb;
				if (getCol(a) == getCol(b))
					col[pa] ^= 1;
				done = 1;
			}
			else 
				if (getCol(a) ^ getCol(b)) done = 1;
		}
		else{
			if (pa ^ pb){
				sz[pb] += sz[pa];
				par[pa] = par[pb];
				if (getCol(a) ^ getCol(b))
					col[pa] ^= 1;
				done = 1;
			}
			else
				if (getCol(a) == getCol(b)) done = 1;
		}
		if (done)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	while (q--){
		int a, b;
		{
			string s, t;	cin >> s >> t;
			a = mp[s], b = mp[t];
		}
		if (getPar(a) == getPar(b)){
			if (getCol(a) == getCol(b))
				cout << "1\n";
			else
				cout << "2\n";
		}
		else
			cout << "3\n";
	}
	return 0;
}