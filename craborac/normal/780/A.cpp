#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        int a;
        cin >> a;
        if (s.find(a) != s.end())
            s.erase(a);
        else
            s.insert(a);
        ans = max(ans, (int)s.size());
    }
    cout << ans << endl;
    return 0;
}