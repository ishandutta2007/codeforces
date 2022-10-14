#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int cnt[MN];
int n;
bool work(int time){
    ll excesstasks=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]<=time){
            excesstasks-=(time-cnt[i])/2;
        }
        else{
            excesstasks+=cnt[i]-time;
        }
    }
    return excesstasks<=0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int m,a;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cnt[i]=0;
        for(int i=1;i<=m;i++){
            cin>>a;
            cnt[a]++;
        }
        int lo=1,hi=m;
        while(lo!=hi){
            int mid=(lo+hi)/2;
            if(work(mid))hi=mid;
            else lo=mid+1;
        }
        printf("%d\n",lo);
    }
    return 0;
}