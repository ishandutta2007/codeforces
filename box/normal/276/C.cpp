#include <iostream>
#include <algorithm>
using namespace std;

int psum[200005];
long long aray[200005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> aray[i];
    for(int i=0; i<q; i++) {
        int s, e; cin >> s >> e;
        psum[s]++; psum[e+1]--;
    }
    for(int i=1; i<=n; i++) psum[i] += psum[i-1];
    sort(psum, psum+n+1);
    sort(aray, aray+n+1);
    long long tot = 0;
    for(int i=0; i<=n; i++) tot += psum[i]*aray[i];
    cout << tot << endl;
}