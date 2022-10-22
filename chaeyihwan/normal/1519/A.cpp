#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll r, b, d; cin >> r >> b >> d;
        if(r > b * (1 + d) || b > r * (1 + d)) cout << "NO\n";
        else cout << "YES\n";
    }
}