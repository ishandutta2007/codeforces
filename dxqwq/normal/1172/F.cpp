#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int f=1,num=0;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1; ch=getchar();}
    while(isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
int n,m,a[1000003],p;
long long ans,sum[4000003];
vector<long long> c[4000003];
inline void build(int l,int r,int id)
{
	//c[id].resize(r-l+3);
	for(int i=1; i<=r-l+3; ++i) c[id].push_back(0);
	if(l==r)
	{
		c[id][0]=-10000000000000000ll,c[id][1]=p-a[l],c[id][2]=10000000000000000ll,sum[id]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,id<<1),build(mid+1,r,(id<<1)+1),sum[id]=sum[id<<1]+sum[(id<<1)+1];
	int la=mid-l+2,lb=r-mid+1;
	c[id][0]=-10000000000000000ll;
	for(int i=1; i<=r-l+2; ++i) c[id][i]=10000000000000000ll;
	for(int i=0,j=0; i<=la; ++i)
	{
		j&&--j;
		for(; j<=lb; ++j)
		{
			long long tx=max(c[(id<<1)+1][j]+1ll*i*p-sum[id<<1],c[id<<1][i]);
			long long ty=c[id<<1][i+1]-1ll*i*p+sum[id<<1]-1;
			if(ty<c[(id<<1)+1][j]) 
			{
				j&&--j;
				break;
			}
			(c[id][i+j]>tx)&&(c[id][i+j]=tx);
		}
	}
	//printf("%d %d %d\n",l,r,(int)c[id].size());
	//for(int i=0; i<=r-l+2; ++i) printf("%lld ",c[id][i]);
	//puts("");
	return ;
}
inline void query(int l,int r,int L,int R,int id)
{
	if(r<L||R<l) return ;
	if(L<=l&&r<=R)
	{
		int pos=upper_bound(c[id].begin(),c[id].end(),ans)-c[id].begin()-1;
		//printf("%d\n",pos);
		ans+=sum[id]-1ll*pos*p;
		return ;
	}
	int mid=(l+r)>>1;
	query(l,mid,L,R,id<<1),query(mid+1,r,L,R,(id<<1)+1);
	return ;
}
signed main()
{
    n=read(),m=read(),p=read(); 
    for(int i=1; i<=n; ++i) a[i]=read();
    build(1,n,1);
    //exit(0);
	for(int l,r; m--;) l=read(),r=read(),ans=0,query(1,n,l,r,1),printf("%lld\n",ans);
    //exit(0);
	//return 0;
}