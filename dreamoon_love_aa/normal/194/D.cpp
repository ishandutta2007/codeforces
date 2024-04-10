#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int a[33],b[33],k[33],p[33],u,r,n;
long long an=-1000000000000000000ll;
set<pair<long long,int> >H;
void dfs(int x,int ha[],long long yo){
    if(H.count(make_pair(yo,x)))return;
    H.insert(make_pair(yo,x));
    int i;
    if(!(x&1)){
        long long tmp=0;
        for(i=1;i<=n;i++)tmp+=ha[i]*k[i];
        an=max(an,tmp);
    }
    if(!x)return;
    int c[33];
    for(i=1;i<=n;i++)c[i]=ha[p[i]]+r;
    for(i=1;i<=x;i+=2)dfs(x-i,c,yo<<1);
    for(i=1;i<=n;i++)ha[i]^=b[i];
    if(x&1){
        long long tmp=0;
        for(i=1;i<=n;i++)tmp+=ha[i]*k[i];
        an=max(an,tmp);
    }
    for(i=1;i<=n;i++)c[i]=ha[p[i]]+r;
    for(i=2;i<=x;i+=2)dfs(x-i,c,(yo<<1)+1);
}
int main(){
    int i,j;
    scanf("%d%d%d",&n,&u,&r);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    for(i=1;i<=n;i++)scanf("%d",&k[i]);
    for(i=1;i<=n;i++)scanf("%d",&p[i]);
    dfs(u,a,0);
    cout<<an<<endl;
    return 0;
}