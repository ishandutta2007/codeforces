#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 1010;

int have[N];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    have[0] = 1;
    int cur = 0;
    for (int i=1; i<=n*n+1; ++i) {
        cur = (cur+i)%n;
        have[cur] = 1;
        //cerr << " " << cur;
    }
    //cerr << endl;
    int hc = 0;
    for (int i=0; i<n; ++i) {
        hc += have[i];
        //if (!have[i]) //cerr << " MISSING " << i << endl;
    }
    cout << (hc == n ? "YES" : "NO") << endl;
    return 0;
}