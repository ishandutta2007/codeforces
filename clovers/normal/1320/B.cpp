#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,k,a[N];
vector<int> v[N],G[N];

void init(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y; scanf("%d%d",&x,&y);
        v[x].push_back(y); G[y].push_back(x);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
}

queue<int> q;
int dis[N];
void bfs(){
    while(!q.empty()) q.pop();
    dis[a[k]]=1; q.push(a[k]);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0;i<(int)G[u].size();i++){
            int to=G[u][i]; if(dis[to]) continue;
            dis[to]=dis[u]+1; q.push(to);
        }
    }
}

void solve(){
    bfs();
    //cout<<dis[5]<<"PPP\n";
    int ans1=0,ans2=0;
    for(int i=1;i<k;i++){
        int cnt=0,mi=10000000,u=a[i];
        for(int j=0;j<(int)v[u].size();j++){
            int to=v[u][j];
            if(dis[to]<mi) mi=dis[to],cnt=1;
            else if(dis[to]==mi) cnt++;
        }
        //cout<<i<<" "<<mi<<" "<<dis[a[i+1]]<<endl;
        if(mi<dis[a[i+1]]) ans1++,ans2++;
        else if(cnt>1) ans2++;
    }
    cout<<ans1<<" "<<ans2<<endl;
}

int main(){
    init(); solve();
    return 0;
}