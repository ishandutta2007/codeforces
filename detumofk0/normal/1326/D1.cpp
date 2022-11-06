#include<bits/stdc++.h>

using namespace std;

const char DUMMY = '.';

vector<int> manacher(string s) {
	int n = s.size() * 2 - 1;
	vector <int> f = vector <int>(n, 0);
	string a = string(n, DUMMY);
	for (int i = 0; i < n; i += 2) a[i] = s[i / 2];
	int l = 0, r = -1, center, res = 0;
	for (int i = 0, j = 0; i < n; i++) {
		j = (i > r ? 0 : min(f[l + r - i], r - i)) + 1;
		while (i - j >= 0 && i + j < n && a[i - j] == a[i + j]) j++;
		f[i] = --j;
		if (i + j > r) {
			r = i + j;
			l = i - j;
		}
    int len = (f[i] + i % 2) / 2 * 2 + 1 - i % 2;
		if (len > res) {
			res = len;
			center = i;
		}
	}
	return f;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    string s; cin >> s;

    int res = 1, pos = 0, rev = 0;

    for(int loop = 0; loop < 2; ++loop) {
      vector<int> f = manacher(s);

      int best = 0;
      for(int i = 0; i < s.size(); ++i) {
        if(s[i] != s[s.size() - i - 1]) break;
        best++;
      }

      for(int i = 0; i + i < f.size(); i++) {
        int p = i / 2;
        int len = (f[i] + i % 2) / 2 * 2 + 1 - i % 2;
        int left = p + (i % 2) - (len / 2);
        if(best >= left) {
          res = max(res, len + left * 2);
          if(res == len + left * 2) {
            pos = p;
            rev = loop;
          }
        }
      }
      reverse(s.begin(), s.end());
    }

    if(rev) reverse(s.begin(), s.end());

    for(int i = 0; i <= pos; ++i) cout << s[i];
    for(int i = pos - res % 2; i >= 0; --i) cout << s[i];
    cout << "\n";
  }

  return 0;
}