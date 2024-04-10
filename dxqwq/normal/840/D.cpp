#include<bits/stdc++.h>
using namespace std; 
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,2097152,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int l[20000003],r[20000003],val[20000003],ans[20000003],rt[1000003],a[1000003],cnt=1;
void build(int L,int R,int id)
{
    if(L==R) return ;
    int mid=(L+R)>>1;
    l[id]=++cnt,build(L,mid,cnt);
    r[id]=++cnt,build(mid+1,R,cnt);
    return ;
}
int update(int L,int R,int& p,int id)
{
    if(L==R)
    {
        val[++cnt]=val[id]+1;
        return cnt;
    }
    int res=++cnt;
    int mid=(L+R)>>1;
    if(p<=mid) l[res]=update(L,mid,p,l[id]),r[res]=r[id];
    else r[res]=update(mid+1,R,p,r[id]),l[res]=l[id];
    val[res]=val[l[res]]+val[r[res]];
    return res;
}
int query(int L,int R,int k,int id1,int id2)
{
    if(L==R) return L;
    int CntL=val[l[id2]]-val[l[id1]],CntR=val[r[id2]]-val[r[id1]];
	int mid=(L+R)>>1;
    if(k<CntL) 
    {
    	int res=query(L,mid,k,l[id1],l[id2]);
    	if(res!=-1) return res;
	}
    if(k<CntR)
	{
		int res=query(mid+1,R,k,r[id1],r[id2]);
		if(res!=-1) return res;
	} 
    return -1;
}
signed main()
{
    int n=read(),m=read();
    for(int i=1; i<=n; i++) a[i]=read();
    build(1,n,1),rt[0]=1;
    for(int i=1; i<=n; i++) rt[i]=update(1,n,a[i],rt[i-1]); 
    for(int i=1; i<=m; i++)
    {
        int L=read(),R=read(),k=(R-L+1)/read();
        printf("%d\n",query(1,n,k,rt[L-1],rt[R]));
    }
	return 0;
}