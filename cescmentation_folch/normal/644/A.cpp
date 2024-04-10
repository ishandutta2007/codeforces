#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    
    vvi M(a, vi(b, 0));
    int senars = (a*b + 1)/2;
    int parells = a*b/2;
    
    if (senars < (n + 1)/2) {
        cout << -1 << endl;
        return 0;
    }
    
    int s = 1;
    int p = 2;
    
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            int k = 0;
            if (s <= n and (i + j)%2 == 0) {
                k = s;
                s += 2;
            }
            else if (p <= n and (i + j)%2 == 1) {
                k = p;
                p += 2;
            }
            if (j) cout << ' ';
            cout << k;
        }
        cout << endl;
    }
}