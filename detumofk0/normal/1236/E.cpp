#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N];
int ansl[N];
int ansr[N];
int goleft[N];
int goright[N];
vector < int > blocked[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m;

  if(n == 1 && m > 0) {
    cout << 0;
    return 0;
  }

  for(int i = 1; i <= m; ++i) {
    cin >> a[i];
    blocked[a[i]].push_back(i);
  }

  map < int, int > mymap;

  /// calc goright()
  mymap.clear();
  for(int i = n; i >= 1; --i) {
    sort(blocked[i].rbegin(), blocked[i].rend());
    for(int id : blocked[i]) {
      int v = id - i + 1;
      if(mymap.count(v)) goright[id] = mymap[v];
      else goright[id] = id;

      mymap[id - i] = goright[id];
    }
    /// we know that it's blocked at 0th moment
    if(!mymap.count(-1 -i + 1)) {
      ansr[i] = min(n, i + m);
    }
    else {
      int x = mymap[-1 -i + 1];
      ansr[i] = min(n, a[x] - 1 + (m - x));
    }
  }

  // calc goleft
  mymap.clear();
  for(int i = 1; i <= n; ++i) {
    for(int id : blocked[i]) {
      int v = i + id + 1;
      if(mymap.count(v)) goleft[id] = mymap[v];
      else goleft[id] = id;
      mymap[i + id] = goleft[id];
    }

    if(!mymap.count(i)) {
      ansl[i] = max(1, i - m);
    }
    else {
      int x = mymap[i];
      ansl[i] = max(1, a[x] + 1 - (m - x));
    }
  }

  long long tot = 0;
  for(int i = 1; i <= n; ++i) {
    ansl[i] = max(1, ansl[i] - 1);
    ansr[i] = min(n, ansr[i] + 1);
    tot += ansr[i] - ansl[i] + 1;
  }

  cout << tot << endl;

  return 0;
}