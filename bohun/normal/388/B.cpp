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

const int nax = 1005;

int k;

int ans[nax][nax];
int fre = 3;	
int LOG[31];

int daj() {
	return fre++;
}

void add(int a, int b) {
	ans[a][b] = ans[b][a] = 1;
}

int main() {	
	scanf("%d", &k);
	
	int v = daj();
	add(2, v);
	LOG[0] = v;
	FOR(i, 1, 29) {
		v = daj();
		LOG[i] = v;
		int u = daj();
		int uu = daj();
		add(u, LOG[i]);
		add(u, LOG[i - 1]);
		add(uu, LOG[i]);
		add(uu, LOG[i - 1]);
	}
	for(int i = 29; 0 <= i; --i) {
		if(((1 << i) & k)) {
			int last = 1;
			int R = (29 - i) * 2;
			while(R--) {
				int u = daj();
				add(u, last);
				last = u;
			}
			add(LOG[i], last);
		}
	}
	assert(fre <= 1000);
	fre -= 1;
	printf("%d\n", fre);
	FOR(i, 1, fre) {
		FOR(j, 1, fre) {
			printf(ans[i][j] == 1 ? "Y" : "N");
		}
		printf("\n");
	}
	
	
	
			
	return 0;
}