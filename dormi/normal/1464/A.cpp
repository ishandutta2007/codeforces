#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int am[MN][2];
pii pieces[MN];
bool gone[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)am[i][0]=am[i][1]=0;
        int a,b;
        for(int i=1;i<=m;i++){
            gone[i]=false;
            cin>>a>>b;
            am[a][0]=i,am[b][1]=i;
            pieces[i]={a,b};
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            if(gone[i])continue;
            gone[i]=true;
            if(pieces[i].first==pieces[i].second)continue;
            ans++;
            if(am[pieces[i].first][1]&&am[pieces[i].second][0]){
                int ne=am[pieces[i].second][0];
                bool work=false;
                while(ne!=i&&!work){
                    bool prev=gone[ne];
                    gone[ne]=true;
                    if(!prev)ans++;
                    if(prev||!am[pieces[ne].second][0])work=true;
                    else ne=am[pieces[ne].second][0];
                }
                if(!work)ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}