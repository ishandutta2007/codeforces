#include <bits/stdc++.h>
using namespace std;
//!!!!
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
pair<int,int> ar[200005];
void bru(int n) {
    sort(ar+1, ar+n+1);
    rep1(x, n) {
        iter(y, x+1, n+1) {
            rep1(z, n) {
                if(z == x || z == y) continue;
                iter(w, z+1, n+1) {
                    if(w == x || w == y) continue;
                    // if(y == z) continue;
                    // cout << x << ' ' << w << ' ' << y << ' ' << z << ' ' << ar[x].fi + ar[y].fi  << ' ' <<  ar[z].fi + ar[w].fi << endl;
                    if(ar[x].fi + ar[y].fi == ar[z].fi + ar[w].fi) {
                        cout << "YES\n" << ar[x].se << ' ' << ar[y].se << ' ' << ar[z].se << ' ' << ar[w].se << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n" << endl;
}
int cx[100005], cy[100005];
int A[5000006], B[5000006];
void bru2(int n) {
    int cnt=199;
    while(cnt--) {
        shuffle(ar+1, ar+n+1, rng);
        int m = n/2;
        rep1(i, 100000) {
            int x = uniform_int_distribution<int>(1,m)(rng);
            int y = uniform_int_distribution<int>(1,m)(rng);
            cx[i] = x, cy[i] = y;
            if(x == y) continue;
            A[ar[x].fi+ar[y].fi] = x;
            B[ar[x].fi+ar[y].fi] = y;
        }
        rep1(i, 100000) {
            int x = uniform_int_distribution<int>(m+1,n)(rng);
            int y = uniform_int_distribution<int>(m+1,n)(rng);
            if(x == y) continue;
            int d = ar[x].fi+ar[y].fi;
            if(A[d]) {
                cout << "YES" << endl;
                cout << ar[A[d]].se << ' ' << ar[B[d]].se << ' ' << ar[x].se << ' ' << ar[y].se << endl;
                return;
            }
        }
        rep1(i, 100000) {
            int x = cx[i];
            int y = cy[i];
            if(x == y) continue;
            A[ar[x].fi+ar[y].fi] = 0;
            B[ar[x].fi+ar[y].fi] = 0;
        }
    }
    cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int n; cin >> n;
    rep1(i, n) cin >> ar[i].fi, ar[i].se = i;
    shuffle(ar+1, ar+n+1, rng);
    if(n <= 150) bru(n);
    else bru2(n);
    return 0;
}
//rejudge