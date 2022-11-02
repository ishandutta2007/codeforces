//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

int n,sx[100005],anss;
vector<int> g[100005];
pair<int,int> f[100005][2],ff[100005][2];
int pf[100005],pff[100005];
vector<pair<int,int>> ans;
bool vis[100005];
vector<int> seq;

void dfs(int x,int p,int anc){
    f[x][0]=f[x][1]=make_pair(0,0);
    seq.emplace_back(x);
    pf[x]=0;
    pair<int,int> tmp;
    for(int y:g[x])if(y!=p&&y!=anc){
        dfs(y,x,anc);
        f[x][0].first+=max(f[y][0],f[y][1]).first;
        f[x][0].second+=max(f[y][0],f[y][1]).second;
    }
    for(int y:g[x])if(y!=p&&y!=anc){
        tmp.first=f[x][0].first-max(f[y][0],f[y][1]).first+f[y][0].first+1;
        tmp.second=f[x][0].second-max(f[y][0],f[y][1]).second+f[y][0].second+(sx[x]!=sx[y]);
        if(f[x][1]<tmp){
            f[x][1]=tmp;
            pf[x]=y;
        }
    }
}

void print(int x,int p,int anc,int chs){
    vis[x]=1;
    if(chs&&pf[x]){
        ans.emplace_back(x,pf[x]);
        anss+=sx[x]!=sx[pf[x]];
        print(pf[x],x,anc,0);
        for(int y:g[x])if(y!=p&&y!=anc&&y!=pf[x]&&!vis[y]){
            if(f[y][0]<f[y][1])print(y,x,anc,1);
            else print(y,x,anc,0);
        }
    }else{
        for(int y:g[x])if(y!=p&&y!=anc&&!vis[y]){
            if(f[y][0]<f[y][1])print(y,x,anc,1);
            else print(y,x,anc,0);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<int> deg(n+1);
    for(int i=1;i<=n;i++){
        int f;
        cin>>f>>sx[i];
        g[i].emplace_back(f);
        g[f].emplace_back(i);
        deg[i]++;
        deg[f]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)if(deg[i]==1)q.emplace(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int y:g[x]){
            deg[y]--;
            if(deg[y]==1)q.emplace(y);
        }
    }
    for(int i=1;i<=n;i++)if(deg[i]==2){
        int y1=-1,y2=-1;
        for(int x=i;deg[x]==2;){
            if(y1==-1&&x!=i)y1=x;
            y2=x;
            deg[x]=0;
            for(int y:g[x])if(deg[y]==2){
                x=y;
                break;
            }
        }
        if(y2!=y1){
            seq.clear();
            dfs(i,y1,i);
            for(int x:seq){
                swap(f[x],ff[x]);
                swap(pf[x],pff[x]);
            }
            seq.clear();
            dfs(i,y2,i);
            if(max(f[i][0],f[i][1])<max(ff[i][0],ff[i][1])){
                for(int x:seq){
                    swap(f[x],ff[x]);
                    swap(pf[x],pff[x]);
                }
            }else swap(y1,y2);
            if(f[i][0]>f[i][1])print(i,y1,i,0);
            else print(i,y1,i,1);
        }else{
            dfs(i,i,i);
            if(f[i][0]>f[i][1])print(i,i,i,0);
            else print(i,i,i,1);
        }
    }
    cerr<<"ANS:\n";
    cout<<ans.size()<<' '<<anss<<'\n';
    for(pair<int,int> &p:ans)cout<<p.first<<' '<<p.second<<'\n';

    return 0;
}