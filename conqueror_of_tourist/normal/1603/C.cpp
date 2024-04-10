#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define sq(a) ((a)*(a))
 
#define MOO(i,a,b) for (int i=a; i<b; i++)
#define M00(i,a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define per(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rep(i,a,b) for (int i=a; i<b; i++)
 
#define FOR(i,a,b) for (int i=a; i<b; i++)
#define F0R(i,a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << endl, 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << endl;
#define _<< " _ " <<
 
//#define int long long
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
 
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const ld PI = acos(-1.0);
const ld EPS = 1e-7;
const int MOD = 998244353;

int main() { FAST
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        
        ll out = 0;
        
        vector<pair<ll,ll>> values;
        for (int i = n - 1; i >= 0; i--){
            vector<pair<ll,ll>> new_values;
            values.pb({100001, 1});
            int v = a[i];
            
            for (auto p : values){
                ll limit = p.first;
                //cout << p.first << ' ' << p.second << '\n';
                ll ct = p.second;
                ll amt = 1+((v - 1)/limit);
                out += (((i+1) * ct) % MOD) * (amt - 1);
                out %= MOD;
                
                ll nl = v / amt;
                if (!new_values.empty() && new_values.back().first == nl){
                    new_values[sz(new_values) - 1] = {nl, new_values.back().second + ct};
                } else {
                    new_values.pb({nl, ct});
                }
            }
            values = new_values;
        }
        cout << out << '\n';
    }
}