#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int M = 1000000007;

const int maxn = 300005;
int n, m;
int x[maxn], y[maxn];
ll sx[maxn], sy[maxn];
int p[maxn];
ll res[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", x + i, y + i);
		p[i] = i;
	}
	sort(p + 1, p + n + 1, [](int i, int j){
			return x[i] - y[i] < x[j] - y[j];
		});
	//for(int i = 1; i <= n; ++i) q[p[i]] = i;
	for(int i = 1; i <= n; ++i)
		sx[i] = sx[i - 1] + x[p[i]];
	for(int i = 1; i <= n; ++i)
		sy[i] = sy[i - 1] + y[p[i]];

	for(int i = 1; i <= n; ++i)
		res[p[i]] = 1LL * y[p[i]] * (i - 1) + 1LL * x[p[i]] * (n - i)
			+ sy[n] - sy[i] + sx[i - 1];

	for(int i = 1; i <= m; ++i){
		int p, q;
		scanf("%d%d", &p, &q);
		res[p] -= min(x[p] + y[q], x[q] + y[p]);
		res[q] -= min(x[p] + y[q], x[q] + y[p]);
	}

	for(int i = 1; i <= n; ++i)
		printf("%I64d ", res[i]);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}