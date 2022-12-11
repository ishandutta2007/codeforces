#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<ll> vi;

vpi U;
vpi D;
vi T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    ll P[n];
    ll act = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> P[i];
        act += abs(P[i] - i - 1);
    }

    T = vi(n);
    for (ll i = 0; i < n; ++i) {
        if (P[i] == i + 1) {
            U.push_back(pi(0, n-i-1));
            T[n-i-1] = abs(P[i] - 1) - abs(n - P[i]);
            D.push_back(pi(n-i, n));
        }
        else if(P[i] < i + 1) {
            U.push_back(pi(0, n-i-1));
            T[n-i-1] = abs(P[i] - 1) - abs(n - P[i]);
            D.push_back(pi(n-i, n-i+P[i]-1));
            U.push_back(pi(n-i+P[i]-1, n));
        }
        else {
            D.push_back(pi(0,P[i]-i-1));
            U.push_back(pi(P[i]-i-1,n-i-1));
            T[n-i-1] = abs(P[i] - 1) - abs(n - P[i]);
            D.push_back(pi(n-i, n));
        }
    }
    sort(U.begin(), U.end());
    sort(D.begin(), D.end());

    vi E(n+1, 0);
    ll mii = 0;
    ll diff = 0;
    ll actdiff = 0;
    ll ui = 0;
    ll di = 0;
    ll ress = 0;
    for (ll i = 0; i < n-1; ++i) {
        E[i] = 0;
        while (ui < U.size() and U[ui].first == i) {
            ++diff;
            E[U[ui].second]--;
            ++ui;
        }
        while (di < D.size() and D[di].first == i) {
            --diff;
            E[D[di].second]++;
            ++di;
        }
        diff += E[i];
        actdiff += T[i];
        actdiff += diff;
        if (actdiff < mii) ress = i + 1;
        mii = min(actdiff, mii);
        diff += E[i + 1];
    }
    cout << act + mii << ' ' << ress << endl;
}