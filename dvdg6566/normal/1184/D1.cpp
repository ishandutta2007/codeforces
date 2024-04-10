#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m, t; cin >> n >> k >> m >> t;
    int s = 1, e = n;
    FOR(j,0,t-1){
        int x, i; cin >> x >> i;
        if (x == 1){
            int y = k-s+1;
            if (i <= y) --s;
            else ++e;
        }else{
            int y = k-s+1;
            if (i < y) s += i;
            else e = s+i-1;
        }
        cout << e-s+1 << ' ' << k-s+1 << '\n';
    }
}