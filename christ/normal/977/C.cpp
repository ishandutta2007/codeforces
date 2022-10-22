#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e3+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	sort(all(a));
	if (k > n) return !printf ("-1\n");
	int att;
	if (k == 0) att = 1;
	else att = a[k-1];
	int cnt = 0;
	for (int i = 0; i < n; i++) if (a[i] <= att) ++cnt;
	if (cnt != k) printf ("-1\n");
	else printf ("%d\n",att);
    return 0;
}