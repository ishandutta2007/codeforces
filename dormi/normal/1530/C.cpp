#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        ll a;
        cin>>n;
        vector<ll> aarr,barr;
        for(int i=0;i<n;i++){
            cin>>a;
            aarr.push_back(a);
        }
        for(int i=0;i<n;i++){
            cin>>a;
            barr.push_back(a);
        }
        sort(aarr.begin(),aarr.end(),greater<>());
        sort(barr.begin(),barr.end(),greater<>());
        for(int i=1;i<n;i++){
            aarr[i]+=aarr[i-1];
            barr[i]+=barr[i-1];
        }
        ll lo=0,hi=1e6;
        while(lo!=hi){
            ll mid=(lo+hi)/2;
            ll am=(mid+n)-(mid+n)/4;
            ll fullam=min(am,mid);
            ll apoint=fullam*100+(fullam==am?0:aarr[am-fullam-1]);
            ll arram=min(am,ll(sz(barr)));
            ll bpoint=barr[arram-1];
            if(apoint>=bpoint)hi=mid;
            else lo=mid+1;
        }
        printf("%lli\n",lo);
    }
    return 0;
}