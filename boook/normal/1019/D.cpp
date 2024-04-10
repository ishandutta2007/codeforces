/*input
5 628335793692286823
735634121 59912302
142271917 367299755
-231820501 586187125
450402558 -840167367
-627664644 -428228185
*/
#include <bits/stdc++.h>
using namespace std;
#define F    first
#define S    second
#define PII pair<int, int>
///------------------------------------------------------------
#define maxn 2002
#define INF 0x3f3f3f3f

PII p[maxn];
int n, idx[maxn], pos[maxn];
long long wnt;
vector<PII> v;

inline PII operator + (PII x, PII y){
	return make_pair(x.F + y.F, x.S + y.S); }
inline PII operator - (PII x, PII y){ 
	return make_pair(x.F - y.F, x.S - y.S); }
inline long long cross(PII x, PII y){ 
	return 1ll * x.F * y.S - 1ll * x.S * y.F; }

inline long long calcArea(PII x, PII y, PII z){
	long long val = abs(cross(y - x, z - x));
	if(val == wnt){
		cout << "Yes" << endl;
		cout << x.F << " " << x.S << endl;
		cout << y.F << " " << y.S << endl;
		cout << z.F << " " << z.S << endl;
		exit(0);
	}
	return val;
}
inline int cmp(PII x, PII y){
	x = p[x.S] - p[x.F];
	y = p[y.S] - p[y.F];
	return cross(x, y) > 0;
}
int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n >> wnt, wnt += wnt;
	for (int i = 1; i <= n; ++ i)
		cin >> p[i].F >> p[i].S;
	sort(p + 1, p + 1 + n);
	for (int i = 1; i <= n; ++ i)
		idx[i] = i, pos[i] = i;
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)
			v.emplace_back(i, j);
	sort(v.begin(), v.end(), cmp);

	for(auto line : v){
		int fr = pos[line.F], ba = pos[line.S], now;
		if(fr > ba) swap(fr, ba);

		now = fr;
		for (int i = 10; i >= 0; -- i) {
			int to = now - (1 << i);
			if(to >= 1 && calcArea(p[idx[fr]], p[idx[ba]], p[idx[to]]) <= wnt) now = to;
		}
		now = ba;
		for (int i = 10; i >= 0; -- i) {
			int to = now + (1 << i);
			if(to <= n && calcArea(p[idx[fr]], p[idx[ba]], p[idx[to]]) <= wnt) now = to;
		}
		swap(idx[fr], idx[ba]);
		swap(pos[line.F], pos[line.S]);
	} 
	cout << "No" << endl;
    return 0;
}