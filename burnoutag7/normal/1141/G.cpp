#include<bits/stdc++.h>
using namespace std;

int n,k,d[200005],e[200005],cs;
vector<pair<int,int>> g[200005];

void dfs(int x,int p,int pc){
    int c=0;
    for(auto &[y,z]:g[x])if(y!=p){
        c++;
        c+=c==pc;
        e[z]=c;
        dfs(y,x,c);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b,i);
        g[b].emplace_back(a,i);
        d[a]++;
        d[b]++;
    }
    sort(d+1,d+n+1);
    dfs(1,-1,-1);
    cout<<(cs=d[n-k])<<'\n';
    for(int i=1;i<n;i++)cout<<min(cs,e[i])<<' ';

    return 0;
}