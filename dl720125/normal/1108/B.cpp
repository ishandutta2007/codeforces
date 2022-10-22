#include <bits/stdc++.h>
//#define int long long
using namespace std;

int x[10010],b[10010],n,maxv;
bool vis[10010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		maxv=max(maxv,x[i]);
	}
	cout<<maxv<<" ";
	for(int i=1;i<=n;i++) if(maxv%x[i]==0&&b[x[i]]==0){
		b[x[i]]=1;
		vis[i]=1;
	}
	int maxv2=0;
	for(int i=1;i<=n;i++) if(!vis[i]){
		maxv2=max(maxv2,x[i]);
	}
	cout<<maxv2<<endl;
	return 0;
}