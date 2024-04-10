#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, k;
        cin >> a>> b >> k;
        cout << (k+1)/2*a-k/2*b << endl;
    }
    return 0;
}