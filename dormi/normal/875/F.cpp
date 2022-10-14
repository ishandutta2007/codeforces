#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
pair<ll,pii> weds[MAXN];
int dsu[MAXN];
int find(int a){
    if(dsu[a]==a)return a;
    return dsu[a]=find(dsu[a]);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return;
    dsu[bp]=ap;
}
bool done[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>weds[i].second.first>>weds[i].second.second>>weds[i].first;
    for(int i=1;i<=n;i++)dsu[i]=i;
    sort(weds,weds+m,greater<>());
    ll ans=0;
    for(int i=0;i<m;i++){
        if(done[weds[i].second.first])swap(weds[i].second.first,weds[i].second.second);
        if(done[weds[i].second.first]){
            if(!done[find(weds[i].second.first)]){
                done[find(weds[i].second.first)]=true;
                ans+=weds[i].first;
                uni(weds[i].second.second,weds[i].second.first);
            }
            else if(!done[find(weds[i].second.second)]){
                done[find(weds[i].second.second)]=true;
                ans+=weds[i].first;
                uni(weds[i].second.first,weds[i].second.second);
            }
        }
        else ans+=weds[i].first,done[weds[i].second.first]=true,uni(weds[i].second.second,weds[i].second.first);
    }
    printf("%lli\n",ans);
    return 0;
}