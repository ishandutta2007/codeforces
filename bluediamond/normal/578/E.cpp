/// 482 -> 483
#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9 + 7;

int getCnt(vector<int> order) {
  if (order.empty()) {
    return INF;
  }
  int sol = 0;
  for (int i = 1; i < (int) order.size(); i++) {
    sol += (order[i - 1] > order[i]);
  }
  return sol;
}

void addup(vector<int> &a, vector<int> b) {
  for (auto &x : b) {
    a.push_back(x);
  }
}

void print(vector<int> v) {
  cout << " ---> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

const int N = (int) 1e5 + 7;
string str;
int n;
int type[N], par[N];
bool vis[N];
vector<int> stk[2];
vector<vector<int>> kek[2][2];

void print_type(vector<int> v) {
  cout << " ---> ";
  for (auto &x : v) {
    cout << type[x] << " ";
  }
  cout << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> str;
  n = (int) str.size();

  for (int i = 1; i <= n; i++) {
    char ch = str[i - 1];
    assert(ch == 'L' || ch == 'R');
    if (ch == 'R') {
      type[i] = 0;
    } else {
      type[i] = 1;
    }
  }

  int cost = 0;

  for (int i = 1; i <= n; i++) {
    if (stk[type[i] ^ 1].empty()) {
      cost++;
    } else {
      par[i] = stk[type[i] ^ 1].back();
      stk[type[i] ^ 1].pop_back();
    }
    stk[type[i]].push_back(i);
  }

  for (int i = n; i >= 1; i--) {
    vector<int> path;
    if (vis[i] == 0) {
      int j = i;
      while (j) {
        vis[j] = 1;
        path.push_back(j);
        j = par[j];
      }
      reverse(path.begin(), path.end());
      kek[type[path[0]]][type[path.back()]].push_back(path);
    }
  }


  swap(kek[0][0], kek[0][1]);
  swap(kek[1][0], kek[1][1]);


  assert(abs((int) kek[0][1].size() - (int) kek[1][0].size()) <= 1);


  for (int x = 0; x <= 1; x++) {
    while ((int) kek[x][x].size() > 1) {
      addup(kek[x][x][0], kek[x][x].back());
      kek[x][x].pop_back();
    }
  }



  vector<int> sol;
  int total = (int) kek[0][1].size() + (int) kek[1][0].size();

  if (kek[0][1].empty() && kek[1][0].empty()) {
    for (auto &v : kek[0][0]) addup(sol, v);
    for (auto &v : kek[1][1]) addup(sol, v);

    if (!kek[0][0].empty() && !kek[1][1].empty()) {
      sol.clear();
      vector<int> v1, v2;
      for (auto &v : kek[0][0]) addup(v1, v);
      for (auto &v : kek[1][1]) addup(v2, v);
      assert(!v1.empty() && !v2.empty());
      if (v1.back() < v2.back()) {
        swap(v1, v2);
      }



      v2.push_back(v1.back());

      v1.pop_back();
      addup(sol, v1);
      addup(sol, v2);

    }
   /** for (int vl = 0; vl < 2; vl++) {
      cout << " ----------------- \n";
      cout << vl << " : \n";
      for (auto &v : kek[vl][vl]) {
        cout << " ---> ";
        for (auto &x : v) {
          cout << type[x] << " ";
        }
        cout << "\n";
      }
    }

    exit(0);

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        cout << (int) kek[i][j].size() << " ";
      }
      cout << "\n";
    }
    exit(0);**/
    /// 0 1 si 1 0
  } else {
    if ((int) kek[0][1].size() >= (int) kek[1][0].size()) {
      for (auto &v : kek[0][0]) addup(sol, v);

      for (int j = 0; j < total; j++) {
        if (j % 2 == 0) {
          assert(!kek[0][1].empty());
          addup(sol, kek[0][1].back());
          kek[0][1].pop_back();
        } else {
          assert(!kek[1][0].empty());
          addup(sol, kek[1][0].back());
          kek[1][0].pop_back();
        }
        for (auto &v : kek[1][1]) addup(sol, v);
      }

      assert(kek[0][1].empty() && kek[1][0].empty());
    } else {
      for (auto &v : kek[1][1]) addup(sol, v);

      for (int j = 0; j < total; j++) {
        if (j % 2 == 1) {
          assert(!kek[0][1].empty());
          addup(sol, kek[0][1].back());
          kek[0][1].pop_back();
        } else {
          assert(!kek[1][0].empty());
          addup(sol, kek[1][0].back());
          kek[1][0].pop_back();
        }
        for (auto &v : kek[0][0]) addup(sol, v);
      }
      assert(kek[0][1].empty() && kek[1][0].empty());
    }
  }



  /**



  00

  01

  10

  11



  01 10 01 10

  **/

  /**
  0 0 | 1 1 | 0 0 | 1 1 | 0 0 | 1 1

  0 0 | 1 0 | 1 1
  **/

  cout << cost - 1 << "\n";
  for (auto &i : sol) {
    cout << i << " ";
  }
  cout << "\n";
}