#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int A[n];
    int B[n];
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (A[i] == 1) a = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
        if (B[i] == 1) b = i;
    }
    bool xec =  true;
    for (int i = 0; i < n - 1; ++i) {
        if (A[a] != B[b]) xec = false;
        a = (a + 1)%n;
        b = (b + 1)%n;
        if (A[a] == 0) a = (a + 1)%n;
        if (B[b] == 0) b = (b + 1)%n;
    }
    if (xec) cout << "YES" << endl;
    else cout << "NO" << endl;
}