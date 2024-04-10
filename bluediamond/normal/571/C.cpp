#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 

bool home = true;
using namespace std;

struct T {
  int tp = 0;
  int x;
};

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int m, n;
  cin >> m >> n;
  vector<vector<T>> v(m);
  vector<vector<pair<int, int>>> positions(n);
  vector<int> solution(n, -1), point(n, -1);
  vector<vector<pair<int, int>>> g(m);
  vector<bool> solved_request(m, false);

  function<void(int)> update_i = [&](int i) {
    assert(0 <= i && i < n);
    vector<pair<int, int>> nw;
    for (auto& p : positions[i]) {
      if (!solved_request[p.first]) {
        nw.push_back(p);
      }
    }
    positions[i] = nw;
  };

  function<int(int)> get_answer = [&](int i) {
    assert(0 <= i && i < n);
    assert(solution[i] == -1);
    update_i(i);

    int dim = (int)positions[i].size(), answer = -1;
    if (dim == 0) return answer;
    if (dim == 1) {
      auto p0 = positions[i][0];
      answer = v[p0.first][p0.second].tp;
    }
    else {
      assert(dim == 2);
      auto p0 = positions[i][0];
      auto p1 = positions[i][1];
      if (v[p0.first][p0.second].tp == v[p1.first][p1.second].tp) {
        answer = v[p0.first][p0.second].tp;
      }
      else {
        if (p0.first == p1.first) {
          answer = 0;
        }
      }
    }
    if (answer != -1) {
      ///   cout << i + 1 << " -> " << answer << "\n";
    }
    return answer;
  };

  function<void(int)> solve_request = [&](int i) {
    if (solved_request[i]) return;
    solved_request[i] = true;
    for (auto& G : v[i]) {
      int x = G.x;
      if (solution[x] != -1) continue;
      int answer = get_answer(x);
      if (answer == -1) continue;
      solution[x] = answer;
      for (auto& it : positions[x]) {
        solve_request(it.first);
      }
    }
  };

  for (int i = 0; i < m; i++) {
    int l;
    cin >> l;
    v[i].resize(l);
    for (int j = 0; j < l; j++) {
      auto& it = v[i][j];
      cin >> it.x;
      if (it.x < 0) {
        it.x *= -1;
        it.tp = 1;
      }
      it.x--;
      assert(0 <= it.x && it.x < n);
      positions[it.x].push_back({ i, j });
    }
  }


  for (int i = 0; i < n; i++) {
    if (solution[i] != -1) continue;
    int answer = get_answer(i);
    if (answer == -1) continue;
    solution[i] = answer;
    for (auto& it : positions[i]) {
      solve_request(it.first);
    }
  }


  vector<int> all;


  for (int i = 0; i < n; i++) {
    if (solution[i] != -1) continue;
    int answer = get_answer(i);
    assert(answer == -1);
    if (positions[i].size() == 0) continue;
    assert((int)positions[i].size() == 2);
    int a = positions[i][0].first, b = positions[i][1].first;
    // edge a <-> b
    all.push_back(i);
    g[a].push_back({ b, i });
    g[b].push_back({ a, i });
   // cout << "edge " << a + 1 << " " << b + 1 << "\n";
  }


  vector<bool> vis(m, false), act(m, false);
  vector<int> when(m, -1);

  vector<int> current, found, verts, pth, uipth;

  function<void(int, int)>dfs = [&](int a, int ipar) {
    when[a] = (int)current.size();
   

    pth.push_back(a);
    verts.push_back(a);
    vis[a] = true;
    act[a] = true;

    for (auto& edge : g[a]) {
      int b = edge.first, i = edge.second;
      if (i == ipar) continue;
      if (act[b]) {

        if (found.empty()) {
          assert(when[b] != -1);
          for (int j = when[b]; j < (int)current.size(); j++) {
            found.push_back(current[j]);
          }
          for (int j = when[b]; j < (int)current.size(); j++) {
            assert(0 <= j && j < pth.size());
            uipth.push_back(pth[j]);
          }
          found.push_back(i);
        }
      }
      else {
        if (!vis[b]) {
          current.push_back(i);
          dfs(b, i);
          current.pop_back();
        }
      }
    }

    act[a] = false;
  };

  function<void(int)>build = [&](int a) {
    if (vis[a]) assert(act[a]);
    vis[a] = true;
    for (auto& edge : g[a]) {
      int b = edge.first, i = edge.second;
      if (!vis[b]) {
        point[i] = b;
        build(b);
      }
    }
  };

  
  for (int i = 0; i < m; i++) {

    if (vis[i]) continue;
    if (g[i].empty()) continue;
    current.clear();
    found.clear();
    verts.clear();
    dfs(i, -1);
    if (found.empty()) {
      cout << "NO\n";
      return 0;
    }
    for (auto& b : verts) {
      vis[b] = false;
      act[b] = false;
    }
    vector<int> posi;
    posi.push_back(positions[found[0]][0].first);
    posi.push_back(positions[found[0]][1].first);
    bool good = false;
    vector<int> szs;
    for (auto& clast : posi) {
      int last = clast;
      set<int> st;
      for (auto& i : found) {
        assert((int)positions[i].size() == 2);
        int a = positions[i][0].first, b = positions[i][1].first;
        vis[a] = vis[b] = act[a] = act[b] = true;

        //cout << a << " " << b << "\n";

        if (a == last) {
          point[i] = b;
        }
        else {
          point[i] = a;
        }
        st.insert(point[i]);

        //cout << a + b - point[i] << " " << point[i] << "\n";

        last = point[i];
 
      }
      szs.push_back((int)st.size());
      if ((int)st.size() == (int)found.size()) {
        good = true;
        break;
      }
    }
    if (!good) {
      cout << "good is bad\n";
      for (auto& X : szs) {
        cout << X << " ";
      }
      cout << "\n";
      cout << (int)found.size() << "\n";
      for (auto& i : found) {

        int a = positions[i][0].first, b = positions[i][1].first;
        cout << a << " " << b << "\n";
      }
      exit(0);
    }
    assert(good);
    for (auto& v : verts) {
      if (act[v]) {
        build(v);
      }
    }
    for (auto& v : verts) {
      when[v] = -1;
    }
  }
  
  //cout << "directed:\n";
  for (auto& i : all) {
    if (point[i] == -1) continue;

    int a = positions[i][0].first, b = positions[i][1].first;
    
  //  cout << a+b-point[i] << " " << point[i] << "\n";
    assert(a != b);
    assert(point[i] == a || point[i] == b);
    int pz;
    if (point[i] == a) pz = 0; else pz = 1;
    solution[v[positions[i][pz].first][positions[i][pz].second].x] = v[positions[i][pz].first][positions[i][pz].second].tp;
  }
  cout << "YES\n";

  for (auto& x : solution) {
    if (x == -1) {
      x = 0;
    }
    x ^= 1;
    cout << x;

  }
  cout << "\n";
}