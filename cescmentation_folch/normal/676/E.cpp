#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll P[10] = {(ll)1e9 + 7, (ll)1e9 + 9, 1428571429, 524745797, 797893561, 1778567093, 655193573, 352813543, 0, 0};

int main() {
    srand(time(NULL));
    P[9] = rand()%((ll)1e9) + 1;
    P[8] = rand()%((ll)1e9) + 1;
    ll n, k;
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    ll A[n + 1];
    int tt = 0;
    bool xec = true, xec2 = true;
    for (ll i = 0; i <= n; ++i) {
        string a;
        cin >> a;
        if (i > 0 and a == "?") {
            xec = false;
        }
        else if (i == 0 and a == "?") {
            xec2 = false;
            xec = false;
        }
        else {
            A[i] = stoi(a);
            ++tt;
        }
    }
    if (k == 0 and xec2 and A[0] != 0) {
        cout << "No" << endl;
        return 0;
    }
    else if (k == 0 and xec2) {
         cout << "Yes" << endl;
         return 0;
    }
    else if (!xec2 and k == 0 and tt%2 == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    else if (!xec2 and k == 0) {
        cout << "No" << endl;
        return 0;
    }
    else if (!xec and n%2) {
        cout << "Yes" << endl;
        return 0;
    }
    else if (!xec and n%2 == 0) {
        cout << "No" << endl;
        return 0;
    }
    else {
        for (ll p = 0; p < 10; ++p) {
            ll t = 1;
            ll res = 0;
            for (ll i = 0; i <= n; ++i) {
                res = (res + A[i]*t + abs(k)*P[p])%P[p];
                t = (t*k + abs(k)*P[p])%P[p];
            }
            if (res != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
}