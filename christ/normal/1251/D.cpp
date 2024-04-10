
// Problem : D. Salary Changing
// Contest : Educational Codeforces Round 75 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1251/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
bool check (int mid, ll cash, vector<pii> &range) {
	int n = range.size();
	vector<pii> can, cant;
	for (auto &au : range) {
		if (au.second >= mid) {
			can.push_back(au);
		} else {
			cant.push_back(au);
		}
	}
	if (can.size() < (n+1)/2) return 0;
	sort(all(can));
	ll cost = 0;
	for (int i = 0; i <= n/2; i++) cost += max(mid,can.back().first), can.pop_back();
	for (auto &au : can) cost += au.first;
	for (auto &au : cant) cost += au.first;
	return cost <= cash;
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int n; ll s;
		scanf ("%d %lld",&n,&s);
		vector<pii> range(n);
		for (auto &au : range) scanf ("%d %d",&au.first,&au.second);
		int low = 1, high = 1e9, mid, ans = -1;
		while (low <= high) {
			mid = (low+high)/2;
			if (check(mid,s,range)) low = (ans = mid) + 1;
			else high = mid-1;
		}
		printf ("%d\n",ans);
	}
	return 0;
}