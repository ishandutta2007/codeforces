#include<bits/stdc++.h>
#define int long long
const int N=1000050,mod=998244353;
using namespace std;

int n,f[N];
void solve(){
	int s=0;
	cin>>n;
	for(int i=1;i<=n;i++)	
		for(int j=i;j<=n;j+=i)
			f[j]++;
	for(int i=1;i<n;i++)
		s+=f[i]+s,s%=mod;
	cout<<(s+f[n])%mod;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}