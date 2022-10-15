#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n;
vector <int> g[N];
int a[N], d[N], p[N], k[N];


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]] = i;
    d[i] = -1;
  }

  d[a[1]] = 0;
  if (a[1] != 1) {
    cout << "No\n";
    return 0;
  }
  queue <int> q;
  q.push(a[1]);

  while (!q.empty()) {
    int nod = q.front();
    q.pop();
    for (auto &nou : g[nod]) {
      if (d[nou] == -1) {
        k[nou] = nod;
        d[nou] = 1 + d[nod];
        q.push(nou);
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if (p[k[a[i - 1]]] > p[k[a[i]]]) {
      cout << "No\n";
      return 0;
    }

  }
  cout << "Yes\n";

  return 0;
}