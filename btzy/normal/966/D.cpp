#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <vector>
#include <utility>
#include <random>
#include <bitset>
#include <queue>
using namespace std;
typedef long long ll;
int n,m;
//pair<int,int> opencor[100000];
vector<int> adjlist[300000];
bitset<300000> visited;
int precpath[300000];
vector<int> bfs(){
    visited.reset();
    queue<pair<int,int>> q;
    q.emplace(0,-1);
    int ct=0;
    q.emplace(-1,-1);
    bool done=false;
    while(q.size()>1){
        pair<int,int> tmp=q.front();
        q.pop();
        if(tmp.first==-1){
            ++ct;
            q.push(tmp);
            continue;
        }
        if(visited[tmp.first]){
            continue;
        }
        visited[tmp.first]=true;
        precpath[tmp.first]=tmp.second;
        if(tmp.first==n-1){
            done=true;
            break;
        }
        for(int x:adjlist[tmp.first]){
            if(!visited[x]){
                q.emplace(x,tmp.first);

            }
        }
    }
    if(done){
        int tmp=n-1;
        vector<int> ans;
        while(tmp!=-1){
            ans.push_back(tmp);
            tmp=precpath[tmp];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    return vector<int>();
}
bitset<300000> rootflag;
int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    if(adjlist[0].empty()){
        cout<<-1<<'\n';
        return 0;
    }
    vector<int> ans=bfs();
    rootflag.reset();
    for(int x:adjlist[0]){
        rootflag[x]=true;
    }
    if(ans.empty()||ans.size()>5){
        bool done=false;
        for(int x:adjlist[0]){
            for(int y:adjlist[x]){
                if(y!=0&&!rootflag[y]){
                    ans.clear();
                    ans.push_back(0);
                    ans.push_back(x);
                    ans.push_back(y);
                    ans.push_back(0);
                    ans.push_back(n-1);
                    done=true;
                    break;
                }
            }
            if(done)break;
        }
    }
    if(ans.empty()||ans.size()>6){
        bool done=false;
        mt19937_64 rng(123455476);
        shuffle(adjlist[0].begin(),adjlist[0].end(),rng);
        for(int h:adjlist[0]){
            if(adjlist[h].size()>=adjlist[0].size())continue;
            sort(adjlist[h].begin(),adjlist[h].end());
            for(int via:adjlist[h]){
                if(via!=0){
                    for(int x:adjlist[via]){
                        if(x!=0&&x!=h&&!binary_search(adjlist[h].begin(),adjlist[h].end(),x)){
                            ans.clear();
                            ans.push_back(0);
                            ans.push_back(h);
                            ans.push_back(via);
                            ans.push_back(x);
                            ans.push_back(h);
                            ans.push_back(n-1);
                            done=true;
                            break;
                        }
                    }
                    if(done)break;
                }
            }
            if(done)break;
        }
    }
    if(ans.empty()){
        cout<<-1<<'\n';
    }
    else{
        cout<<ans.size()-1<<'\n';
        bool fl=false;
        for(int x:ans){
            if(fl)cout<<' ';
            fl=true;
            cout<<(x+1);
        }
        cout<<'\n';
    }
    return 0;
}