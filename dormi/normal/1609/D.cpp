#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
pii arr[MN];
pii dsu[MN];
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
int n;
void reset(){
    for(int i=1;i<=n;i++)dsu[i]={i,1};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int d;
    cin>>n>>d;
    for(int i=0;i<d;i++){
        cin>>arr[i].A>>arr[i].B;
    }
    for(int i=0;i<d;i++){
        reset();
        int extra=i+1;
        for(int j=0;j<=i;j++){
            if(uni(arr[j].A,arr[j].B))extra--;
        }
        vector<int> sizes;
        for(int j=1;j<=n;j++)if(find(j)==j){
            sizes.push_back(dsu[j].B);
        }
        sort(sizes.begin(),sizes.end(),greater<>());
        int ans=0;
        for(int j=0;j<=extra;j++){
           ans+=sizes[j];
        }
        printf("%d\n",ans-1);
    }
    return 0;
}