#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
const int MN = 1e5+2, BASE = 131, MOD = 1e9+7;
void solve () {
	int n;
	scanf ("%d",&n);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	printf (a[0] < a[n-1] ? "YES\n" : "NO\n");
	
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}

// - + - + - + - +
/*
*/