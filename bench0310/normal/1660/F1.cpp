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
        s="$"+s;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int a=0;
            int c=0;
            for(int j=i;j<=n;j++)
            {
                a+=((s[j]=='+')?-1:1);
                if(j>i&&s[j]=='-'&&s[j-1]=='-') c++;
                res+=(a>=0&&(a%3)==0&&(a/3)<=c);
            }
        }
        cout << res << "\n";
    }
    return 0;
}