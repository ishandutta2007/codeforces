#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        ll x;
        cin >> x;
        ll pot = 1;
        int cont = 0;
        while (pot <= x) {
            ++cont;
            pot *= 2;
        }

        --pot;
        if (x == pot) {
            ll k = x;
            for (int i = 2; i < 50; ++i) {
                if (x%i == 0) {
                    k = i;
                    break;
                }
            }
            cout << x/k << '\n';
        }
        else cout << pot << '\n';
    }

}