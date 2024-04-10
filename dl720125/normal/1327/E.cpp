#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define MOD 998244353ll
using namespace __gnu_pbds;
using namespace std;

int n,pw[200010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	pw[0]=1ll;
	for(int i=1;i<=n;i++){
		pw[i]=(pw[i-1]*10ll)%MOD;
	}
	for(int i=1;i<n;i++){
		int num1=2,num2=n-i-1;
		int val1=(num1*90ll*pw[n-i-1])%MOD;
		int val2=0ll;
		if(i<n-1) val2=(num2*810ll*pw[n-i-2])%MOD;
		cout<<(val1+val2)%MOD<<" ";
	}
	cout<<10<<endl;
	return 0;
}