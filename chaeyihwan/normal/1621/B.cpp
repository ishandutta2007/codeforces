#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

ll l[100002], r[100002], c[100002];

ll cost(int a, int b)
{
    if(a == b) return c[a];
    else return c[a] + c[b];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    c[0] = 1e11;
    l[0] = 1e11;
    r[0] = -1e11;
    while(t--){
        int n; cin >> n;
        cin >> l[1] >> r[1] >> c[1];

        int a = 1, b = 1, k = 1;
        cout << c[1] << "\n";
        for(int i=2;i<=n;i++)
        {
            cin >> l[i] >> r[i] >> c[i];
            if(l[i] == l[a] && r[i] == r[b])
            {
                if(c[k] > c[i]) k = i;
            }
            else if(l[i] <= l[a] && r[i] >= r[b])
            {
                k = i;
            }

            if(l[i] < l[a]) a = i;
            if(l[i] == l[a] && c[a] > c[i]) a = i;
            if(r[i] > r[b]) b = i;
            if(r[i] == r[b] && c[b] > c[i]) b = i;

            if(l[k] > l[a] || r[k] < r[b]) k = 0;
            if(l[k] < l[a] || r[k] > r[b]) cout << c[k] << "\n";
            cout << min(c[a] + c[b], c[k]) << "\n";
        }
    }
}