#include<bits/stdc++.h>
using namespace std;
int n,q,dist[200000],dp[200000][19],H[200000];vector<int>x[200000];map<int,int>MM[200000];
void dfs(int pos,int depth){
    if(dist[pos]!=-1)return;
    dist[pos]=depth;
    for(int i=0;i<x[pos].size();i++)dfs(x[pos][i],depth+1);
}
int ances(int u,int f){
    int Y=H[f];
    for(int i=Y;i>=0;i--){
        if(f>=(1<<i)){u=dp[u][i];f-=(1<<i);}
    }
    return u;
}
int LCA(int u,int v){
    if(dist[u]<dist[v])swap(u,v);
    u=ances(u,dist[u]-dist[v]);
    int L=0,R=131072,M,maxn=1e9;
    for(int i=0;i<18;i++){
        M=(L+R)/2;
        if(ances(u,M)==ances(v,M)){maxn=min(maxn,M);R=M;}
        else L=M;
    }
    if(MM[u][v]>=1)return MM[u][v];
    int vv=ances(u,maxn);
    MM[u][v]=vv;
    return vv;
}
int dst(int u,int v){
    return dist[u]+dist[v]-dist[LCA(u,v)]*2;
}
int main(){
    cin>>n>>q;
    for(int i=0;i<200000;i++){
        for(int j=0;j<20;j++){if((1<<j)<=i)H[i]=j;}
    }
    for(int i=2;i<=n;i++){int a;cin>>a;x[i].push_back(a);x[a].push_back(i);}
    for(int i=1;i<=n;i++)dist[i]=-1;
    dfs(1,0);
    for(int i=2;i<=n;i++){
        for(int j=0;j<x[i].size();j++){
            if(dist[x[i][j]]<dist[i])dp[i][0]=x[i][j];
        }
    }
    for(int i=1;i<=18;i++){
        for(int j=1;j<=n;j++){dp[j][i]=dp[dp[j][i-1]][i-1];}
    }
    /*for(int i=1;i<=n;i++)cout<<dist[i]<<' ';cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++)cout<<dp[i][j]<<' ';cout<<endl;
    }*/
    for(int i=0;i<q;i++){
        int d[3];cin>>d[0]>>d[1]>>d[2];int maxn=0;sort(d,d+3);int V=0;
        do{
            if(d[0]>d[1])continue;
            int a=d[0],b=d[1],c=d[2];
            //cout<<a<<' '<<b<<' '<<c<<' '<<LCA(a,b)<<' '<<LCA(a,c)<<' '<<LCA(b,c)<<endl;
            int P1=dist[LCA(a,b)];
            int P2=dist[LCA(a,c)];
            int P3=dist[LCA(b,c)];
            if(P1>=P2 && P1>=P3){maxn=max(maxn,dst(LCA(a,b),c));}
            else if(P2>=P1 && P2>=P3){maxn=max(maxn,dst(LCA(a,c),c));}
            else if(P3>=P1 && P3>=P2){maxn=max(maxn,dst(LCA(b,c),c));}
        }while(next_permutation(d,d+3));
        cout<<maxn+1<<endl;
    }
    return 0;
}