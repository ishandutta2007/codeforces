#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int w1 = max(a, b);
    int w2 = max(c, d);
    vector<int> q = {a, b, c, d};
    sort(all(q));
    if (w1 < w2) swap(w1, w2);
    if (w1 == q[3] && w2 == q[2]) cout << "YES\n"; else cout << "NO\n";
  }
}