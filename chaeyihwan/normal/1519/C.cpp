#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll u[200002], s[200002];
vector<ll> U[200002];
vector<int> big;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> u[i];
        for(int i=1;i<=n;i++) cin >> s[i];
        for(int i=1;i<=n;i++) U[i].clear();
        big.clear();

        for(int i=1;i<=n;i++)
        {
            U[u[i]].push_back(s[i]);
        }

        for(int i=1;i<=n;i++)
        {
            sort(U[i].rbegin(), U[i].rend());
            int m = U[i].size();
            for(int j=1;j<m;j++)
            {
                U[i][j] += U[i][j-1];
            }

            if(m*m > n) big.push_back(i);
        }
        int i;
        for(i=1;i*i<=n;i++)
        {
            ll sum = 0;
            for(int j=1;j<=n;j++)
            {
                int m = U[j].size();
                if(m/i != 0) sum += U[j][(m/i)*i-1];
            }

            cout << sum << " ";
        }
        for(;i<=n;i++)
        {
            ll sum = 0;
            for(int j : big)
            {
                int m = U[j].size();
                if(m/i != 0) sum += U[j][(m/i)*i-1];
            }

            cout << sum << " ";
        }

        cout << "\n";
    }
}