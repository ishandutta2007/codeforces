 
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
#define _<< " _ " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n, m;
	cin >> n >> m;
    
    vi rx(n,0);
    vi ry(n,0);
    for (int i = 0; i < n; i++){
        cin >> rx[i] >> ry[i];
    }
    
    vi sx(m,0);
    vi sy(m,0);
    for (int i = 0; i < m; i++){
        cin >> sx[i] >> sy[i];
    }
    
    ll MAX = 2000000;
    
    vll cond = vll();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ll dx = max(0, sx[j] - rx[i] + 1);
            ll dy = max(0, sy[j] - ry[i] + 1);
            cond.pb((MAX - dx) * MAX + dy);
        }
    }
    cond.pb(MAX * MAX);
    
    sort(cond.begin(), cond.end());
    ll best = 5 * MAX;
    ll need = 0;
    for (ll res : cond){
        ll dx = MAX - (res / MAX);
        ll dy = res % MAX;
        //cout << dx << " " << dy << "\n";
        ll curr = need + dx;
        best = min(curr, best);
        need = max(need, dy);
    }
    
    cout << best;
}