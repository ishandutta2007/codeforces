//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 105
#define MOD 1000000007

int n;
int arr[MAXN];

int search_max_index(int l, int r) {
    int m = 0;
    for(int i=l; i<=r; i++) {
        m = max(m, arr[i]);
    }
    for(int i=l; i<=r; i++) {
        if(arr[i]==m) return i;
    }
}

int find(int i) {
    int d = 0;
    int l = 0;
    int r = n-1;
    while(l<=r) {
        int ind = search_max_index(l, r);
        if(ind==i) return d;
        if(ind > i) {
            r = ind - 1;
            d += 1;
        }
        if(ind < i) {
            l = ind + 1;
            d += 1;
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n;
    forn(i, n) cin >> arr[i];
    int depth[n];
    forn(i, n) depth[i] = find(i);
    forn(i, n) cout << depth[i] << " ";
    cout << endl;
}
    return 0;
}