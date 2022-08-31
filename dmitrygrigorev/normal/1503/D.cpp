#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Pair {
  int x;
  int y;
  int def_stack;
};

bool cmp(Pair &a, Pair &b) {
  return (a.x < b.x);
}

const int INF = 1e9;

pair<int, int> check(set<pair<int, int> > &st, Pair &p, Pair &prev, int cost, int t) {
  if (!st.size()) return mp(-1, -1);
  auto it = st.lower_bound(mp(p.y, -1));
  if (it == st.end()) return mp(-1, -1);

  int C = ((*it).y) + cost + t;
  return mp(prev.y, C);

}

void Ins(set<pair<int, int> > &st, pair<int, int> &p, int t) {
  p.y -= t;

  if (st.size()) {

    auto it = st.lower_bound(p);
    if (it != st.end()) {
      if ((*it).y <= p.y) return;
    }

  }

  while (st.size()) {
    auto it = st.lower_bound(p);
    if (it == st.begin()) break;
    it--;

    if ((*it).y <= p.y) break;
    st.erase(it);
  }

  st.insert(p);

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<Pair> v(n);
  for (auto &x : v) {
    cin >> x.x >> x.y;
    x.def_stack = 0;
    if (x.x > x.y) {
      swap(x.x, x.y);
      x.def_stack = 1;
      if (x.x > n) {
        cout << -1;
        exit(0);
      }
    }
    else if (x.x > n) {
      cout << -1;
      exit(0);
    }
  }

  sort(all(v), cmp);

  int fadd = 0, sadd = 0;

  set<pair<int, int> > first_stack, second_stack;
  int D = v[0].def_stack;

  first_stack.insert(mp(INF, 1-D));
  second_stack.insert(mp(INF, D));

  for (int i = 1; i < n; ++i) {
    D = v[i].def_stack;
    
    auto A = check(first_stack, v[i], v[i-1], D, fadd);
    auto B = check(second_stack, v[i], v[i-1], 1-D, sadd);

    if (v[i].y < v[i-1].y) {
      if (D==0) fadd++;
      else sadd++;
    }
    else {
      fadd = 0;
      sadd = 0;
      first_stack.clear();
      second_stack.clear();
    }

   // cout << A.x << " " << B.x << endl;

    if (A.x != -1) {
      Ins(second_stack, A, sadd);
    }
    if (B.x != -1) {
      Ins(first_stack, B, fadd);
    }
  }

  int ans = INF;
  if (first_stack.size()) {
    ans = min(ans, (*first_stack.begin()).y + fadd);
  }
  if (second_stack.size()) {
    ans = min(ans, (*second_stack.begin()).y + sadd);
  }

  if (ans == INF) cout << -1;
  else cout << ans;



}