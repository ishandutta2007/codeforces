
// Problem : B. Marvolo Gaunt's Ring
// Contest : Manthan, Codefest 17
// URL : https://codeforces.com/contest/855/problem/B
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
int main () {
	int n; vector<int> t(3);
	scanf ("%d %d %d %d",&n,&t[0],&t[1],&t[2]);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	ll best0 = LLONG_MIN, best1 = LLONG_MIN, best2 = LLONG_MIN;
	for (int i : a) {
		best0 = max(best0,i*1LL*t[0]);
		best1 = max(best1,best0+i*1LL*t[1]);
		best2 = max(best2,best1+i*1LL*t[2]);
	}
	printf ("%lld\n",best2);
	return 0;
}