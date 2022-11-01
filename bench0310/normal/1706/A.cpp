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
        int n,m;
        cin >> n >> m;
        string s(m+1,'B');
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            a=min(a,m-a+1);
            if(s[a]=='B') s[a]='A';
            else s[m-a+1]='A';
        }
        cout << s.substr(1,m) << "\n";
    }
    return 0;
}