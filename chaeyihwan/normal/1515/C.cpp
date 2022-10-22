#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll y[100002], M[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m, x; cin >> n >> m >> x;
        priority_queue<pair<ll, int>> pq1, pq2;

        for(int i=1;i<=m;i++)
        {
            pq1.push({0, i});
            y[i] = 0;
        }

        for(int i=1;i<=n;i++)
        {
            ll h; cin >> h;
            pq2.push({h, i});
        }

        for(int i=1;i<=n;i++)
        {
            ll h = pq2.top().first; int I = pq2.top().second;
            pq2.pop();

            ll Y = -pq1.top().first, b = pq1.top().second;
            pq1.pop();
            y[b] += h;
            pq1.push({-y[b], b});

            M[I] = b;
        }
        ll Ma = 0, mi = 2e9;
        for(int i=1;i<=m;i++)
        {
            Ma = max(Ma, y[i]);
            mi = min(mi, y[i]);
        }

        if(Ma - mi > x) cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(int i=1;i<=n;i++) cout << M[i] << " ";
            cout << "\n";
        }
    }
}