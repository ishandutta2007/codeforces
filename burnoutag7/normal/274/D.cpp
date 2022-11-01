#include<bits/stdc++.h>
using namespace std;

int n,m,nds;
vector<int> g[200005];
int ed[200005],tp;

void dfs(int x){
    ed[x]=-1;
    for(int &y:g[x]){
        if(ed[y]==-1){
            cout<<-1<<endl;
            exit(0);
        }
        if(!ed[y])dfs(y);
    }
    ed[x]=++tp;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    nds=m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        vector<pair<int,int>> v;
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]!=-1)v.emplace_back(a[i][j],j);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(i&&v[i].first!=v[i-1].first)nds++;
            g[nds].push_back(v[i].second);
            g[v[i].second].push_back(nds+1);
        }
        nds+=2;
    }
    for(int i=0;i<m;i++)if(!ed[i])dfs(i);
    vector<int> v(m);
    iota(v.begin(),v.end(),0);
    sort(v.begin(),v.end(),[](const int &a,const int &b){
        return ed[a]>ed[b];
    });
    for(int &x:v)cout<<x+1<<' ';
    cout<<endl;

    return 0;
}