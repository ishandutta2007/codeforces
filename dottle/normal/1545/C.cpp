#include<bits/stdc++.h>
#define int long long
const int N=1005,mod=998244353; 
using namespace std;

int a[N][N],c[N][N];

void solve(){
	int n;cin>>n;
	int ans=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)c[i][j]=0;
	for(int i=1;i<=n<<1;i++)for(int j=1;j<=n;j++)cin>>a[i][j],c[a[i][j]][j]++;
	vector<int> v(n<<1|1),res;
	for(int i=1;i<=n;i++){
		int nw=0;
		for(int j=1;j<=n<<1;j++)if(!v[j])
			for(int k=1;k<=n;k++)
				if(c[a[j][k]][k]==1)
					nw=j;
		if(!nw)
			for(nw=1,ans=ans*2%mod;v[nw];nw++);
		for(int j=1;j<=n<<1;j++)if(!v[j]){
			for(int k=1;k<=n;k++)
				if(a[j][k]==a[nw][k])v[j]=1;
			if(v[j])for(int k=1;k<=n;k++)
				c[a[j][k]][k]--;
		}
		res.push_back(nw);
	}
	cout<<ans<<endl;
	for(auto x:res)cout<<x<<' ';cout<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}