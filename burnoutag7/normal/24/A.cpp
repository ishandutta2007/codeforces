#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > g[105];

int dfs(int x,int p){
    if(x==1&&p!=-1){
        return 0;
    }
    int res=114514;
    for(int i=0;i<g[x].size();i++){
        int &y=g[x][i].first,&z=g[x][i].second;
        if(y!=p){
            res=min(res,dfs(y,x)+z);
        }
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,0));
        g[b].push_back(make_pair(a,c));
    }
    cout<<dfs(1,-1)<<endl;

    return 0;
}