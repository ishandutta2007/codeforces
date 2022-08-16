/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

struct SuffixArray {
  const int L;
  string s;
  vector<vector<int> > P;
  vector<pair<pair<int,int>,int> > M;
  SuffixArray(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++) 
             M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++) 
             P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }    
  }
  vector<int> GetSuffixArray() { return P.back(); }
};

struct stringComparator {
	string &t;
	stringComparator(string &_t) : t(_t) {}
	bool operator()(const int &suff_id, const string &s) { 
		return t.substr(suff_id, s.length()) < s;
	}
	bool operator()(const string &s, const int &suff_id) { 
		return s < t.substr(suff_id, s.length());
	}
};

const int N = 2e5 + 10;

string s[N];

ll solve(string t, int n);
vector<int> find_matches(string t, int n);

int main() {
	fast_cin();
	string t; int n;
	cin >> t >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	cout << solve(t, n) << '\n';
}

ll solve(string t, int n) {
	int m = t.length();
	vector<int> fw = find_matches(t, n);
	reverse(t.begin(), t.end());
	for (int i = 1; i <= n; ++i) {
		reverse(s[i].begin(), s[i].end());
	}
	vector<int> bw = find_matches(t, n);
	reverse(bw.begin(), bw.end());
	ll ans = 0;
	for (int i = 0; i < m - 1; ++i) {
		ans += ll(bw[i]) * fw[i + 1];
	}
	return ans;
}

vector<int> find_matches(string t, int n) {
	int m = t.length();
	SuffixArray SA(t);
	vector<int> inv = SA.GetSuffixArray();
	vector<int> suff_array(m);
	for (int i = 0; i < m; ++i) {
		suff_array[inv[i]] = i;
	}
	vector<int> upd(m + 1, 0);
	for (int i = 1; i <= n; ++i) {
		int l = lower_bound(suff_array.begin(), suff_array.end(), s[i], stringComparator(t)) - suff_array.begin();
		int r = upper_bound(suff_array.begin(), suff_array.end(), s[i], stringComparator(t)) - suff_array.begin();
		++upd[l];
		--upd[r];
	}
	int cur = 0;
	vector<int> ans(m, 0);
	for (int i = 0; i < m; ++i) {
		cur += upd[i];
		ans[suff_array[i]] += cur;
	}
	return ans;
}