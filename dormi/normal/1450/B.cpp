#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
pii points[101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>points[i].first>>points[i].second;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            bool work=true;
            for(int j=0;j<n&&work;j++){
                if(abs(points[j].first-points[i].first)+abs(points[j].second-points[i].second)>k)work=false;
            }
            if(work)ans=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}