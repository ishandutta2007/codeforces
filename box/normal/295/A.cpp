#include <iostream>
using namespace std;

long long psum[100005];
long long tpsu[100005];

long long l[100005], r[100005], d[100005];

int main() {
    int n, m, k; cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> psum[i];
    for(int i=n; i>=1; i--) psum[i] -= psum[i-1];
    for(int i=1; i<=m; i++) cin >> l[i] >> r[i] >> d[i];
    for(int i=1; i<=k; i++) {
        int L, R; cin >> L >> R;
        tpsu[L]++; tpsu[R+1]--;
    }
    for(int i=1; i<=m; i++) {
        tpsu[i] += tpsu[i-1];
        psum[l[i]] += d[i] * tpsu[i];
        psum[r[i]+1] -= d[i] * tpsu[i];
    }
    for(int i=1; i<=n; i++) {
        psum[i] += psum[i-1];
        if(i != 1) cout << ' ';
        cout << psum[i];
    }
    cout << endl;
}