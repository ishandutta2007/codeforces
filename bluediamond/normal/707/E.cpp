#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Cell {
  int pos, x;
};

struct Dependency {
  int pos, i, sgn;
};

int n, m;

bool cmpCell(Cell a, Cell b) {
  return a.pos < b.pos;
}

bool cmpDependency(Dependency a, Dependency b) {
  return a.pos < b.pos;
}

ll aib[2222];

void add(int i, ll x) {
  while (i < 2222) {
    aib[i] += x;
    i += i & (-i);
  }
}

ll get(int i) {
  ll s = 0;
  while (i) {
    s += aib[i];
    i -= i & (-i);
  }
  return s;
}

void clr() {
  for (int i = 0; i < 2222; i++)aib[i] = 0;
}

struct Guy {
  vector<Cell> cells;
  vector<Dependency> dependencies;
  Guy(vector<Cell> cells) : cells(cells) {
  }
  void addDependency(int r, int c, int i, int sgn) {
    dependencies.push_back({ r * 2222 + c, i, sgn });
  }
  void solveDependencies(vector<ll>& solution) {
    sort(cells.begin(), cells.end(), cmpCell);
    sort(dependencies.begin(), dependencies.end(), cmpDependency);
    clr();
    int nxt = 0;
    for (auto& dependency : dependencies) {
      while (nxt < (int)cells.size() && cells[nxt].pos / 2222 <= dependency.pos / 2222) {
        add(cells[nxt].pos % 2222, cells[nxt].x);
        nxt++;
      }
      solution[dependency.i] += get(dependency.pos % 2222) * dependency.sgn;
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  /// freopen("input", "r", stdin);
  int k;
  cin >> n >> m >> k;
  vector<vector<Cell>> all(k);
  vector<Guy> guys;
  vector<bool> act(k, 1);
  for (auto& cells : all) {
    int l;
    cin >> l;
    cells.resize(l);
    for (auto& it : cells) {
      int r, c;
      cin >> r >> c;
      it.pos = r * 2222 + c;
      cin >> it.x;
    }
    guys.push_back(cells);
  }
  vector<ll> solution;
  int q;
  cin >> q;
  while (q--) {
    string type;
    cin >> type;
    if (type == "ASK") {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      ll sum = 0;
      for (int i = 0; i < k; i++) {
        if (act[i]) {
          guys[i].addDependency(r2, c2, (int)solution.size(), +1);
          guys[i].addDependency(r2, c1 - 1, (int)solution.size(), -1);
          guys[i].addDependency(r1 - 1, c2, (int)solution.size(), -1);
          guys[i].addDependency(r1 - 1, c1 - 1, (int)solution.size(), +1);
        }
      }
      solution.push_back(0);
    }
    else {
      int i;
      cin >> i;
      i--;
      act[i] = !act[i];
    }
  }

  for (int i = 0; i < k; i++) {
    guys[i].solveDependencies(solution);
  }
  for (auto& x : solution) {
    cout << x << "\n";
  }
  return 0;
}