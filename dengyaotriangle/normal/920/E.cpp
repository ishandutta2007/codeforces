#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=200005;

int n,m;
int blk[maxn];
set<int> dl[maxn];
set<int> ds;

inline int  bfs(int u,int s){
    queue<int> q;
    q.push(u);
    int cnt=0;
    ds.erase(u);
    while(!q.empty()){
        cnt++;
        int v=q.front();q.pop();
        //cerr<<v<<endl;
        blk[v]=s;
        vector<int> id;
        for(set<int>::iterator it=ds.begin();it!=ds.end();it++){
            if(dl[v].find(*it)==dl[v].end()){
                id.push_back(*it);
                q.push(*it);
            }
        }
        for(int i=0;i<id.size();i++){
            ds.erase(id[i]);blk[id[i]]=s;
        }
    }
    //cerr<<endl;
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        dl[u].insert(v);
        dl[v].insert(u);
    }
    for(int i=1;i<=n;i++)ds.insert(i);
    int cnt=0;vector<int> e;
    for(int i=1;i<=n;i++){
        if(blk[i]==0){
            e.push_back(bfs(i,++cnt));
        }
    }
    cout<<cnt<<'\n';
    sort(e.begin(),e.end());
    for(int i=0;i<e.size();i++)cout<<e[i]<<' ';
    return 0;
}