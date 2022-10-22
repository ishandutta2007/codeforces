/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, bool> pib;
#define F first
#define S second
const int N = 301234;
vector <pib> v[N];
vector <pair <int, pib>> p;

int32_t main(){
	int n, q;
	scanf("%d%d", &n, &q);
	int ans = 0;
	while (q--) {
		int type, x;
		scanf("%d%d", &type, &x);
		if (type == 1){
			v[x].push_back({p.size(), 1});
			p.push_back({x, {v[x].size() - 1, 1}});
			ans++;
			printf("%d ", ans);
		} else if (type == 2) {
			int an = 0;
			for (int i = v[x].size() - 1; i >= 0; i--) {
				if (v[x][i].S == 0)
					break;
				if (p[v[x][i].F].S.S == 1)
					an++;
				v[x][i].S = 0;
			}
			ans -= an;
			printf("%d ", ans);
		} else {
			int an = 0;
			for (int i = x - 1; i >= 0; i--) {
				if (p[i].S.S == 0)
					break;
				if (v[p[i].F][p[i].S.F].S == 1)
					an++;
				p[i].S.S = 0;
			}
			ans -= an;
			printf("%d ", ans);
		}
	}
}