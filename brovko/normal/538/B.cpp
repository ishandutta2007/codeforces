#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> ans(10);

    int y = 1;

    while(n > 0)
    {
        int c = n % 10;

        for(int i = 0; i < c; i++)
            ans[i] += y;

        y *= 10;
        n /= 10;
    }

    while(ans.back() == 0)
        ans.pop_back();

    cout << ans.size() << "\n";

    for(auto x:ans)
        cout << x << ' ';
}