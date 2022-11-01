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
        for(char c:s)
        {
            if(c=='U'||c=='D') cout << char('D'^'U'^c);
            else cout << c;
        }
        cout << "\n";
    }
    return 0;
}