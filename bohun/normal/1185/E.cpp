#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int mod = 1e9 + 7, nax = 20;

int T;
int n, m;
string s[2005];

vector <pair<int, int>> lit[30];

vector <int> alone;

pair<int, int> jest;

pair <pair<int, int>, pair<int, int>> p[30];

vector <int> pole[2005][2005];

int ile[30];
int blok[30][30];
int byl[30];

void show(int x) {
	if(p[x].fi.fi == 0) {
		cout << p[x].se.fi << " " << p[x].fi.se << " " << p[x].se.se << " " << p[x].fi.se << endl;
	}
	else {
		cout << p[x].fi.se << " " << p[x].se.fi << " " << p[x].fi.se << " " << p[x].se.se << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
		
	cin >> T;
	while(T--) {
		cin >> n >> m;
		
		for(int i = 0; i < 26; ++i) {
			byl[i] = 0;
			lit[i].clear();
		}
		alone.clear();
		
		int maks = -1;
		for(int i = 1; i <= n; ++i) {
			cin >> s[i];
			s[i] = '2' + s[i];
			for(int j = 1; j <= m; ++j) {
				pole[i][j].clear();
				if(s[i][j] != '.') {
					int l = s[i][j] - 'a';
					lit[l].pb(mp(i, j));
					maks = max(maks, l);
					if(l >= maks) {
						jest = mp(i, j);
					}
				}
			}
		}
		
		if(maks == -1) {
			cout << "YES\n";
			cout << 0 << endl;
			continue;
		}
		
		bool ok = 1;
		
		for(int i = 0; i <= maks; ++i) {
			int bigx = -mod;
			int bigy = -mod;
			int smallx = mod;
			int smally = mod;
			if(ss(lit[i]) == 0) {
				alone.pb(i);
				continue;
			}
			bool pion = 1;
			bool poziom = 1;
			for(int j = 0; j < ss(lit[i]); ++j) {
				int Y = lit[i][j].fi;
				int X = lit[i][j].se;
				bigx = max(bigx, X);
				smallx = min(smallx, X);
				bigy = max(bigy, Y);
				smally = min(smally, Y);
				if(j) {
					pion &= (X == lit[i][j - 1].se);
					poziom &= (Y == lit[i][j - 1].fi);
				}
			}
			
			if(!pion && !poziom) {
				ok = 0;
				break;
			}
			if(bigx != smallx && bigy != smally) {
				ok = 0;
				break;
			}
			
			if(pion) {
				p[i] = mp(mp(0, bigx), mp(smally, bigy));
				
				for(int j = smally; j <= bigy; ++j) {
					if(s[j][bigx] == '.')
						ok = 0;
					pole[j][bigx].pb(i);
				}
				
			}
			else {
				p[i] = mp(mp(1, bigy), mp(smallx, bigx));
				
				for(int j = smallx; j <= bigx; ++j) {
					if(s[bigy][j] == '.')
						ok = 0;
					pole[bigy][j].pb(i);
				}
				
			}
		}
		
		if(!ok) {
			cout << "NO\n";
			continue;
		}
		
		for(int i = 1; i <= n; ++i) 
			for(int j = 1; j <= m; ++j) {
				int l = s[i][j] - 'a';
				if(s[i][j] == '.')
					continue;
				for(auto it: pole[i][j]) {
					if(it != l) {
						if(it > l)
							ok = 0;
					}
				}
			}
		if(!ok) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		++maks;
		cout << maks << endl;
		for(auto it: alone) {
			p[it] = mp(mp(0, jest.se), mp(jest.fi, jest.fi));
		}
		
		for(int i = 0; i <= maks - 1; ++i) {
			show(i);
		}
	}
				
			
					
				
				
				
			
		
		
		
			
						
	
	
				
	
	
	return 0;
}