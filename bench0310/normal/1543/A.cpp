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
        ll a,b;
        cin >> a >> b;
        if(a>b) swap(a,b);
        ll g=b-a;
        ll x=(g!=0?min(a%g,g-a%g):0);
        cout << g << " " << x << "\n";
    }
    return 0;
}