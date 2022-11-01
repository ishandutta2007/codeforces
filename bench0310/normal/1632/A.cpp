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
        if(n==1||(n==2&&s[0]!=s[1])) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}