#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[302], U[302];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i=1;i<=m;i++) cin >> a[i];
        for(int i=1;i<=m;i++) U[i] = 0;
        int ans = 0;
        for(int i=1;i<=m;i++)
        {
            int cnt = 0;
            for(int j=1;j<=m;j++) if(a[j] > a[i]) cnt++;
            int S = m - cnt;
            while(U[S]) S--;

            U[S] = 1;
            for(int j=1;j<S;j++) ans += U[j];
        }
        cout << ans << "\n";
    }
}