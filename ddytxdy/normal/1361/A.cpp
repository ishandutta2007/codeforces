#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=5e5+50;
int n,m,a[N];bool fl[N];
vector<int>v[N],vv[N];
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++){
        x=read();y=read();
        v[x].pb(y);v[y].pb(x);
    }
    for(int i=1;i<=n;i++)vv[read()].pb(i);
    for(int i=1;i<=n;i++){
        for(int j=0,x;j<vv[i].size();j++){
            x=vv[i][j];
            if(v[x].size()<i-1)puts("-1"),exit(0);
            for(int k=1;k<=i;k++)fl[k]=0;
            for(int k=0;k<v[x].size();k++)fl[a[v[x][k]]]=1;
            if(fl[i])puts("-1"),exit(0);
            for(int k=1;k<i;k++)if(!fl[k])puts("-1"),exit(0);
            a[x]=i;
        }
    }
    for(int i=1;i<=n;i++)for(int j=0;j<vv[i].size();j++)printf("%d ",vv[i][j]);
    return 0;
}