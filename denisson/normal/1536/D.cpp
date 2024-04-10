#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
int a[200007];



int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    set<int> q;
    q.insert(a[0]);
    int uk = a[0];
    int ok = 1;
    for (int i = 1; i < n; ++i) {
   //   cout << uk << ' ' << q.size() << endl;
      if (a[i] == uk) continue;
      if (a[i] > uk) {

        if (uk == *prev(q.end())) {
          q.insert(a[i]);
          uk = a[i];
        } else {
          auto it = q.find(uk);
          ++it;
          if (*it == a[i]) { uk = a[i]; continue; }
          if (*it < a[i]) {
            ok = 0;
            break;
          } else q.insert(a[i]), uk = a[i];
        }

      } else {

        auto it = q.find(uk);
        if (it == q.begin()) {
          q.insert(a[i]);
          uk = a[i];
        } else {
          it--;

          if (*it == a[i])  { uk = a[i]; continue; }
          if (*it > a[i]) {
            ok = 0;
            break;
          } else q.insert(a[i]), uk = a[i];
        }

      }
    }
    if (ok) cout << "YES\n"; else cout << "NO\n";
  }
}