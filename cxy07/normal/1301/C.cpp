//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

int T;
int n,m,val,a,b; 
int ans,va,vb,la,lb;

signed main () {
	cin >> T;
	while(T--) {
		cin >> n >> m;
		if(n == m) {printf("%lld\n",1ll * (n + 1) * n >> 1); continue;}
		if(!m) {puts("0"); continue;}
		m++; 
		val = n - m + 1;//0
		va = val / m;
		vb = va + 1;
		b = val - va * m;
		a = m - b;
		ans = (n + 1) * n / 2 - a * (va + 1) * va / 2 - b * (vb + 1) * vb / 2; 
		//cout << ans << endl;
		printf("%lld\n",ans);
	}
	return 0;
}