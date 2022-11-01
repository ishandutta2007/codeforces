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
        bool ok=1;
        string opt="rgb";
        for(char c:opt) ok&=(s.find(c)<s.find(toupper(c)));
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}