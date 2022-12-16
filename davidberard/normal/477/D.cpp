#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const int N = 5050;
const int LG = 14;

/*
 * let a[i][j] = min number of "print operations" to print first i chars
 *  where last chunk was length j.
 * and f[i][j] = number of ways to write first i chars where last chunk
 *  was length j.
 *
 * there's two cases, one for when s[i-2j...i-j) <= s[i-j...i) and the other
 *  when >, since we know that the previous number must be smaller. Check
 *  this condition with a suffix array/lcp.
 *
 * below assumes the > case, but if the <= case occurs then k can be <= j.
 *
 * when s[i-j] is '0' then both will be given null values (inf and 0)
 * otherwise, 
 *   a[i][j] = 1 + min over k < j of a[i-j][k]
 *   f[i][j] = sum over k < j of f[i-j][k]
 *
 * this would be n^3 so instead we define
 *   b[i][j] = min over k<=j of a[i][j]
 *   g[i][j] = sum over k<=j of f[i][j]
 */

int b[N][N];
int g[N][N];

int n;
string s;

struct suff_array {
  int L; string s; int i, skip, lvl;
  vector<vi> P; vector<pair<pii,int>> M;
  suff_array(const string &s) : L(s.size()), s(s), P(1, vi(L, 0)), M(L) {
    for (i = 0; i < L-(L==1); i++) P[0][i] = int(s[i]);
    for (skip = 1, lvl = 1; skip < L; skip *= 2, lvl++) {
      P.push_back(vi(L, 0));
      for (int i = 0; i < L; i++)
        M[i] = {{P[lvl-1][i], i+skip<L ? P[lvl-1][i + skip] : -1000}, i};
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
        P[lvl][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ?
            P[lvl][M[i-1].second] : i; } }
  const vi& get_sarray() { return P.back(); }
  //returns len of longest common prefix of s[i...L-1] and s[j...L-1], O(lg L)
  int lcp(int i, int j) {
    int len = 0; if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--)
      if (P[k][i] == P[k][j]) { i += 1 << k; j += 1 << k; len += 1 << k; }
    return len; } 
  int orig(int i) const { // get position in string of of ith sorted value
    return M[i].second;
  }
  int ord(int i) const { // get order of ith string
    return P.back()[i];
  }
}; //! code adapted from the Stanford Team Notebook

suff_array sa("asdf");

int mv[LG][N];

void setup() {
    memset(mv, INF, sizeof mv);
    for (int i=0; i<n-1; ++i) {
        mv[0][i] = sa.lcp(sa.orig(i), sa.orig(i+1));
    }
    for (int l=0; l<LG-1; ++l) {
        for (int i=0; i+(1<<l)<n-1; ++i) {
            mv[l+1][i] = min(mv[l][i], mv[l][i+(1<<l)]);
        }
    }
}

ll get_lcp(int i, int j) { // inclusive
    int a = sa.ord(i);
    int b = sa.ord(j);
    if (a == b) return n-i;
    if (a > b) swap(a, b);
    --b;
    int len = (b-a)+1;
    int lg = 31 - __builtin_clz(len);
    return min(mv[lg][a], mv[lg][b-(1<<lg)+1]);
}

ll get_cost(int i, int j) {
    ll tp = 1;
    ll ans = 0;
    for (int k=j-1; k>=i; --k) {
        ans = (ans + (s[k] == '1' ? tp : 0))%MOD;
        tp = tp*2%MOD;
    }
    return ans;
}

bool leq(int a, int b, int len) {
    if (a < 0) return true;
    int lcp = get_lcp(a, b);
    if (lcp >= len) return true;
    assert(s[lcp+a] != s[lcp+b]);
    return s[lcp+a] < s[lcp+b];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    n = s.size();
    sa = suff_array(s);
    setup();

    for (int i=0; i<N; ++i) {
        g[0][i] = 1;
        b[i][0] = INF;
        b[0][i] = 0;
    }

    for (int i=1; i<=n; ++i) {
        if (i%100 == 0) {
            //////cerr << "! " << i << endl;
        }
        for (int j=1; i-j>=0; ++j) {
            bool can_jump = s[i-j] == '1';
            bool leq_result = leq(i-j*2, i-j, j);
            int a_crit;

            if (!can_jump) {
                g[i][j] = g[i][j-1];
                b[i][j] = b[i][j-1];
            } else {
                g[i][j] = leq_result ? g[i-j][j] : g[i-j][j-1];
                g[i][j] = (g[i][j] + g[i][j-1])%MOD;

                int bv = leq_result ? b[i-j][j] : b[i-j][j-1];
                ++bv;
                b[i][j] = min(b[i][j-1], bv);
            }

            ////cerr << "  g[" << i << "][" << j << "] = " << g[i][j] << " : can jump " << can_jump << " leq_result " << leq_result << endl;
            ////cerr << "   a[" << i << "][" << j << "] = " << a[i][j] << " : acrit " << a_crit << endl;
        }
        for (int j=i+1; j<=n; ++j) {
            g[i][j] = g[i][j-1];
            b[i][j] = b[i][j-1];
        }
    }

    ll tcost = 0;
    int elen = 0;
    pii best(2, INF);
    ll base = 1;
    ll cur_cost = 0;
    int above = 0;
    for (int i=1; i<=n; ++i) {
        if (s[n-i] == '1') {
            cur_cost += base;
            if (cur_cost > MOD) {
                cur_cost -= MOD;
                above = 1;
            }
        }

        //cerr << "   ? base " << base << endl;

        if (b[n][i] != INF) {
            ll tv = b[n][i]+cur_cost;
            //cerr << "! " << i << " " << tv << " cc " << cur_cost << endl;
            ll fv = (tv >= MOD || above);
            pii xv = pii(fv, tv%MOD);
            best = min(best, xv);
            if (fv) break;
            ////cerr << " for " << i << " get " << xv.first << ", " << xv.second << endl;
        }

        base *= 2;
        if (base > MOD) {
            base -= MOD;
            above = 1;
        }
    }

    cout << g[n][n] << "\n";
    cout << best.second << "\n";
    

    return 0;
}