#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=31*N;
int n,a[N],b[32],x[M],c,d[M],mxd,pos,pos2,to[M];
vector<int>e[M];
void dfs(int u,int fa){
    for(auto &v:e[u]){
        if(v==fa)continue;
        //printf("u:%d v:%d\n",u,v);
        d[v]=d[u]+1;
        if(d[v]>mxd && to[v]){
            mxd=d[v];
            pos=v;
        }
        dfs(v,u);
    }
}
int main(){
    b[0]=1;
    for(int i=1;i<=30;++i){
        b[i]=b[i-1]<<1;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        int lg=30;
        for(int j=a[i];j;j=b[lg]-j){
            x[c++]=j;
            while(lg>=0 && b[lg]>=j)lg--;
            lg++;
        }
    }
    x[c++]=0;
    sort(x,x+c);
    c=unique(x,x+c)-x;
    for(int i=1;i<c;++i){
        int fa=*lower_bound(b,b+31,x[i]);
        fa=fa-x[i];
        int id=lower_bound(x,x+c,fa)-x;
        e[id].push_back(i);
        e[i].push_back(id);
    }
    assert(c<=2000000);
    for(int i=1;i<=n;++i){
        int id=lower_bound(x,x+c,a[i])-x;
        to[id]=i;
    }
    dfs(0,-1);
    pos2=pos;d[pos]=mxd=0;
    dfs(pos,-1);
    printf("%d %d %d\n",to[pos2],to[pos],d[pos]);
    return 0;
}