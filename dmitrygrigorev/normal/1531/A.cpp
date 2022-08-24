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

  string ans = "blue";
  bool locked = false;

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string t;
    cin >> t;

    if (t == "lock") locked = true;
    else if (t == "unlock") locked = false;
    else if (!locked) ans = t;

  }

  cout << ans;

}