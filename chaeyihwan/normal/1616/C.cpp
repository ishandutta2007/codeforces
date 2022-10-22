#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int A[102];
int cnt[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> A[i];
        int ans = n - 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int tmp = 0;
                for(int x=1;x<=n;x++)
                {
                    if((j-i) * A[x] == (A[j]-A[i]) * (x-i) + A[i] * (j-i)) tmp++;
                }
                ans = min(ans, n - tmp);
            }
        }
        cout << ans << "\n";
    }
}