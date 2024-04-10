#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 100005;
int n, k, p, ans, inv4, cnt[N], inv[N];
void divide(int x, int k){
	if(k==1 || x==1) return (void)(++cnt[x], ans=(ans+(ll)x*(x-1)%p*inv4)%p);
	divide(x/2, k-1), divide(x-x/2, k-1);
}
inline int calc(int x, int y){
	int ans=(ll)x*y%p*(p+1)/2%p;
	for(int i=2; i<=x+y; ++i) ans=(ans+(min(x, i-1)-max(1, i-y)+1ll)*(p-inv[i]))%p;
	return ans;
}
int main() {
	scanf("%d%d%d", &n, &k, &p), inv4=(p+1ll)*(p+1)/4%p;
	inv[1]=1;
	for(int i=2; i<=n; ++i) inv[i]=(ll)(p-p/i)*inv[p%i]%p;
	divide(n, k);
	int x=0;
	for(int i=1; i<=n; ++i) if(cnt[i]){ x=i; break;}
	ans=(ans+(ll)cnt[x]*(cnt[x]-1)/2%p*calc(x, x))%p;
	if(cnt[x+1])
		ans=(ans+(ll)cnt[x]*cnt[x+1]%p*calc(x, x+1)+(ll)cnt[x+1]*(cnt[x+1]-1)/2%p*calc(x+1, x+1))%p;
	return printf("%d", ans), 0;
}