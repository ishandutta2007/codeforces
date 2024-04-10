#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=100000;
int aa[MAXN],bb[MAXN];
int ac[MAXN+1],bc[MAXN+1];
template <typename Callback>
int bsta(int low, int high, Callback callback) {
    while(low+1<high){
        int mid=(low+high)/2;
        if(callback(mid)){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return high;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>aa[i];
        }
        sort(aa,aa+n);
        for(int i=0;i<n;++i){
            ac[i+1]=ac[i]+aa[i];
        }
        for(int i=0;i<n;++i){
            cin>>bb[i];
        }
        sort(bb,bb+n);
        for(int i=0;i<n;++i){
            bc[i+1]=bc[i]+bb[i];
        }
        int ans=bsta(-1,3*n,[n](int test){
            int drop=(test+n)/4;
            int ascore=ac[n]-ac[drop]+100*test;
            int bscore;
            if (drop>=test){
                int bdrop=drop-test;
                bscore=bc[n]-bc[bdrop];
            }
            else {
                bscore=bc[n]-bc[0];
            }
            return ascore<bscore;
        });
        cout<<ans<<'\n';
    }
}