 
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;


int main() { FAST
    int r, n;
    cin >> r >> n;
    vi x;
    vi y;
    vi t;
    x.pb(1);
    y.pb(1);
    t.pb(0);
    
    for (int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        t.pb(a);
        x.pb(b);
        y.pb(c);
    }
    
    vi best;
    int out = 0;
    best.pb(0);
    for (int i = 1; i <= n; i++){
        int curr = -n;
        for (int j = max(0, i - 2000); j < i; j++){
            int xdiff = abs(x[i] - x[j]);
            int ydiff = abs(y[i] - y[j]);
            int tdiff = (t[i] - t[j]);
            
            if (xdiff + ydiff <= tdiff){
                //cout << j << ' ' << best[j] << '\n';
                curr = max(curr, best[j] + 1);
            }
        }
        out = max(out, curr);
        best.pb(curr);
        //cout << i << ' ' << curr << '\n' << '\n';;
    }
    cout << out;
}