#include<bits/stdc++.h>
using namespace std; 
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node
{
	int pr,sf,ans,f;
};
node merge(node x,node y)
{
	node res;
	res.ans=max(max(x.ans,y.ans),x.sf+y.pr);
	res.pr=x.pr+x.f*y.pr;
	res.sf=y.sf+y.f*x.sf;
	res.f=x.f&y.f;
	return res;
}
node A[10000003];
int l[10000003],r[10000003]; 
int rt[1000003],a[1000003],cnt=1;
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
    	A[++cnt]=(node){1,1,1,1};
        return cnt;
    }
    int res=++cnt;
    int mid=(L+R)>>1;
    if(p<=mid) l[res]=update(L,mid,p,l[id]),r[res]=r[id];
    else r[res]=update(mid+1,R,p,r[id]),l[res]=l[id];
    if(!r[res]) A[res]=A[l[res]];
	else if(!l[res]) A[res]=A[r[res]];
	else A[res]=merge(A[l[res]],A[r[res]]);
    return res;
}
int lsh[1000003];
node query(int L,int R,int ll,int rr,int id)
{
    if(L<=ll&&rr<=R) return A[id];
    int mid=(ll+rr)>>1;
    if(R<=mid) return query(L,R,ll,mid,l[id]);
    if(L>mid) return query(L,R,mid+1,rr,r[id]);
    return merge(query(L,R,ll,mid,l[id]),query(L,R,mid+1,rr,r[id]));
}
vector<int> v[100003];
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) lsh[i]=a[i]=read();
    sort(lsh+1,lsh+n+1);
    int len=unique(lsh+1,lsh+n+1)-lsh-1;
    for(int i=1; i<=n; i++) a[i]=lower_bound(lsh+1,lsh+len+1,a[i])-lsh,v[a[i]].push_back(i);
    build(1,n,1),rt[len+1]=1;
    for(int i=len; i>=1; i--) 
	{
		for(int x:v[i])if(!rt[i]) rt[i]=update(1,n,x,rt[i+1]); 
		else rt[i]=update(1,n,x,rt[i]); 
	}
    for(int m=read(); m--;)
    {
        int L=read(),R=read(),k=read();
        int l=1,r=len,ans=1;
        while(l<=r)
        {
        	int mid=(l+r)>>1;
			if(query(L,R,1,n,rt[mid]).ans>=k) ans=mid,l=mid+1; else r=mid-1;
    	}
    	printf("%d\n",lsh[ans]);
	}	
	return 0;
}