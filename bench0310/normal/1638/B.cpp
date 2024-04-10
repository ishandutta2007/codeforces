#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v[2];
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            v[a&1].push_back(a);
        }
        if(ranges::is_sorted(v[0])&&ranges::is_sorted(v[1])) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}