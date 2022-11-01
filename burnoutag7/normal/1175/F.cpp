#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock().now().time_since_epoch().count());
__int128_t rng128(){return (__int128_t)rng64()<<64|rng64();}

__int128_t hsv[300005],perm[300005];
int n,a[300005],ans;

void solve(){
    for(int i=1;i<=n;i++)if(a[i]==1){
        set<int> sl,sr;
        sl.insert(1);
        sr.insert(1);
        set<__int128_t> pres;
        pres.insert(hsv[1]);
        __int128_t pre=hsv[1],suf=0;
        for(int l=i-1,r=i+1;r<=n&&sr.find(a[r])==sr.end();r++){
            sr.insert(a[r]);
            suf^=hsv[a[r]];
            for(;l>=1&&sl.find(a[l])==sl.end()&&a[l]<*sr.rbegin();l--){
                sl.insert(a[l]);
                pre^=hsv[a[l]];
                pres.insert(pre);
            }
            ans+=pres.find(perm[*sr.rbegin()]^suf)!=pres.end();
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        hsv[i]=rng128();
        perm[i]=perm[i-1]^hsv[i];
    }
    for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i]==1;
    solve();
    reverse(a+1,a+1+n);
    solve();
    cout<<ans<<endl;

    return 0;
}