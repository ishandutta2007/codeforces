#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vll;

ll S[6] = {4,5,6,3,2,1};
ll T[4] = {0, 7, 0, 7};
const ll E = 16;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    char a;
    cin >> n >> a;
    ll k = (n - 1)/4;
    ll t = (n - 1)%4;
    ll e = a - 'a';
    cout << k*E + T[t] + S[e] << '\n';
}