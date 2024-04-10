#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=150001;
unordered_map<int,int> id;
int get(int val){
    if(id.count(val))return id[val];
    int te=sz(id);
    id[val]=te;
    return te;
}
vector<pii> dsu;
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
int arr[MN];
vector<int> pf[MN];
vector<unordered_set<int>> canreach;
unordered_set<int> done;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b;
    cin>>n>>q;
    get(2);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        get(arr[i]);
        ll te=arr[i];
        for(ll j=2;j*j<=te;j++){
            if(te%j==0){
                get(j);
                pf[i].push_back(j);
                while(te%j==0)te/=j;
            }
        }
        if(te>1)pf[i].push_back(te),get(te);
    }
    dsu.resize(sz(id));
    canreach.resize(sz(id));
    for(int i=0;i<sz(dsu);i++)dsu[i]={i,1};
    for(int i=1;i<=n;i++){
        for(auto x:pf[i]){
            uni(get(x),get(arr[i]));
        }
    }
    for(int i=1;i<=n;i++){
        ll te=(arr[i]+1);
        int rt=find(get(arr[i]));
        unordered_set<int> gathering;
        gathering.insert(rt);
        for(ll j=2;j*j<=te;j++){
            if(te%j==0){
                if(id.count(j)){
                    gathering.insert(find(id[j]));
                }
                while(te%j==0)te/=j;
            }
        }
        if(te>1){
            if(id.count(te)){
                gathering.insert(find(id[te]));
            }
        }
        for(auto x:gathering){
            for(auto y:gathering){
                canreach[x].insert(y);
            }
        }
    }
    while(q--){
        cin>>a>>b;
        if(find(get(arr[a]))==find(get(arr[b]))){
            printf("0\n");
            continue;
        }
        if(canreach[find(get(arr[a]))].count(find(get(arr[b])))){
            printf("1\n");
            continue;
        }
        if(canreach[find(get(arr[b]))].count(find(get(arr[a])))){
            printf("1\n");
            continue;
        }
        printf("2\n");
    }
    return 0;
}