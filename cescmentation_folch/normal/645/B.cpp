#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ll n, k;
    cin >> n >> k;
    k = min(k, n/2);
    ll res = 0;
    ll tt = n - 2;
    for (int i = 0; i < k; ++i) {
        res +=  2*tt + 1;
        tt -= 2;
    }
    cout << res << endl;
}