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
        string s;
        cin >> n >> s;
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=(s[i]-'0');
            res+=(i!=n-1&&s[i]!='0');
        }
        cout << res << "\n";
    }
    return 0;
}