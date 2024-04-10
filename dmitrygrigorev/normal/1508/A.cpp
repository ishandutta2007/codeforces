#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

char maj(char a, char b, char c) {
  int sum = (a - '0') + (b - '0') + (c - '0');
  if (sum >= 2) return '1';
  return '0';
}

void solve() {
  int n;
  cin >> n;

  string a, b, c;
  cin >> a >> b >> c;

  string ans = "";
  int u1 = 0, u2 = 0, u3 = 0;
  while (u1 < 2*n && u2 < 2*n && u3 < 2*n) {
    
    char Q = maj(a[u1], b[u2], c[u3]);
    ans += Q;

    if (a[u1] == Q) u1++;
    if (b[u2] == Q) u2++;
    if (c[u3] == Q) u3++;
  }

  while (u1 < 2*n) {
    if (u1 < u2 && u1 < u3) break;
    ans += a[u1++];
  }

  while (u2 < 2*n) {
    if (u2 <= u1 && u2 < u3) break;
    ans += b[u2++];
  }

  while (u3 < 2*n) {
    if (u3 <= u1 && u3 <= u2) break;
    ans += c[u3++];
  }

  cout << ans << '\n';

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}