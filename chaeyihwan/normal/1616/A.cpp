#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[102];
int cnt[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=0;i<=100;i++) cnt[i] = 0;
        for(int i=1;i<=n;i++) cnt[abs(a[i])]++;
        int ans = 0;
        ans += min(1, cnt[0]);
        for(int i=1;i<=100;i++) ans += min(2, cnt[i]);
        cout << ans << "\n";
    }
}