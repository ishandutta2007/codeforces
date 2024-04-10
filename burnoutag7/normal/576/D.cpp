#include<bits/stdc++.h>
using namespace std;

int n,m;
pair<int,pair<int,int>> e[150];
bitset<150> g[150],con[150],cc[150];
int dis[150];

void mul(bitset<150> *a,bitset<150> *b){
    bitset<150> r[150],c[150];
    for(int i=0;i<150;i++)for(int j=0;j<150;j++){
        r[i][j]=a[i][j];
        c[j][i]=b[i][j];
    }
    for(int i=0;i<150;i++)for(int j=0;j<150;j++){
        a[i][j]=(r[i]&c[j]).any();
    }
}

void qpow(int s){
    bitset<150> h[150];
    for(int i=0;i<150;i++)h[i]=g[i],con[i].reset(),con[i][i]=1;
    while(s){
        if(s&1){
            mul(con,h);
        }
        mul(h,h);
        s>>=1;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>e[i].second.first>>e[i].second.second>>e[i].first;
        e[i].second.first--;e[i].second.second--;
    }
    sort(e,e+m);
    int ans=2e9;
    for(int i=0;i<n;i++)cc[i][i]=1;
    for(int i=0;i<m;i++){
        qpow(e[i].first-(i==0?0:e[i-1].first));
        mul(cc,con);
        g[e[i].second.first][e[i].second.second]=1;
        memset(dis,0x3f,sizeof(dis));
        queue<int> q;
        for(int j=0;j<n;j++)if(cc[0][j])dis[j]=0,q.push(j);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int y=0;y<n;y++)if(g[x][y]&&dis[y]==0x3f3f3f3f){
                dis[y]=dis[x]+1;
                q.push(y);
            }
        }
        if(dis[n-1]!=0x3f3f3f3f)ans=min(ans,dis[n-1]+e[i].first);
    }
    if(ans!=2e9)cout<<ans<<endl;
    else cout<<"Impossible"<<endl;

    return 0;
}