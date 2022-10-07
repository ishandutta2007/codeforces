#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,c,l[N],r[N],i,al[1024][1024],j,t[1024],pl[25],bb[25],aa[25];
int a[25],b[25],pa[N],pb[N],p[1024][1024],ans=1<<30,ansl,ansr,u,vis[1100005];
int main()
{
	scanf("%d %d %d",&n,&m,&c);
	for(i=1;i<=c;++i)
		scanf("%1d",&a[i]);
	for(i=1;i<=c;++i)
		scanf("%1d",&b[i]);
	for(i=1;i<=n;++i)
		scanf("%d %d",&l[i],&r[i]);
	for(i=1;i<=c;++i)
		pl[i]=i;
	for(i=0;i<=n;++i)
	{
		if(i!=0)
			swap(pl[l[i]],pl[r[i]]);
		for(j=1;j<=c;++j)
			bb[pl[j]]=b[j];
		for(j=1;j<=c;++j)
			aa[pl[j]]=a[j];
		for(j=1;j<=c;++j)
		{
			pa[i]=pa[i]*2+aa[j];
			pb[i]=pb[i]*2+bb[j];
		}
	}
	for(i=n;i>=0;--i)
	{
		if(vis[pb[i]])
			pb[i]=-1;
		else
			vis[pb[i]]=1;
	}
	memset(vis,0,sizeof(vis));
	for(i=0;i<=n;++i)
		if(vis[pa[i]])
			pa[i]=-1;
		else
			vis[pa[i]]=1;
	for(i=0;i<1024;++i)
		t[i]=__builtin_popcount(i);
	memset(p,0x7f,sizeof(p));
	for(i=m;i<=n;++i)
	{
		if(pa[i-m]!=-1)
		{
			int x=(pa[i-m]>>10),y=pa[i-m]&((1<<10)-1);
			for(j=0;j<1024;++j)
				if(p[x][j]>t[j^y])
				{
					p[x][j]=t[j^y];
					al[x][j]=i-m;
				}
		}
		if(pb[i]!=-1)
		{
			int x=pb[i]>>10,y=pb[i]&((1<<10)-1);
			for(j=0;j<1024;++j)
				if(ans>p[j][y]+t[j^x])
				{
					ans=p[j][y]+t[j^x];
					ansl=al[j][y];
					ansr=i;
				}
		}
	}
	cout<<c-ans<<endl;
	cout<<ansl+1<<' '<<ansr<<endl;
}