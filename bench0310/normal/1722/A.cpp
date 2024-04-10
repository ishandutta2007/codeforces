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
        string s;
        cin >> n >> s;
        ranges::sort(s);
        string o="Timur";
        ranges::sort(o);
        if(s==o) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}