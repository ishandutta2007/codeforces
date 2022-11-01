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
        string s;
        cin >> s;
        ll res=0;
        map<int,ll> m;
        m[0]=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int a=(s[i]-'0');
            a--;
            sum+=a;
            res+=(m[sum]++);
        }
        cout << res << "\n";
    }
    return 0;
}