#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

const int p = 15;

int n;
int a[101];
int full;
map<vector<int>, int> mapa;

int main() {	
	full = (1 << 30) - 1;
	full ^= (1 << p) - 1;
	scanf("%d", &n);
	FOR(i, n) scanf("%d", a + i);
	for(int maska = 0; maska < (1 << p); ++maska) {
		vector <int> ja;
		for(int i = 1; i <= n; ++i) 
			ja.pb(__builtin_popcount(((a[i] & ((1 << p) - 1)) ^ maska)));
		mapa[ja] = maska;
	}
	vector <int> on;
	for(int maska = 0; maska < (1 << p); ++maska) {
		for(int len = 0; len <= 30; ++len) {
			on.clear();
			for(int j = 1; j <= n; ++j) 
				on.pb(len - __builtin_popcount(((a[j] >> 15) ^ maska)));
			if(mapa.find(on) != mapa.end()) {
				printf("%d", (maska << 15) + mapa[on]);
				return 0;
			}
		}
	}
	printf("-1\n");
	
	
	return 0;
}