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
        int m=9;
        for(char c:s) m=min(m,c-'0');
        if(s.size()==2) cout << s[1] << "\n";
        else cout << m << "\n";
    }
    return 0;
}