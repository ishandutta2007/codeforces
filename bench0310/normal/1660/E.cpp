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
        int c=0;
        vector<int> cnt(n,0);
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<n;j++)
            {
                int a=(s[j]-'0');
                c+=a;
                cnt[(j-i+n)%n]+=a;
            }
        }
        int res=n*n;
        for(int i=0;i<n;i++)
        {
            int o=(c-cnt[i]);
            res=min(res,n-cnt[i]+o);
        }
        cout << res << "\n";
    }
    return 0;
}