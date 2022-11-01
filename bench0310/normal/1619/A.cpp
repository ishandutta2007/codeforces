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
        int n=s.size();
        if((n%2)==0&&s.ends_with(s.substr(0,n/2))) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}