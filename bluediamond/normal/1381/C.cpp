#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n, x, y, a[N], f[N];
vector<int> pos[N];
bool eq[N];
bool kek[N];
int sol[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    if (x == n) {
      cout << "YES\n";
      for (int i = 1; i <= n; i++) {
        int uu;
        cin >> uu;
        cout << uu << " ";
      }
      cout << "\n";
      continue;
    }
    for (int i = 0; i <= n + 1; i++) {
      f[i] = 0;
      pos[i].clear();
      eq[i] = 0;
      kek[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      f[a[i]]++;
      pos[a[i]].push_back(i);
    }
    int wood = 1;
    while (f[wood] != 0) {
      wood++;
    }
    set<pair<int, int>> s;
    for (int i = 1; i <= n + 1; i++) {
      s.insert({f[i], i});
    }
    for (int st = 1; st <= x; st++) {
      auto it = s.end();
      it--;
      int i = it->second;
      s.erase({f[i], i});
      f[i]--;
      s.insert({f[i], i});
      eq[pos[i].back()] = 1;
      pos[i].pop_back();
    }
    y -= x;
    vector<pair<int, int>> rem;
    for (auto &it : s) {
      rem.push_back({it.first, it.second});
      /// {cnt, value}
    }
    reverse(rem.begin(), rem.end());
    vector<int> lol;
    for (auto &it : rem) {
      for (int j = 1; j <= it.first; j++) lol.push_back(it.second);
    }
    int sz = (int) lol.size();
    vector<int> lol2;
    for (int i = 0; i < sz; i++) {
      lol2.push_back(lol[(i + rem[0].first) % sz]);
    }
    int matches = 0;
    for (int i = 0; i < sz; i++) matches += (lol[i] == lol2[i]);
    int questions = sz - y;
    if (questions >= matches) {
      for (int i = 0; i < sz; i++) {
        if (lol[i] == lol2[i]) {
          kek[i] = 1;
          questions--;
        }
      }
      for (int i = 0; i < sz; i++) {
        if (questions > 0 && lol[i] != lol2[i]) {
          kek[i] = 1;
          questions--;
        }
      }
      vector<int> pisi, pisi2;
      for (int i = 0; i < sz; i++) {
        int x = lol[i];
        pisi.push_back(pos[x].back());
        pos[x].pop_back();
      }
      for (int i = 0; i < sz; i++) {
        pisi2.push_back(pisi[(i + rem[0].first) % sz]);
      }
      for (int i = 1; i <= n; i++) sol[i] = -1;
      for (int i = 0; i < sz; i++) {
        if (kek[i]) {
          sol[pisi[i]] = wood;
        } else {
          sol[pisi[i]] = lol2[i];
        }
      }
      cout << "YES\n";
      for (int i = 1; i <= n; i++) {
        if (eq[i]) cout << a[i] << " "; else cout << sol[i] << " ";
      }
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}