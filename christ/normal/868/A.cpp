#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e6 + 2, LOG = 17, INF = 1e8;
void solve () {
	pair<char,char> pp;
	scanf (" %c%c",&pp.first,&pp.second);
	int n;
	scanf ("%d",&n);
	set<char> start,ed;
	bool yes = 0;
	while (n--) {
		pair<char,char> p;
		scanf (" %c%c",&p.first,&p.second);
		if (p == pp) yes = 1;
		start.insert(p.first); ed.insert(p.second);
		if (p.second == pp.first && start.count(pp.second)) yes = 1;
		if (p.first == pp.second && ed.count(pp.first)) yes = 1;
	}
	printf(yes ? "YES\n" : "NO\n");
}
int main () { 
	int _t = 1;
	//scanf ("%d",&_t);
	for (int cs = 1; cs <= _t; cs++) solve();
    return 0;
}