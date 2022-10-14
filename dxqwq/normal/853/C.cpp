// Problem: C. Boredom
// Contest: Codeforces - Codeforces Round #433 (Div. 1, based on Olympiad of Metropolises)
// URL: https://codeforces.com/contest/853/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int l[10000003],r[10000003],val[10000003],rt[1000003],a[1000003],cnt=1;
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
int query_(int L,int R,int k,int id)
{
    if(L==R) return val[id];
    int mid=(L+R)>>1;
    if(k<=mid) return query_(L,mid,k,l[id]);
    else return val[l[id]]+query_(mid+1,R,k,r[id]);
}
int lsh[1000003];
#define ll long long 
ll cmll02(int x)
{
	return 1ll*x*(x-1)/2;
}
int n,m;
int query(int L,int R,int K,int RT)
{
	if(K==0) return 0;
	return query_(L,R,K,RT);
}
int Q(int L,int R,int X,int Y)
{
	if(L>R||X>Y) return 0;
	return 
	query(1,n,Y,rt[R])-query(1,n,X-1,rt[R])
	-query(1,n,Y,rt[L-1])+query(1,n,X-1,rt[L-1]);
}
signed main()
{
    n=read(),m=read();
    for(int i=1; i<=n; i++) a[i]=read();
    build(1,n,1),rt[0]=1;
    for(int i=1; i<=n; i++) rt[i]=update(1,n,a[i],rt[i-1]);
    for(int i=1; i<=m; i++)
    {
        int L=read(),X=read(),R=read(),Y=read();
        ll ANS=cmll02(n)-cmll02(L-1);
        ANS=ANS
        -cmll02(n-R)
        -cmll02(Q(1,n,1,X-1))
        -cmll02(Q(1,n,Y+1,n));
        ANS=ANS
        +cmll02(Q(1,L-1,1,X-1))
        +cmll02(Q(1,L-1,Y+1,n))
        +cmll02(Q(R+1,n,1,X-1))
        +cmll02(Q(R+1,n,Y+1,n));
        printf("%lld\n",ANS);
    }
	return 0;
}