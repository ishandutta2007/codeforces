#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n;
string s[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    int ans = 0;

    for(int i = 'a'; i <= 'z'; i++)
        for(int j = 'a'; j < i; j++)
        {
            int k = 0;

            for(int x = 0; x < n; x++)
            {
                int F = 1;

                for(auto y:s[x])
                    if(y != i && y != j)
                        F = 0;

                if(F)
                    k += s[x].size();
            }

            ans = max(ans, k);
        }

    cout << ans;
}