//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> g[2000005];
bool win;

pair<int,int> dfs(int x,int p){
    pair<int,int> c(0,0);
    for(int y:g[x])if(y!=p){
        pair<int,int> p=dfs(y,x);
        c.first+=p.second;
        c.second+=p.first;
    }
    win|=c.first&&g[x].size()>=3;
    win|=c.first>=2||c.second>=2;
    c.first=c.first||g[x].size()>=3;
    c.second=!!c.second;
    return c;
}

void mian(){
    cin>>n;
    for(int i=1;!g[i].empty();i++)g[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    m=n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='W'){
            g[i].emplace_back(m+1);
            g[m+1].emplace_back(i);
            g[m+1].emplace_back(m+2);
            g[m+2].emplace_back(m+1);
            g[m+1].emplace_back(m+3);
            g[m+3].emplace_back(m+1);
            m+=3;
        }
    }
    win=false;
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        if(g[i].size()>=4)win=true;
        int cnt=0;
        for(int x:g[i]){
            cnt+=g[x].size()>=2;
        }
        if(cnt>=2&&g[i].size()>=3)win=true;
    }
    cout<<(win?"White\n":"Draw\n");
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}