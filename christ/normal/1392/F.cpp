#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5 + 5, MOD = 1e9 + 7;
int main () {
	int n; ll sum=0;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++) {
		ll a; scanf ("%lld",&a); sum += a - i;
	}
	ll go = sum / n;
	sum -= go * n;
	vector<ll> ret(n);
	for (int i = 0; i < n; i++) ret[i] = i + go;
	for (int i = 0; i < sum % n; i++) {
		ret[i]++;
	} 
	for (int i = 0; i < n; i++) printf ("%lld%c",ret[i]," \n"[i+1==n]);
	return 0;
}