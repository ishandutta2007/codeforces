#include<bits/stdc++.h>
using namespace std;

int n,k,sum,w[505],nxt[505][10],f[505][15][505];
vector<int> g[505];

void add(int x,string &s,int p,int v){
    w[x]+=v;
    if(p==s.size())return;
    if(nxt[x][s[p]-'0']==-1){
        nxt[x][s[p]-'0']=++n;
        g[x].emplace_back(n);
    }
    add(nxt[x][s[p]-'0'],s,p+1,v);
}

void dfs(int x){
    for(int y:g[x]){
        dfs(y);
        for(int d=0;d<=n;d++){
            vector<int> nf=vector<int>(k+1);
            for(int i=0;i<=k;i++)for(int j=0;i+j<=k;j++){
                nf[i+j]=max(nf[i+j],f[x][i][d]+f[y][j][d+1]);
            }
            for(int i=0;i<=k;i++)f[x][i][d]=nf[i];
        }
    }
    for(int j=0;j<=k;j++){
        for(int i=1;i<=n;i++){
            f[x][j+1][i]=max(f[x][j+1][i],f[x][j][0]+w[x]*i);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(nxt,-1,sizeof(nxt));
    n=1;
    int T;
    cin>>T>>k;
    while(T--){
        string s;
        int m;
        cin>>s>>m;
        w[1]-=m;
        add(1,s,0,m);
        sum+=m*s.size();
    }
    dfs(1);
    cerr<<sum<<' '<<f[1][min(n,k)][0]<<endl;
    cout<<sum-f[1][min(n,k)][0]<<'\n';

    return 0;
}