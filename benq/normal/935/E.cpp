#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<double,double> pd;
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
const double PI = 4*atan(1);

string e;
int dp[2][10001][101],mx[10001],P,M; // min, max value
int cur = 0, tot = 0;

int getm(int l, int r) {
    int co = 0;
    FOR(i,l+1,r) {
        if (e[i] == '(') co ++;
        else if (e[i] == ')') co --;
        if (e[i] == '?' && co == 0) return i;
    }
    exit(5);
}

void solve1(int ind, int l, int r) { // less positive
    if (l == r) {
        dp[0][ind][0] = dp[1][ind][0] = e[l]-'0';
        return;
    }
    int x = getm(l,r);
    
    mx[ind] = 1;
    int a = ++cur; solve1(a,l+1,x-1); mx[ind] += mx[a];
    int b = ++cur; solve1(b,x+1,r-1); mx[ind] += mx[b];
    mx[ind] = min(mx[ind],P);
    
    F0R(i,P+1) dp[0][ind][i] = -MOD, dp[1][ind][i] = MOD;
    F0R(i,P+1) if (i <= mx[a]) F0R(j,P+1-i) if (j <= mx[b]) {
        dp[0][ind][i+j] = max(dp[0][ind][i+j],dp[0][a][i]-dp[1][b][j]);
        dp[1][ind][i+j] = min(dp[1][ind][i+j],dp[1][a][i]-dp[0][b][j]);
    }
    F0R(i,P) if (i <= mx[a]) F0R(j,P-i) if (j <= mx[b]) {
        dp[0][ind][i+j+1] = max(dp[0][ind][i+j+1],dp[0][a][i]+dp[0][b][j]);
        dp[1][ind][i+j+1] = min(dp[1][ind][i+j+1],dp[1][a][i]+dp[1][b][j]);
    }
}

void solve2(int ind, int l, int r) { // less negative
    if (l == r) {
        dp[0][ind][0] = dp[1][ind][0] = e[l]-'0';
        return;
    }
    int x = getm(l,r);
    
    mx[ind] = 1;
    int a = ++cur; solve2(a,l+1,x-1); mx[ind] += mx[a];
    int b = ++cur; solve2(b,x+1,r-1); mx[ind] += mx[b];
    mx[ind] = min(mx[ind],M);
    
    F0R(i,M+1) dp[0][ind][i] = -MOD, dp[1][ind][i] = MOD;
    F0R(i,M+1) if (i <= mx[a]) F0R(j,M+1-i) if (j <= mx[b]) {
        dp[0][ind][i+j] = max(dp[0][ind][i+j],dp[0][a][i]+dp[0][b][j]);
        dp[1][ind][i+j] = min(dp[1][ind][i+j],dp[1][a][i]+dp[1][b][j]);
    }
    F0R(i,M) if (i <= mx[a]) F0R(j,M-i) if (j <= mx[b]) {
        dp[0][ind][i+j+1] = max(dp[0][ind][i+j+1],dp[0][a][i]-dp[1][b][j]);
        dp[1][ind][i+j+1] = min(dp[1][ind][i+j+1],dp[1][a][i]-dp[0][b][j]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> e >> P >> M;
    if (P <= M) {
        solve1(0,0,sz(e)-1);
        cout << dp[0][0][P];
    } else {
        solve2(0,0,sz(e)-1);
        cout << dp[0][0][M];
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)