    //Code By CXY
    #include<bits/stdc++.h>
    using namespace std;
     
    #define int long long
     
    const int mod = 1e9 + 7;
     
    int n,m,ans; 
    int a[21][1010],b[21][1010];
     
    signed main () {
    	scanf("%lld%lld",&n,&m);
    	for(register int i = 1;i <= n; ++i)
    		a[1][i] = b[1][i] = 1;
    	for(register int i = 2;i <= m; ++i) 
    		for(register int j = 1;j <= n; ++j) 
    			for(register int k = 1;k <= j; ++k)
    				(a[i][j] += a[i - 1][k]) %= mod,(b[i][k] += b[i - 1][j]) %= mod;
    	for(register int i = 1;i <= n; ++i) 
    		for(register int j = 1;j <= i; ++j) 
    			(ans += (a[m][j] % mod) * (b[m][i] % mod) % mod) %= mod;
    	printf("%lld\n",ans);
    	return 0;
    }