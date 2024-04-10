#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int x;
    cin >> x;
    bool res=[&]()->bool
    {
        if(s=="ABC") return (x<=1999);
        else if(s=="ARC") return (x<=2799);
        else if(s=="AGC") return (1200<=x);
        assert(0);
        return 0;
    }();
    if(res) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}