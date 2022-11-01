#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int> > g[5005];
pair<pair<int,int>,int> q[5005];
int d[5005];
pair<int,int> par[5005];
int f[5005];

void dfs(int x,int p,int cd){
    d[x]=cd;
    for(int i=0;i<g[x].size();i++){
        int &y=g[x][i].first,&z=g[x][i].second;
        if(y!=p){
            dfs(y,x,cd+1);
            par[y]=make_pair(x,z);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(make_pair(b,i));
        g[b].push_back(make_pair(a,i));
        f[i]=1;
    }
    dfs(1,-1,1);
    cin>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        q[i]=make_pair(make_pair(a,b),c);
        if(d[a]>d[b])swap(a,b);
        while(d[b]>d[a]){
            f[par[b].second]=max(f[par[b].second],c);
            b=par[b].first;
        }
        while(b!=a){
            f[par[a].second]=max(f[par[a].second],c);
            a=par[a].first;
            f[par[b].second]=max(f[par[b].second],c);
            b=par[b].first;
        }
    }
    for(int i=1;i<=m;i++){
        bool fl=false;
        int a,b,c;
        a=q[i].first.first;
        b=q[i].first.second;
        c=q[i].second;
        if(d[a]>d[b])swap(a,b);
        while(d[b]>d[a]){
            if(f[par[b].second]==c)fl=true;
            b=par[b].first;
        }
        while(b!=a){
            if(f[par[a].second]==c)fl=true;
            a=par[a].first;
            if(f[par[b].second]==c)fl=true;
            b=par[b].first;
        }
        if(!fl){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=1;i<n;i++){
        cout<<f[i]<<' ';
    }
    cout<<endl;

    return 0;
}