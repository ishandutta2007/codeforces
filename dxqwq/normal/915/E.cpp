#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int ls[15000003],rs[15000003],val[15000003],cnt=1;
void update(int l,int r,int& L,int& R,int& k,int id)
{
	if(L<=l&&r<=R) 
	{
		val[id]=(r-l+1)*k;
		return ;
	}
	int mid=(l+r)>>1;
	if(!ls[id])ls[id]=++cnt,rs[id]=++cnt;
	if(val[id]==r-l+1) val[ls[id]]=mid-l+1,val[rs[id]]=r-mid;
	if(val[id]==0) val[ls[id]]=val[rs[id]]=0;
	if(L<=mid) update(l,mid,L,R,k,ls[id]);
	if(R>mid) update(mid+1,r,L,R,k,rs[id]);
	val[id]=val[ls[id]]+val[rs[id]];
	return ;
}
signed main()
{
    int n=read(),q=read();
    val[1]=n;
    for(;q--;)
    {
    	int l=read(),r=read(),k=read()-1;
    	update(1,n,l,r,k,1);
    	printf("%d\n",val[1]);
	}
    return 0;
}