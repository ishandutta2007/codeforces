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
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 1e6 + 5, pod = (1 << 19), inf = 1e9 + 5;

int n;
char s[nax];
vector <int> v[nax][5];
int mapa[2005];
vector <string> res;

vector <pair<int, int>> slabe, goods;

vector <int> alone;

vector <pair <pair<int, int>, pair<int, int>>> q;


void cat(int i) {
	for(auto it: res[i]) {
		printf("%c", it);
	}
}

int main() {
	
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	
	mapa['a' - 'a'] = 0;
	mapa['e' - 'a'] = 1;
	mapa['u' - 'a'] = 2;
	mapa['o' - 'a'] = 3;
	mapa['i' - 'a'] = 4;
	
	scanf ("%d", &n);
	for(int i = 0; n > i; ++i) {
		scanf("%s", s);
		int len = strlen(s);
		int ile = 0;
		int last = -1;
		string X = "";
		for(int j = 0; len > j; ++j) {
			X.pb(s[j]);
			if(s[j] == 'a' || s[j] == 'e' || s[j] == 'u' || s[j] == 'i' || s[j] == 'o') {
				++ile;
				last = mapa[s[j] - 'a'];
			}
		}
		res.pb(X);
		v[ile][last].pb(i);
	}
	
	for(int i = 0; nax > i; ++i) {
		for(int j = 0; 5 > j; ++j) {
			int last = -1;
			for(auto it: v[i][j]) {
				if(last == -1) {
					last = it;
				}
				else {
					goods.push_back({last, it});
					last = -1;
				}
			}
			if(last != -1) {
				alone.pb(last);
		}
	}
		int l = -1;
		for(auto it: alone) {
			if(l == -1) {
				l = it;
			}
			else {
				slabe.pb({l, it});
				l = -1;
			}
		}
	
		alone.clear();
		
	}
	
	int k = min(ss(slabe), ss(goods));
	
	for(int i = 0; k > i; ++i) {
		pair <int, int> ja = goods.back();
		pair <int, int> on = slabe.back();
		goods.pop_back();
		slabe.pop_back();
		q.pb({on, ja});
	}
	int X = ss(goods) / 2;
	for(int i = 0; X > i; ++i) {
		pair <int, int> ja = goods.back();
		goods.pop_back();
		pair <int, int> on = goods.back();
		goods.pop_back();
		q.pb({ja, on});
	}
	
	printf ("%d\n", ss(q));
	
	for(auto it: q) {
		cat(it.fi.fi);
		printf(" ");
		cat(it.se.fi);
		printf("\n");
		cat(it.fi.se);
		printf(" ");
		cat(it.se.se);
		printf("\n");
	}
	
			
			
	
	
	
	
	
	
		
	
		
	
    return 0;
}