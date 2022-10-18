#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n,t;
int p[maxn];
bool vis[maxn];
vector<int> r[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)if(!vis[i]){
        ++t;
        for(int u=i;!vis[u];u=p[u])vis[u]=1,r[t].push_back(u);
        if(r[t].size()==1){
            r[t].clear();
            t--;
        }
    }
    vector<pair<int,int> > oper;
    for(int i=1;i+1<=t;i+=2){
        oper.push_back({r[i][0],r[i+1][0]});
        for(int t=0;t<2;t++)for(int j=1;j<(int)r[i+t].size();j++){
            oper.push_back({r[i+(!t)][0],r[i+t][j]});
        }
        oper.push_back({r[i][0],r[i+1][0]});
    }
    if(t&1){
        if(r[t].size()==2){
            int id=1;
            while(id==r[t][0]||id==r[t][1])id++;
            oper.push_back({r[t][0],id});
            oper.push_back({r[t][1],id});
            oper.push_back({r[t][0],id});
        }else{
            for(int i=1;i<(int)r[t].size()-1;i++){
                oper.push_back({r[t][0],r[t][i]});
            }
            oper.push_back({r[t][1],r[t].back()});
            oper.push_back({r[t][0],r[t].back()});
            oper.push_back({r[t][0],r[t][1]});
        }
    }
    cout<<oper.size()<<'\n';
    for(auto&x:oper)cout<<x.first<<' '<<x.second<<'\n';
    return 0;
}