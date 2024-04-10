#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 10;

int n, a[MAXN], x, y;
ll p[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(9);
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n, greater<int>());
	for (int i = 0; i < n; i++)
		p[i + 1] = p[i] + a[i];
	cout << max(ld(p[x])/ x + ld(p[x + y] - p[x])/ y, ld(p[y])/ y + ld(p[x + y] - p[y])/ x) << endl;
	return 0;
}