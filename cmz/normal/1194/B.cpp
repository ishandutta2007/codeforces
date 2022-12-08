#include<bits/stdc++.h>
using namespace std;
const int N=5e4+50;
int t,n,m,s[N],s2[N],ans;
string c[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);ans=1e9;
		for(int i=0;i<n;i++)cin>>c[i];
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)s[i]+=(c[i][j]=='.');
		for(int j=0;j<m;j++)for(int i=0;i<n;i++)s2[j]+=(c[i][j]=='.');
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)ans=min(ans,s[i]+s2[j]-(c[i][j]=='.'));
		for(int i=0;i<n;i++)s[i]=0;
		for(int j=0;j<m;j++)s2[j]=0;
		printf("%d\n",ans);
	}
	return 0;
}