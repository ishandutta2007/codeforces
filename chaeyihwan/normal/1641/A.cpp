#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;
ll a[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n, x; cin >> n >> x;
        for(int i=1;i<=n;i++) cin >> a[i];
        map<ll, int> cnt;

        sort(a+1, a+n+1);
        for(int i=1;i<=n;i++) cnt[a[i]]++;

        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(cnt[a[i]] && cnt[a[i]*x])
            {
                cnt[a[i]]--;
                cnt[a[i]*x]--;
                ans++;
            }
        }

        cout << n - ans * 2 << "\n";
    }
}