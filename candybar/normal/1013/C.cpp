#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 200005
using namespace std;
typedef long long ll;
const ll inf = (ll)1e18;
int n;
ll a[maxn];
int main(){
	scanf("%d",&n);
	int m = n * 2;
	for(int i=1;i<=m;i++){
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+m+1);
	ll ans = (a[n] - a[1]) * (a[m] - a[n+1]);
	for(int i=2;i<=n;i++){
		ans = min(ans,(a[i+n-1] - a[i]) * (a[m] - a[1]));
	}
	printf("%I64d\n",ans);
	return 0;
}