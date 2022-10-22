#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int maxn=100010,mod=998244353;
int i,j,k,n,m,a[maxn],b[maxn],c[maxn],tree[maxn];
int lowbit(int x){return x&(-x);};
void add(int x,int s){if(x)for(;x<=n;x+=lowbit(x))tree[x]+=s;}
int find(int x){int s=0;for(;x;x-=lowbit(x))s+=tree[x];return s;}
signed main(){
    cin>>n;
    for(i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=b[i-1]+a[i];
    // for(i=1;i<=n;i++)cerr<<b[i]<<' ';cerr<<endl;
    // return 0;
    for(i=1;i<=n;i++)c[i]=b[i];
    sort(c+1,c+1+n);
    if(c[1]<0 || b[n]!=c[n]){puts("-1");return 0;}
    for(i=1;i<=n;i++)b[i]=lower_bound(c+1,c+1+n,b[i])-c;
    // for(i=1;i<=n;i++)cerr<<b[i]<<' ';cerr<<endl;
    long long Ans=0;
    for(i=1;i<=n;i++)add(b[i],1),Ans+=i-find(b[i]);
    cout<<Ans<<endl;
}
/*
A B C D
A+B -B B+C D
A+B C -B-C B+C+D
A+B+C -C -B B+C+D


A A+B A+B+C
2A+B -A-B 2A+2B+C

A B-A C-B D-C

A B C D

A C-A B-C D-B

A C B D
*/