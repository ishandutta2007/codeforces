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
void nxt (int &i) {
	if (++i > 12) i = 1;	
}
int lst (int i) {
	if (--i < 0) i = 12;
	return i;
}
void solve () {
	int h,m,s,t1,t2;
	scanf ("%d %d %d %d %d",&h,&m,&s,&t1,&t2);
	bool bad = 0;
	for (int i = t1; i != t2; nxt(i)) {
		if (h == i) {bad=1;break;} //hour hand is between i and i+1
		int mhand = m / 5;
		if (mhand == 0) mhand = 12;
		if (mhand == i) {bad=1;break;}
		int shand = s / 5;
		if (shand == 0) shand = 12;
		if (shand == i) {bad=1;break;}
	}
	if (!bad) return (void) printf("YES\n");
	bad=0;
	for (int i = t1; i != t2; i=lst(i)) {
		if (h == lst(i)) {bad=1;break;}
		int mhand = m / 5;
		if (mhand == 0) mhand = 12;
		if (mhand == lst(i)) {bad=1;break;}
		int shand = s / 5;
		if (shand == 0) shand = 12;
		if (shand == lst(i)) {bad=1;break;}
	}
	printf(bad ? "NO\n" : "YES\n");
}
int main () { 
	int _t = 1;
	//scanf ("%d",&_t);
	for (int cs = 1; cs <= _t; cs++) solve();
    return 0;
}