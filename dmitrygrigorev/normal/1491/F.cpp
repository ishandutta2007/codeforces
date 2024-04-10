#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> bad;
  int last;

  for (int i = 1; i < n; ++i) {
    cout << "? " << i << " " << 1 << endl;
    for (int j = 0; j < i; ++j) cout << j+1 << " ";
    cout << endl;

    cout << i + 1 << endl;
    int x;
    cin >> x;

    if (x != 0) {
      last = i;
      break;
    }

  }

  for (int i = last + 1; i < n; ++i) {
    cout << "? " << 1 << " " << 1 << endl;
    cout << last + 1 << endl;
    cout << i + 1 << endl;

    int x;
    cin >> x;
    if (x == 0) bad.pb(i);
  }

  int l = 0, r = last - 1;

  while (l != r) {
    int mid = (l+r)/2;
    cout << "? " << mid-l+1 << " " << 1 << endl;
    for (int j = l; j <= mid; ++j) cout << j+1 << " ";
    cout << endl;

    cout << last+1 << endl;
    int x;
    cin >> x;

    if (x == 0) l = mid+1;
    else r = mid;
  }

  for (int i = 0; i < last; ++i) {
    if (i != l) bad.pb(i);
  }

  cout << "! ";
  cout << bad.size() << " ";
  sort(all(bad));

  for (auto x : bad) cout << x+1 << " ";
  cout << endl;

}


int main(){
#ifdef LOCAL
	//freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) solve();

}