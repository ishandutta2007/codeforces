#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;

set<pair<int,int>> s[2];
int n;
int k[maxn],p[maxn][2][2];
vector<pair<bool,pair<int,int>>> chg[maxn];
bool ans[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i]>>p[i][0][0]>>p[i][0][1]>>p[i][1][0]>>p[i][1][1];
    }
    if(p[1][1][0]==0&&p[1][0][0]<=k[1]&&k[1]<=p[1][0][1])s[0].insert({0,1});
    if(p[1][0][0]==0&&p[1][1][0]<=k[1]&&k[1]<=p[1][1][1])s[1].insert({0,1});
    for(int i=2;i<=n;i++){
        bool f[2]={s[0].empty(),s[1].empty()};
        for(int t=0;t<2;t++)if(!f[!t]){
            chg[i].push_back({t,{k[i-1],-i}});
            s[t].insert({k[i-1],i});
        }
        for(int t=0;t<2;t++){
            if(p[i][t][0]>k[i]||p[i][t][1]<k[i]){
                for(auto&u:s[t])chg[i].push_back({t,u});
                s[t].clear();
                continue;
            }
            while(!s[t].empty()){
                if(s[t].begin()->first<p[i][!t][0]){
                    chg[i].push_back({t,*s[t].begin()});
                    s[t].erase(s[t].begin());
                }else if(s[t].rbegin()->first>p[i][!t][1]){
                    chg[i].push_back({t,*s[t].rbegin()});
                    auto it=s[t].end();
                    s[t].erase(--it);
                }else break;
            }
        }
    }
    bool cans=!s[0].empty()||!s[1].empty();
    if(!cans){
        cout<<"No";return 0;
    }
    cout<<"Yes\n";
    bool c=s[0].empty();
    pair<int,int> cur=(c?*s[1].begin():*s[0].begin());
    for(int i=n;i>1;i--){
        ans[i]=c;
        for(int j=chg[i].size()-1;j>=0;j--){
            auto u=chg[i][j];
            if(u.second.second<0){
                s[u.first].erase({u.second.first,-u.second.second});
            }else s[u.first].insert(u.second);
        }
        if(cur.second==i){
            c=!c;
            cur=*s[c].begin();
        }
    }
    ans[1]=c;
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}