#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MN = 105+3, BASE = 31, LOG = 20;
int front[MN], lft[MN];
int exist[MN][MN];
int main() {
	int n,m,h;
	scanf ("%d %d %d",&n,&m,&h);
	for (int i = 1; i <= m; i++) scanf ("%d",front+i);
	for (int i = 1; i <= n; i++) scanf ("%d",lft+i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf ("%d",&exist[i][j]);
			if (j != 1) printf (" ");
			if (exist[i][j]) printf ("%d",min(front[j],lft[i]));
			else printf ("0");
		}
		printf ("\n");
	}
	return 0;
}
//orz ninjaclasher