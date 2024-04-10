#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;

const int nax = 1e5 + 111;
const int pier = 350;

int n, m;
int a[nax];
int type, b, c;
int id[nax];
pair<int, int> jump[nax];
int par[nax];

void akt(int i) {
	if(id[a[i] + i] != id[i]) {
		jump[i] = mp(a[i] + i, 1);
		par[i] = i;
	}
	else {
		jump[i] = mp(jump[a[i] + i].fi, jump[a[i] + i].se + 1);
		par[i] = par[a[i] + i];
	}
}

int main() {
	scanf("%d %d", &n, &m);
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
		id[i] = i / pier;
		if(a[i] + i > n + 1)
			a[i] = n + 1 - i;
	}
	id[n + 1] = n / pier + 1;
	for(int i = n; 1 <= i; --i) 
		akt(i);
	FOR(i, 1, m) {
		scanf("%d %d", &type, &b);
		if(type == 0) {
			scanf("%d", &c);
			a[b] = c;
			if(b + a[b] > n + 1)
				a[b] = n + 1 - b;
			int pos = b;
			while(pos > 0 && id[pos] == id[b]) 
				akt(pos--);
		}
		else {
			int ile = 0;
			int last = b;
			while(b != n + 1) {
				last = par[b];
				ile += jump[b].se;
				b = jump[b].fi;
			}
			printf("%d %d\n", last, ile);
		}
	}
			
			
	
	
	
	
	
	
	return 0;
}