#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<pair<int, int>> w[2];

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    w[(i + j) % 2].pb(mp(i + 1, j + 1));
  }

  for (int i = 0; i < n * n; ++i) {
    int a;
    cin >> a;

    if (w[0].size() > 0 && w[1].size() > 0) {
      int now = 1; if (a == 1) now = 2;
      cout << now << ' ' << w[now - 1].back().x << ' ' << w[now - 1].back().y << endl;
      w[now - 1].pop_back(); 
    } else {
      if (w[0].size() > 0) {
        int now = 1;
        if (a == 1) now = 3;
        cout << now << ' ' << w[0].back().x << ' ' << w[0].back().y << endl;
        w[0].pop_back();
      } else {
        int now = 2;
        if (a == 2) now = 3;
        cout << now << ' ' << w[1].back().x << ' ' << w[1].back().y << endl;
        w[1].pop_back();
      }
    }
  }
}