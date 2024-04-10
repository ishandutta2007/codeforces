// Problem : F. Ray in the tube
// Contest : Codeforces Round #509 (Div. 2)
// URL : https://codeforces.com/contest/1041/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
map<int,int> has, md;
int main () {
	int n,y1,m;
	scanf ("%d %d",&n,&y1);
	vector<int> x1(n);
	for (auto &au : x1) scanf ("%d",&au), ++has[au];
	scanf ("%d %d",&m,&y1);
	vector<int> x2(m);
	int ans = 0;
	for (auto &au : x2) {
		scanf ("%d",&au);
		if (has[au]) ans = max(ans,2);
	}
	for (int diff = 2; diff <= 1e9; diff <<= 1) {
		md.clear();
		for (int i : x1) ans=max(ans,++md[i%diff]);
		for (int i : x2) ans=max(ans,++md[(i+diff/2)%diff]);
	}	
	printf ("%d\n",ans);
	return 0;
}