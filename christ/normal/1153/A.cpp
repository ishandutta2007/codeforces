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
const int MN = 1e5+3, BASE = 31, LOG = 20;
int main() {
	int n,t;
	scanf ("%d %d",&n,&t);
	vector<pii> bus(n);
	for (auto &au : bus) scanf ("%d %d",&au.first,&au.second);
	int close = -1, tt = INT_MAX; int ind = 0;
	for (pii p : bus) {
		++ind;
		int cur = p.first;
		while (cur < t) cur += p.second;
		if (cur < tt) {
			tt = cur;
			close = ind;
		} 
	}
	printf ("%d\n",close);
	return 0;
}
//orz ninjaclasher