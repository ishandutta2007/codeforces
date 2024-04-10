#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

ll a[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];

        if(n == 3)
        {
            if(a[2]%2)
            {
                cout << "-1\n";
                continue;
            }

            cout << a[2]/2 << "\n";
            continue;
        }

        bool flag = false;
        for(int i=2;i<n;i++) if(a[i] > 1) flag = true;
        if(!flag)
        {
            cout << "-1\n";
            continue;
        }

        ll S = 0;
        for(int i=2;i<n;i++) S += a[i] + a[i]%2;

        cout << S/2 << "\n";
    }
}