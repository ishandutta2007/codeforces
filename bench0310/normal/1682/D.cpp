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
        int c=ranges::count(s,'1');
        if(c>=2&&(c%2)==0)
        {
            cout << "YES\n";
            auto e=[&](int a,int b){cout << a+1 << " " << b+1 << "\n";};
            int p=0;
            while(s[(p-1+n)%n]=='0') p++;
            int l=(p+1)%n;
            while(l!=p)
            {
                e(p,l);
                if(s[l]=='1')
                {
                    l=(l+1)%n;
                    continue;
                }
                int r=l;
                while(s[(r+1)%n]=='0')
                {
                    e(r,(r+1)%n);
                    r=(r+1)%n;
                }
                e(r,(r+1)%n);
                l=(r+2)%n;
            }
        }
        else cout << "NO\n";
    }
    return 0;
}