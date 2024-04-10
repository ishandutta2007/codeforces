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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        s="$"+s;
        int c=0;
        int res=n;
        for(int i=1;i<k;i++) c+=(s[i]=='B');
        for(int i=k;i<=n;i++)
        {
            c+=(s[i]=='B');
            res=min(res,k-c);
            c-=(s[i-k+1]=='B');
        }
        cout << res << "\n";
    }
    return 0;
}