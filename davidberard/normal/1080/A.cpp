#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll r = n*2;
    ll g = n*5;
    ll b = n*8;
    ll amt = (r+k-1)/k + (g+k-1)/k + (b+k-1)/k;
    cout << amt << endl;
    return 0;
}