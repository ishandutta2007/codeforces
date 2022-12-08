#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
pair<ll, ll> arr[200002];
ll ans;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        n++;
        arr[1] = make_pair(1LL, 1LL);
        for(int i=2; i<=n; i++) scanf("%lld", &arr[i].first);
        for(int i=2; i<=n; i++) scanf("%lld", &arr[i].second);
        sort(arr+1, arr+n+1);

        ans=0;
        for(int i=2; i<=n; i++){
            ll s = arr[i-1].first - arr[i-1].second;
            ll e = arr[i].first - arr[i].second;
            if(s==e && s%2==0){
                ans += arr[i].first - arr[i-1].first;
                continue;
            }
            s/=2, e/=2;
            assert(s <= e);
            ans += e-s;
        }
        printf("%lld\n", ans);
    }
}