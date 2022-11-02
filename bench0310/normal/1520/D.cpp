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
        map<int,int> m;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            m[a-i]++;
        }
        ll res=0;
        for(auto [a,c]:m) res+=(ll(c)*(c-1)/2);
        cout << res << "\n";
    }
    return 0;
}