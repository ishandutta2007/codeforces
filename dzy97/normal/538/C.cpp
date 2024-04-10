#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
const int N = 1e5 + 10;
int n, m, d[N], h[N];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i ++) scanf("%d%d", &d[i], &h[i]);
	int ans = 0;
	for(int i = 1;i < m;i ++){
		int k = d[i + 1] - d[i];
		if(h[i] + k < h[i + 1] || h[i] - k > h[i + 1]){
			printf("IMPOSSIBLE\n");
			return 0;
		}
		int cur = d[i + 1] - d[i] - abs(h[i + 1] - h[i]);
		ans = max(ans, max(h[i + 1], h[i]) + cur / 2);
	}
	ans = max(ans, h[1] + d[1] - 1);
	ans = max(ans, h[m] + n - d[m]);
	printf("%d\n", ans);
	return 0;
}