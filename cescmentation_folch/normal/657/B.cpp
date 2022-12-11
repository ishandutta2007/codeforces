#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll V;
vll R;

void sum(ll x, ll pos) {
    while (x > 0) {
        if (x%2) V[pos]++;
        if (V[pos] > 1) {
            V[pos] %= 2;
            V[pos + 1]++;
        }
        x /= 2;
        pos++;
    }
    while (V[pos] > 1) {
        V[pos] %= 2;
        V[pos + 1]++;
        pos++;
    }
}

void rest(ll x, ll pos) {
    while (x > 0) {
        if (x%2) R[pos]++;
        if (R[pos] > 1) {
            R[pos] %= 2;
            R[pos + 1]++;
        }
        x /= 2;
        pos++;
    }
    while (R[pos] > 1) {
        R[pos] %= 2;
        R[pos + 1]++;
        pos++;
    }
}

bool gran() {
    for (ll i = min((ll)V.size(), (ll)R.size()) - 1; i >= 0; --i) {
        if (V[i] == 1 and R[i] == 0) return true;
        if (V[i] == 0 and R[i] == 1) return false;
    }
    return true;
}

vll T;

void restavectors(vll& A, vll& B) {
//     for (ll i = 0; i < (ll)A.size() - 1; ++i) cerr << A[i] << ' ';
//     cerr << endl;
//     for (ll i = 0; i < (ll)A.size() - 1; ++i) cerr << B[i] << ' ';
//     cerr << endl;
    T = A;
    for (ll i = 0; i < (ll)A.size() - 1; ++i) {
        T[i] -= B[i];
        if (T[i] < 0) {
            B[i + 1] += (-T[i] + 1)/2;
            T[i] = (-T[i])%2;
        }
    }
}

pair<ll, ll> ff() {
    ll k = 0;
    ll pos = -1;
    for (ll i = 0; i < T.size(); ++i) {
//         cerr << T[i] << ' ';
        if (T[i] and pos == -1) pos = i;
        if (pos != -1 and T[i]) {
            if (i - pos > 32) return pair<ll, ll>(-1, -1);
            k += (1ll<<(i - pos));
        }
        if (k > 1e10) return pair<ll, ll>(-1, -1);
    }
    return pair<ll, ll>(k, pos);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ++n;
    V = vll(2*n + 2ll*(ll)log2(k) + 5, 0);
    R = vll(2*n + 2ll*(ll)log2(k) + 5, 0);
    T = vll(2*n + 2ll*(ll)log2(k) + 5, 0);
    vll Q(n);
    for (ll i = 0; i < n; ++i) {
        cin >> Q[i];
        if (Q[i] >= 0) sum(Q[i], i);
        else rest(-Q[i], i);
    }
    bool xec = gran();
    if (xec) restavectors(V, R);
    else restavectors(R, V);
    pair<ll, ll> Z = ff();
    ll poz = Z.second;
    ll kz = Z.first;
    if (xec) kz = -kz;
//     cerr << endl;
//     cerr << poz << ' ' << kz << endl;
    if (poz == -1) {
        cout << 0 << endl;
        return 0;
    }
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        if (i > poz) break;
        if (poz - i + (ll)log2(k) < 64 and (abs(Q[i] + (kz*(1ll<<(poz - i)))) <= k) and ((abs(Q[i] + (kz*(1ll<<(poz - i)))) != 0) or i < n - 1)) ++res;
    }
    cout << res << endl;
}