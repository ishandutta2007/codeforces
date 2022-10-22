#include <bits/stdc++.h>

using namespace std;
using li = long long;

const int N = 2e5 + 5;

vector <int> divs[N];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j += i)
            divs[j].push_back(i);

    int t;
    cin >> t;

    while(t--)
    {
        int l, r;
        cin >> l >> r;

        li ans = 0;

        for(int i = l; i <= r; i++)
        {
            int k = 0;

            for(auto x:divs[i])
                if(x >= l && x < i)
                    k++;

            ans += k * 1ll * (k - 1) / 2;

            if(i % 6 == 0 && i / 2 >= l)
                ans++;

            if(i % 15 == 0 && 2 * i / 5 >= l)
                ans++;
        }

//        cout << ans << "\n";

        cout << (r - l + 1) * 1ll * (r - l) * (r - l - 1) / 6 - ans << "\n";
    }
}