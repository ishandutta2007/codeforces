#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct suff_array {
  int L; string s; int i, skip, lvl;
  vector<vi> P; vector<pair<pii,int>> M;
  suff_array() {}
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
}; //! code adapted from the Stanford Team Notebook

int n;
string s;
string t;
suff_array sa;

const int N = 100100;
const int LG = 17;
int len[N];
pii jump[LG][N];

void setup() {
    for (int i=0; i<n; ++i) {
        jump[0][i] = pii(len[i], i);
    }
    for (int j=0; j<LG-1; ++j) {
        for (int i=0; i+(1<<j)<n; ++i) {
            jump[j+1][i] = max(jump[j][i], jump[j][i+(1<<j)]);
        }
    }
}

// finds the largest palindrome centered somewhere in [i, j] inclusive using binary jumping
pii range_max(int i, int j) {
    int sz = j-i+1;
    int lg = 31 - __builtin_clz(sz);
    return max(jump[lg][i], jump[lg][j+1-(1<<lg)]);
}

// is it possible to get a palindrome entirely fitting in range [i, j] of length l?
bool can_get_between(int i, int j, int l) {
    int ii = i+l/2;
    int jj = j-l/2;
    if (ii > jj) return false;

    auto rm = range_max(ii, jj);
    return rm.first >= l;
}

// find the largest palindrime entirely fitting in range [i, j] by binary search
// returns pair (0-indexed start of palindrome, length of palindrome)
pii get_between(int i, int j) {
    assert (i<=j);
    int lo = 1;
    int hi = N;
    while (lo < hi) {
        int m = (lo+hi+1)/2;
        if (can_get_between(i, j, m)) {
            lo = m;
        } else {
            hi = m-1;
        }
    }
    assert (lo%2 == 1);

    int ii = i+lo/2;
    int jj = j-lo/2;

    auto rm = range_max(ii, jj);
    rm.first = min(rm.first, min((rm.second-i)*2+1, (j-rm.second)*2+1));
    rm.second = rm.second-rm.first/2;

    return rm;
}

struct solution {
    pii x, y, z;
    int parts, length;
    solution() :parts(0), length(0) {}
    solution(pii a): parts(1), x(a), length(a.second) {}
    solution(pii a, pii b, pii c): parts(3), x(a), y(b), z(c), length(a.second+b.second+c.second) {}
    void print() {
        assert(parts != 0);
        cout << parts << "\n";
        cout << x.first << " " << x.second << "\n";
        if (parts > 1) {
            cout << y.first << " " << y.second << "\n";
            cout << z.first << " " << z.second << "\n";
        }
    }
    bool operator < (const solution& o) const {
        if (length == o.length) return parts < o.parts;
        return length < o.length;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    
    // generate suffix array on string s$(rev s)
    // e.g. if s = "abac" then t="abac$caba"
    n = s.size();
    t = s;
    reverse(s.begin(), s.end());
    t += '$'; 
    t += s;
    reverse(s.begin(), s.end());
    sa = suff_array(t);

    // generate longest palindrome centered at each position
    for (int i=0; i<n; ++i) {
        int x = sa.lcp(i, 2*n-i);
        len[i] = x*2-1;
    }
    // setup binary jumping (for finding max in range)
    setup();

    solution ans;

    // Iterate through all start positions. Find longest LCP with reversed suffix.
    //   This is done by lcp(reversed string s, s[i..n)
    // Then find longest possible odd palindrome fitting in between the suffix and prefix.
    //   This is done with a binary search above.
    // For a given start position i, it is always optimal to greedily take the longest
    //   lcp with the reversed suffix. The only reason to not take the longest prefix
    //   and suffix is to take a longer middle palindrome; but taking an extra character
    //   for the prefix/suffix gives +2 which offsets the -2 from reducing the size of the
    //   middle palindrome.
    for (int i=0; i<n; ++i) {
        int lcp = sa.lcp(i, n+1);
        if (lcp == n-i) {
            ans = max(ans, solution(pii(i+1, lcp)));
            auto q = solution(pii(i+1, lcp));
            continue;
        }

        int lo = i+lcp;
        int hi = n-1-lcp;
        assert(hi >= lo);

        pii rm = get_between(lo, hi);

        ans = max(solution(pii(i+1, lcp), pii(rm.second+1, rm.first), pii(n-lcp+1, lcp)), ans);
    }

    // if the palindrome 
    if (ans.length%2 == 0) {
        assert(ans.parts == 1);
        int p = ans.x.first;
        int k = ans.x.second;
        int q = (k-1)/2;
        ans = solution(pii(p, q), pii(p+q, 1), pii(p+k-q, q));
    }
    // in some cases the suffix/prefix might be empty, so fix by using only the middle
    if (ans.length%2 == 1 && ans.x.second == 0) {
        ans = solution(ans.y);
    }

    ans.print();

    return 0;
}