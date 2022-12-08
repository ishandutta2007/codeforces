#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n;
ll arr[100002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        for(ll i=1; i<=n; i++){
            scanf("%lld", &arr[i]);
        }

        ll ans = LLONG_MAX;
        priority_queue<ll, vector<ll>, greater<ll> > odd, even;
        ll oddSum = 0, evenSum = 0;
        odd.push(arr[1]), oddSum = arr[1];
        int oddCnt = n, evenCnt = n+1;
        for(int i=2; i<=n; i++){
            if(i%2==1) odd.push(arr[i]), oddSum += arr[i], oddCnt--;
            else even.push(arr[i]), evenSum += arr[i], evenCnt--;
            ans = min(ans, oddSum + odd.top() * (oddCnt-1) + evenSum + even.top() * (evenCnt - 1));
        }
        printf("%lld\n", ans);
    }
}