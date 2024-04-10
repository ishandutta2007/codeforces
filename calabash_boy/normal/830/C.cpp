#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, a[111];
ll ans, k;

bool chk(ll d, ll k){
	ll sum = 0;
	for(int i = 1; i <= n; ++i) sum += (a[i] + d - 1) / d;
//	cout<<"check("<<d<<","<<k<<") sum="<<sum<<" return"<<(sum<=k)<<endl; 
	return sum <= k;
}

int main(){
//	freopen("input.inp", "r", stdin);
	scanf("%d%I64d",&n,&k);
	for(int i = 1; i <= n; ++i) scanf("%d",&a[i]), k += a[i];
	for(ll l = 1, r; l <= k; l = r + 1){
		r = k / (k / l);
		if (chk(r, k / r)) ans = max(ans, r);
	}
	printf("%I64d",ans);
	return 0;
}