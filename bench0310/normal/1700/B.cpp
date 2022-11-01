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
        string res;
        if(s[0]<'9')
        {
            for(int i=0;i<n;i++) res+=('9'-(s[i]-'0'));
        }
        else
        {
            int c=0;
            for(int i=n-1;i>=0;i--)
            {
                int a=1;
                int b=(s[i]-'0')+c;
                c=(b>a);
                if(b>a) a+=10;
                res+=('0'+(a-b));
            }
            ranges::reverse(res);
        }
        cout << res << "\n";
    }
    return 0;
}