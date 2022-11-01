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
        int l,r;
        cin >> l >> r;
        int a=r+1;
        if((l%a)>=(a+1)/2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}