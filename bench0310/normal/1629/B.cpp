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
        int l,r,k;
        cin >> l >> r >> k;
        int c=(r-(r/2)-(l-1-(l-1)/2));
        if((l==r&&l>1)||(l<r&&c<=k)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}