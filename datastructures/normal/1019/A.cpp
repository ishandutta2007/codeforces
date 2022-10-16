#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
int n,m,p[3005],a[3005],len[3005],c[3005][3005];
int d[3005],tot;
int ans=1e18;
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>p[i]>>a[i];
		c[p[i]][++len[p[i]]]=a[i];
	}
	for (int i=1;i<=m;i++)sort(c[i]+1,c[i]+1+len[i]);
	for (int i=len[1];i<=n;i++){
		int s=i-len[1],val=0;
		tot=0;
		for (int j=2;j<=m;j++)
			for (int k=1;k<=len[j];k++){
				if (len[j]-k+1>=i)s--,val+=c[j][k];
				else d[++tot]=c[j][k];
			}
		sort(d+1,d+1+tot);
		for (int j=1;j<=s;j++)val+=d[j];
		ans=min(ans,val);
	}
	cout<<ans<<endl;
	return 0;
}