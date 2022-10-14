#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    unsigned int f=1,num=0;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1; ch=getchar();}
    while(isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
long long tr[1000003],add[1000003];
int n,m,M=1;
inline void buildtree()
{
    while(M<(n+2))M<<=1;
    for(register int i=M+1;i<=M+n;i++)
    {
    	tr[i]=read();
    	int x=i;
    	while(x>>=1)tr[x]=tr[x<<1]+tr[x<<1|1];
    }
}
inline void change(int l,int r,long long val)
{
    l+=M-1,r+=M+1;
    long long L=0,R=0;
    for(register int i=1;l^r^1;i<<=1,l>>=1,r>>=1)
    {
        tr[l]+=L*val,tr[r]+=R*val;
        if(~l&1)add[l^1]+=val,tr[l^1]+=i*val,L+=i;
        if(r&1) add[r^1]+=val,tr[r^1]+=i*val,R+=i;
    }
    tr[l]+=L*val;tr[r]+=R*val;
    while(l>>=1)tr[l]+=val*(L+R);
}
inline long long getsum(int l,int r)
{
    l+=M-1;r+=M+1;
    long long ans=0,L=0,R=0;
    for(register long long i=1;l^r^1;i<<=1,l>>=1,r>>=1)
    {
        ans+=add[l]*L+add[r]*R;
        if(~l&1)ans+=tr[l^1],L+=i;
        if(r&1) ans+=tr[r^1],R+=i;
    }
    ans+=add[l]*L+add[r]*R;
    while(l>>=1) ans+=add[l]*(L+R);
    return ans;
}
//zkw SegmentTree
int main()
{
    n=read();
    buildtree();
    m=read();
    while(m--)
    {
    	int x=read(),y=read();
        printf("%lld\n",getsum(x,y)/10);
	}
    return 0;
}