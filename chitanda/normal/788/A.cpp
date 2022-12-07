#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	scanf("%d", &n);
	int x, y;
	scanf("%d", &x);
	ll f = 0, g = 0, ans = 0;
	for(int i = 1; i < n; ++i){
		scanf("%d", &y);
		if(i & 1){
			f = f + abs(y - x);
			g = max(0LL, g - abs(y - x));
		}else{
			f = max(0LL, f - abs(y - x));
			g = g + abs(y - x);
		}
		ans = max(ans, max(f, g));
		x = y;
	}
	printf("%lld\n", ans);
	return 0;
}