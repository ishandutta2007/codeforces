#include <bits/stdc++.h>
#include <time.h>

using namespace std;

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
	if ((x += y) >= mod) {
		x -= mod;
    }
}

int sum(int x, int y) {
    add(x, y);
    return x;
}

int mult(int x, int y) {
    return (long long) x * y % mod;
}

int power(int x, long long p) {
    int res = 1;
    while (p) {
      if (p & 1) {
        res = mult(res, x);
      }
      x = mult(x, x);
      p >>= 1;
    }
    return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

const int inf = (int) 1.01e9;
const long double eps = 1e-8;
const long double pi = acos(-1.0L);
const int maxn = 1e5 + 100;

int used[1003][30];
int told[30];
vector<int> pos, good;

void solve() {
    int n;
    cin >> n;
    string word;
    cin >> word;
    for (int i = 0; i < n; ++i) {
        if (word[i] == '*') {
            pos.push_back(i);
        } else {
            told[word[i] - 'a'] = 1;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string tmp;
        cin >> tmp;
        bool check = true;
        for (int i = 0; i < n; ++i) {
            if (word[i] != '*') {
                if (word[i] != tmp[i]) {
                    check = false;
                }
            }
        }
        if (check) {
            good.push_back(i);
        } else {
            continue;
        }
        for (int p: pos) {
            if (told[tmp[p] - 'a']) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    used[i][c - 'a'] = 1;
                }
            }
            used[i][tmp[p] - 'a'] = 1;
        }
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        int cnt = 1;
        for (int i: good) {
            cnt &= used[i][c - 'a'];
        }
        ans += cnt;
    }
    cout << ans;
    cout << endl;
}

void precalc() {
}

void clear() {
}

// #define FNAME "local"
// #define DEBUG

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(8);
    srand(time(0));
    cout << fixed;
    precalc();
#ifdef FNAME
 	assert(freopen(FNAME".in", "r", stdin));
    freopen(FNAME".out", "w", stdout);
#endif
	int task_count = 1;
	// cin >> task_count;
    for (int i = 1; i <= task_count; ++i) {
        // cout << "Case #" << i << ": ";
		solve();
#ifdef DEBUG
		cout << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	    clear();
	}
    return 0;
}