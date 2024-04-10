#include <iostream>
using namespace std;
    
int a[200005], b[200005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        if(v < 0) a[i] = 1;
        else a[i] = 0;
    }
    for(int i=1; i<n; i++) a[i] += a[i-1];
    // calculate how many a[j] with j < i is odd
    b[0] = 0;
    long long even = 0, odd = 0;
    for(int i=1; i<=n; i++) b[i] = (b[i-1] + a[i-1] % 2);
    for(int i=0; i<=n; i++) {
        if(a[i] % 2) {
            // odd
            even += b[i];
            odd += (i-b[i]);
        } else {
            odd += b[i];
            even += (i-b[i]);
        }
    }
    cout << odd << ' ' << even << endl;
}