#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



string s;
int k;

void solve() {
  cin >> k >> k >> s;

  int ok = 1;

  for (int i = 0; i < k; ++i) {
    int w1 = 0, w2 = 0;
    for (int j = i; j < s.size(); j += k) {
      if (s[j] == '0') w1 = 1;
      if (s[j] == '1') w2 = 1;
    }
    if (w1 && w2) ok = 0;

    for (int j = i; j < s.size(); j += k) if (s[j] == '?') {
      if (w1) s[j] = '0';
      if (w2) s[j] = '1';
    }
  }

  int bal = 0, cnt = 0;
  for (int i = 0; i < k; ++i) if (s[i] == '0') ++bal; else if (s[i] == '1') --bal; else ++cnt;

  if (cnt < abs(bal)) ok = 0;

  if (ok) cout << "YES\n"; else cout << "NO\n";

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}