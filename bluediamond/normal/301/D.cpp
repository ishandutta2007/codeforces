#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, m;
int a[N];
int p[N];

/// daca i, j contine l, r => i <= l && j <= r => adun toate l din [i, ...n]

struct Question {
  int i;
  int j;
  int id;
};

bool operator < (Question a, Question b) {
  return a.i > b.i;
}

Question q[N];
int sol[N];

int aib[N];

void add(int i) {
  while (i <= n) {
    aib[i]++;
    i += i & (-i);
  }
}

int get(int i) {
  int r = 0;
  while (i > 0) {
    r += aib[i];
    i -= i & (-i);
  }
  return r;
}

vector <int> push[N];
void addup(int pos) {
  for (auto &x : push[pos]) {
    add(x);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      int l = p[i];
      int r = p[j];
      if (l > r) {
        swap(l, r);
      }
      push[l].push_back(r);
    }
  }

  for (int id = 1; id <= m; id++) {
    cin >> q[id].i >> q[id].j;
    q[id].id = id;
  }

  sort(q + 1, q + m + 1);
  int last = n + 1;
  for (int id = 1; id <= m; id++) {
    while (last > q[id].i) {
      last--;
      addup(last);
    }
    sol[q[id].id] = get(q[id].j);
  }

  for (int id = 1; id <= m; id++) {
    cout << sol[id] << "\n";
  }
  cout << "\n";


  return 0;
}