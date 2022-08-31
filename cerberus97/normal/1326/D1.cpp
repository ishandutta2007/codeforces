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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

// Source - github.com/t3nsor/codebook
vector<int> fastLongestPalindromes(string str) {
    int i=0,j,d,s,e,lLen,palLen=0;
    vector<int> res;
    while (i < str.length()) {
        if (i > palLen && str[i-palLen-1] == str[i]) {
            palLen += 2; i++; continue;
        }
        res.push_back(palLen);
        s = res.size()-2;
        e = s-palLen;
        bool b = true;
        for (j=s; j>e; j--) {
            d = j-e-1;
            if (res[j] == d) { palLen = d; b = false; break; }
            res.push_back(min(d, res[j]));
        }
        if (b) { palLen = 1; i++; }
    }
    res.push_back(palLen);
    lLen = res.size();
    s = lLen-2;
    e = s-(2*str.length()+1-lLen);
    for (i=s; i>e; i--) { d = i-e-1; res.push_back(min(d, res[i])); }
    return res;
}

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.length();
		auto v = fastLongestPalindromes(s);
		int max_common = 0;
		for (int i = 0, j = n - 1; i < j; ++i, --j) {
			if (s[i] != s[j]) {
				break;
			}
			++max_common;
		}
		int ans = 0, pref = 0, suff = 0;
		for (int i = 0, j = 1; i < n; ++i, j += 2) {
			int l = v[j] / 2;
			int x = min(i - l, n - i - l - 1);
			if (max_common >= x) {
				if (2 * x + v[j] > ans) {
					ans = 2 * x + v[j];
					pref = x;
					suff = x;
					if (i - l <= n - i - l - 1) {
						pref += v[j];
					} else {
						suff += v[j];
					}
				}
			}
		}
		for (int i = 0, j = 2; i < n - 1; ++i, j += 2) {
			int l = v[j] / 2;
			int x = min(i - l + 1, n - i - l - 1);
			if (max_common >= x) {
				if (2 * x + v[j] > ans) {
					ans = 2 * x + v[j];
					pref = x;
					suff = x;
					if (i - l + 1 <= n - i - l - 1) {
						pref += v[j];
					} else {
						suff += v[j];
					}
				}
			}
		}
		cout << s.substr(0, pref) + s.substr(n - suff, suff) << '\n';
	}
}