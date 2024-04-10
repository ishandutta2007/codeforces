#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int n, dp[2001][715][9], nex;
map<vi,int> revex;
int num[715], rem[715][9], ad[715][9];
vi TMP[715];
pi p[2000];

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        cin >> p[i].f >> p[i].s;
        p[i].f --, p[i].s --;
    }
}

vi tmp(9);

void gen(int cur, int sum) {
    if (sum > 4) return;
    if (cur == 9) {
        revex[tmp] = nex;
        num[nex] = sum;
        TMP[nex] = tmp;
        nex ++;
        return;
    }
    F0R(i,5) {
        tmp[cur] += i;
        sum += i;
        gen(cur+1,sum);
        tmp[cur] -= i;
        sum -= i;
    }
    while (tmp.back() == cur) tmp.pop_back();
}

int main() {
    init();
    gen(0,0);
    F0R(i,715) {
        F0R(j,9) {
            vi z = TMP[i];
            z[j] = 0;
            rem[i][j] = revex[z];
        }
        if (num[i] < 4) F0R(j,9) {
            vi z = TMP[i];
            z[j]++;
            ad[i][j] = revex[z];
        }
    }
    F0R(i,n+1) F0R(j,715) F0R(k,9) dp[i][j][k] = MOD;
    dp[0][0][0] = 0;
    
    F0R(i,n+1) {
        F0Rd(j,715) {
            F0R(k,8) dp[i][j][k+1] = min(dp[i][j][k+1],dp[i][j][k]+1);
            FORd(k,1,9) dp[i][j][k-1] = min(dp[i][j][k-1],dp[i][j][k]+1);
            
            // if (dp[i][j][0] != MOD) cout << "AH " << dp[i][j][0] << "\n";
            F0R(k,9) if (dp[i][j][k] != MOD) // remove
                dp[i][rem[j][k]][k] = min(dp[i][rem[j][k]][k],dp[i][j][k]+num[j]-num[rem[j][k]]);
                
            if (i != n && num[j] < 4) 
                dp[i+1][ad[j][p[i].s]][p[i].f] = min(dp[i+1][ad[j][p[i].s]][p[i].f],dp[i][j][p[i].f]+1);
        }
        // cout << i << " " << dp[i][0][0] << " " << dp[i][0][2] << "\n";
    }
    int ans = MOD;
    F0R(i,9) ans = min(ans,dp[n][0][i]);
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)