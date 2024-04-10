#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int> > g[100005];
int zd[100005];
int bd[100005];
int zp[100005];
int bp[100005];
pair<int,int> par[100005];
set<int> s,ns;

void bfs(int v,int d[],int p[],bool f){
    bool ok[10]={0};
    ok[0]=true;
    if(!f)fill(ok+1,ok+10,true);
    fill(d,d+n,1e9);
    d[v]=0;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int v=q.front();q.pop();
        for(int i=0;i<g[v].size();i++){
            pair<int,int> u=g[v][i];
            if(ok[u.second]&&d[v]+1<d[u.first]){
                d[u.first]=d[v]+1;
                p[u.first]=v;
                q.push(u.first);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    bfs(n-1,zd,zp,true);
    bfs(0,bd,bp,false);
    int rl=1e9;
    for(int i=0;i<n;i++){
        if(i==n-1||zd[i]<1e9){
            if(bd[i]<rl)rl=bd[i];
        }
    }
    fill(par,par+n,make_pair(1e9,0));
    for(int i=0;i<n;i++){
        if(i==n-1||zd[i]<1e9){
            if(bd[i]==rl){
                par[i]=make_pair(zd[i],i);
                s.insert(i);
            }
        }
    }
    for(int i=0;i<rl;i++){
        ns.clear();
        int bt=10;
        for(set<int>::iterator it=s.begin();it!=s.end();it++){
            for(int j=0;j<g[*it].size();j++){
                pair<int,int> u=g[*it][j];
                if(bd[*it]-1!=bd[u.first])continue;
                if(u.second<bt){
                    bt=u.second;
                    ns.clear();
                }
                if(u.second==bt){
                    if(ns.find(u.first)!=ns.end()){
                        par[u.first]=min(par[u.first],make_pair(par[*it].first,*it));
                    }else{
                        ns.insert(u.first);
                        par[u.first]=make_pair(par[*it].first,*it);
                    }
                }
            }
        }
        cout<<bt;
        s=ns;
    }
    if(rl==0)cout<<0;
    cout<<endl;
    int tl=rl+par[0].first;
    cout<<tl+1<<endl;
    int v=0;
    for(int i=0;i<rl;i++){
        cout<<v<<' ';
        v=par[v].second;
    }
    for(int i=0;i<tl-rl;i++){
        cout<<v<<' ';
        v=zp[v];
    }
    cout<<v<<endl;

    return 0;
}