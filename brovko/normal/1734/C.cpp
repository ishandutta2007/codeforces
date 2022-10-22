#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int N = 1e6 + 5;

vector <int> dv[N];
bool used[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j += i)
            dv[j].pb(i);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        li ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                for(auto d:dv[i + 1])
                    if(!used[d])
                    {
                        ans += d;
                        break;
                    }
            }
            else
            {
                for(auto to:dv[i + 1])
                    used[to] = 1;
            }
        }

        for(int i = 0; i <= n; i++)
            used[i] = 0;

        cout << ans << "\n";
    }
}