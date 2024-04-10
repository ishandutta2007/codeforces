#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#define inf 1000000000
using namespace std;
int t,n,m,a[200005],l[200005],r[200005];
int pre[200005][25],nxt[200005],mnl[200005];
int d[200005];
map<int,int> c;
int find(int p,int l){
	for (int i=20;i>=0;i--)
		if (pre[p][i]>=l)p=pre[p][i];
	return p;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=0;i<=n+1;i++){
			memset(pre[i],0,sizeof(pre[i]));
			nxt[i]=0;
			mnl[i]=n+1;
			d[i]=0;
		}
		for (int i=1;i<=m;i++){
			scanf("%d%d",&l[i],&r[i]);
			mnl[r[i]]=min(mnl[r[i]],l[i]);
		}
		c.clear();
		for (int i=1;i<=n;i++){
			pre[i][0]=c[a[i]];
			if (c[a[i]]!=0)nxt[c[a[i]]]=i;
			c[a[i]]=i;
		}
		for (int i=1;i<=20;i++)
			for (int j=1;j<=n;j++)
				pre[j][i]=pre[pre[j][i-1]][i-1];
		int fg=1;
		int mn=n+1;
		for (int i=n;i>=1;i--){
			mn=min(mn,mnl[i]);
			int x=find(i,mn),y=i;
			if (x==y)continue;
			fg=0;
			int _x=nxt[x],_y=pre[y][0];
			d[_x+1]=max(d[_x+1],inf);
			d[x+1]=max(d[x+1],y);
			d[1]=max(d[1],_y);
		}
		if (fg==1)puts("0");
		else{
			int ans=1000000000;
			for (int i=1;i<=n;i++){
				d[i]=max(d[i],d[i-1]);
				ans=min(ans,max(d[i],i)-i+1);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}