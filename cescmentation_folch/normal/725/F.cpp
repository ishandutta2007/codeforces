#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<ll> vll;

struct pila {
    ll a1, b1;
    ll a2, b2;
    ll val;
};

typedef vector<pila> vp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vp V(n);
    ll a = 0;
    ll b = 0;
    priority_queue<pi> Q;
    for (ll i = 0; i < n; ++i) {
        cin >> V[i].a1 >> V[i].b1 >> V[i].a2 >> V[i].b2;
        V[i].val = 0;
        if (V[i].a1 < V[i].b2 and V[i].a2 > V[i].b1) {
//             cerr << "caca" << '\n';
            continue;
        }
        if (V[i].a1 - V[i].b2 <= V[i].a2 - V[i].b1 and V[i].a2 <= V[i].b1) {
//             cerr << "b" << '\n';
            a += V[i].a2;
            b += V[i].b1;
        }
        else if (V[i].a2 - V[i].b1 >= V[i].a1 - V[i].b2 and V[i].a1 >= V[i].b2) {
//             cerr << "a" << '\n';
            a += V[i].a1;
            b += V[i].b2;
        }
        else if (V[i].a1 + V[i].b1 > V[i].a2 + V[i].b2) {
//             cerr << "tots" << '\n';
            Q.push(pi(V[i].a1 + V[i].b1, i));
        }
    }
    while (!Q.empty()) {
        ll i = Q.top().second; Q.pop();
        if (V[i].val) a += V[i].a2;
        else {
            V[i].val = 1;
            a += V[i].a1;
            Q.push(pi(V[i].a2 + V[i].b2, i));
        }
        if (Q.empty()) break;
        i = Q.top().second; Q.pop();
        if (V[i].val) b += V[i].b2;
        else {
            V[i].val = 1;
            b += V[i].b1;
            Q.push(pi(V[i].a2 + V[i].b2, i));
        }
    }
    cout << a - b << '\n';
}