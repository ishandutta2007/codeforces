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
        ll n;
        cin >> n;
        while((n%2)==0) n/=2;
        if(n>1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}