#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    set<int> s;
    bool ok=1;
    while(n)
    {
        int d=(n%m);
        if(s.find(d)!=s.end()) ok=0;
        s.insert(d);
        n/=m;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}