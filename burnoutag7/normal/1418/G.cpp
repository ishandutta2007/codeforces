#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock().now().time_since_epoch().count());
__int128_t rng128(){return (__int128_t)rng64()<<64|rng64();}

__int128_t hsv[500005][3],pre[500005];
int n,a[500005],c[500005],cc[500005];
long long ans;
map<__int128_t,int> mp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        while((hsv[i][0]^hsv[i][1])==0){
            hsv[i][0]=rng128();
            hsv[i][1]=rng128();
            hsv[i][2]=hsv[i][0]^hsv[i][1];
        }
    }
    mp[0]++;
    for(int l=1,r=1;r<=n;r++){
        cin>>a[r];
        pre[r]=pre[r-1]^hsv[a[r]][(++c[a[r]])%3];
        cc[a[r]]++;
        while(cc[a[r]]>3){
            cc[a[l]]--;
            mp[pre[l-1]]--;
            l++;
        }
        ans+=mp[pre[r]]++;
    }
    cout<<ans<<endl;

    return 0;
}