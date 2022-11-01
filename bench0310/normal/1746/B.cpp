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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            v[a[i]].push_back(i);
        }
        ranges::reverse(v[0]);
        int res=0;
        while(res<(int)min(v[0].size(),v[1].size())&&v[0][res]>v[1][res]) res++;
        cout << res << "\n";
    }
    return 0;
}