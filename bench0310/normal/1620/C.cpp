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
        ll x;
        cin >> n >> k >> x;
        x--;
        string s;
        cin >> s;
        string res;
        int r=n-1;
        while(r>=0)
        {
            if(s[r]=='a')
            {
                res+='a';
                r--;
                continue;
            }
            int l=r;
            while(l-1>=0&&s[l-1]=='*') l--;
            int lim=(r-l+1)*k;
            int c=(x%(lim+1));
            x/=(lim+1);
            res+=string(c,'b');
            r=l-1;
        }
        ranges::reverse(res);
        cout << res << "\n";
    }
    return 0;
}