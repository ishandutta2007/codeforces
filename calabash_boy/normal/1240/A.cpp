#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 200000 + 100;
ll A[maxn];
ll x,a,y,b;
ll k;
ll weight[maxn];
ll need[maxn];
bool check(int n){
    for (ll i=1;i<=n;i++)weight[i] = 0;
    for (ll i = a;i <=n;i+=a){
        weight[i] += x;
    }
    for (ll i=b;i<=n;i+=b){
        weight[i] += y;
    }
    sort(weight+1,weight + n+1);
    reverse(weight+1,weight+n+1);
    ll sum = 0;
    for (ll i=1;i<=n;i++){
        sum += weight[i] * A[i] / 100;
    }
    return sum >= k;
}
int main(){
    ll T;
    cin>>T;
    while (T--){
        ll n;
        cin>>n;
        for (ll i=1;i<=n;i++){
            cin>>A[i];
        }
        sort(A+1,A+n+1);
        reverse(A+1,A+n+1);
        cin>>x>>a;
        cin>>y>>b;
        cin>>k;
        ll l = 1;
        ll r = n;
        while (r-l > 1){
            ll mid = l + r >> 1;
            if (check(mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        int ans = -1;
        for (int i=r;i>=l;i--){
            if (check(i)){
                ans = i;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}