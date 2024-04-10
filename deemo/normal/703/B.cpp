#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, k, c[MAXN], id[MAXN];
bool mark[MAXN];

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	while (k--){
		int x;	scanf("%d", &x), x--;
		mark[x] = 1;
	}
	ll ans = 0;
	ll sm = 0;
	for (int i = 0; i < n; i++)	sm += c[i];
	for (int i = 0; i < n; i++)
		if (mark[i]){
			sm -= c[i];
			ans += sm * c[i];
		}
	for (int i = 0; i < n; i++){
		int a = i, b = (i + 1) % n;
		if (!mark[a] && !mark[b])
			ans += ll(c[a]) * c[b];
	}
	printf("%lld\n", ans);
	return 0;
}