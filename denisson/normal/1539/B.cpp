#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, q;
string s;

int cnt[26][100007];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> q >> s;

  for (int i = 0; i < s.size(); ++i) {
    cnt[s[i] - 'a'][i]++;
    if (i)
      for (int j = 0; j < 26; ++j) cnt[j][i] += cnt[j][i - 1];

  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    ll res = 0;

    for (int j = 0; j < 26; ++j) {
      int now = cnt[j][r];
      if (l) now -= cnt[j][l - 1];
      res += now * (ll)(j + 1);
    }

    cout << res << "\n";
  }
}