#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    long long arr[n+1];
    for(long long i = 1; i<=n; i++){
        long long a; cin >> a;
        arr[i] = __builtin_popcountll(a);
    }
    long long prefix[n+1];
    prefix[0] = 0;
    for(long long i = 1; i<=n; i++) prefix[i] = prefix[i-1]+arr[i];
    long long cnt[2] = {0};
    cnt[0]++;
    long long ans = 0;
    for(long long i = 1; i<=n; i++){
        ans += cnt[prefix[i]%2];
        cnt[prefix[i]%2]++;
    }
    for(long long i = 1; i<=n; i++){
        long long mx = arr[i];
        for(long long j = i; j<= min(i+64, n); j++){
            mx = max(mx, arr[j]);
            if((prefix[j]-prefix[i-1])%2 == 0 && (prefix[j]-prefix[i-1]) < 2*mx) ans--;
        }
    }
    cout << ans << endl;
}