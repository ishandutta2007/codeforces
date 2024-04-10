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
        string s;
        cin >> s;
        int x=0;
        bool ok=1;
        for(char c:s)
        {
            if(c=='A') x++;
            else x--;
            ok&=(x>=0);
        }
        ok&=(s.back()=='B');
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}