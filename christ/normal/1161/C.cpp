#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
int main() {
	int mn = INT_MAX;
	int n;
	scanf ("%d",&n);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au), mn = min(mn,au);
	int cnt = 0;
	for (int i = 0; i < n; i++) cnt += a[i] == mn;
	printf (cnt > n/2 ? "Bob\n" : "Alice\n");
    return 0;
}