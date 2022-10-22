#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[200002], l[200002], r[200002];
bool p[1000002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int i=2;i<=1000000;i++) p[i] = true;
    for(int i=2;i<=1000000;i++)
    {
        if(!p[i]) continue;
        for(int j=2*i;j<=1000000;j+=i) p[j] = false;
    }
    while(t--){
        int n, e; cin >> n >> e;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) l[i] = r[i] = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i] == 1) l[i]++;
            else l[i] = 0;
            if(i+e <= n) l[i+e] += l[i];
        }
        for(int i=n;i>=1;i--)
        {
            if(a[i] == 1) r[i]++;
            else r[i] = 0;
            if(i-e > 0) r[i-e] += r[i];
        }

        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(p[a[i]])
            {
                ll L = 0, R = 0;
                if(i > e) L = l[i-e];
                if(i + e <= n) R = r[i+e];
                ans += (L+1) * (R+1) - 1;
            }
        }
        cout << ans << "\n";
    }
}