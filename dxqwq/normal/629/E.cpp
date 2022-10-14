#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> a[100003];
long long d[100003];
int f[100003][20],n,m;
long long s0[100003],s1[100003],s2[100003],s3[100003],s4[100003];
inline void init(int u,int father)
{
    d[u]=d[father]+1,s1[u]=1,s2[u]=d[u];
    for(int i=1; (1<<i)<=d[u]; i++) f[u][i]=f[f[u][i-1]][i-1];
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if(v==father)continue;
        f[v][0]=u,init(v,u),s1[u]+=s1[v],s2[u]+=s2[v],s3[u]+=s3[v]+s1[v];
    }
}
inline void tini(int u,int father)
{
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if(v==father)continue;
        s4[v]=s4[u]-2*s1[v]+n,tini(v,u);
    }
}
inline int LCA(int x,int y)
{
    if(d[x]<d[y])swap(x,y);
    for(int i=18; i>=0; --i)
    {
        if(d[f[x][i]]>=d[y])x=f[x][i];
        if(x==y)return x;
    }
    for(int i=18; i>=0; --i) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
long double calc(int _x,int _y,int _z)
{
    int x=_x,y=_y,z=_z;
    if(x==z) swap(x,y);
    int qwq=x;
    for(int i=18; i>=0; --i) if(d[f[x][i]]>d[y]) x=f[x][i];
	return (long double)(s4[y]-s3[x]-s1[x])*s1[qwq]/(s1[qwq]*(n-s1[x]))+(long double)s3[qwq]/s1[qwq]; 
}
int main()
{
    //
    n=read(),m=read();
	for(int i=1,p,q; i<n; ++i) p=read(),q=read(),a[p].push_back(q),a[q].push_back(p); 
	init(1,0);
    for(int i=2; i<=n; i++) s4[1]+=d[i]-1;
    tini(1,0);
	for(int i=1,p,q,r; i<=m; ++i) 
    {
        p=read(),q=read(),r=LCA(p,q);
        if(p!=r && q!=r) printf("%.10Lf\n",(long double)(s2[p]-d[p]*s1[p])/s1[p]+(long double)(s2[q]-d[q]*s1[q])/s1[q]+d[p]+d[q]-2*d[r]+1);
        else printf("%.10Lf\n",calc(p,q,r)+abs(d[p]-d[q])+1);
    }
    return 0;
}
/*
7 4
1 2
1 3
2 4
2 5
3 6
3 7
3 4
3 5
3 6
3 7
*/