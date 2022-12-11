#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
    //*os_base::sync_with_stdio(false);
   // cin.tie(0);*/
    int n, q;
//     cin >> n >> q;
    scanf("%d %d", &n, &q);
    ll k = 0;
    ll t = 0;
    while (q--) {
        int tt, x;
        scanf("%d", &tt);
        if (tt == 1) {
            scanf("%d", &x);
            k = (k + x + n)%n;
        }
        else {
            if ((t + k)%2) t = (t - 1 + n)%n;
            else t = (t + 1)%n;
        }
    }
    int R[n];
    for (int i = 0; i < n; ++i) {
        if (i%2) R[(i + k - t + 2*n)%n] = i + 1;
        else R[(i + k + t + 2*n)%n] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", R[i]);
//         cout << R[i];
    }
    printf("\n");
//     cout << endl;
}