#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 501010
int n;
pair<int, int> range[maxn];

// struct bit {
  // vector<int> data;
  // void resize(int n) { data.resize(n + 1); }
  // int get(int i) {
    // int ans = 0;
    // for (++i; i > 0; i -= i & -i) ans += data[i];
    // return ans;
  // }
  // void upd(int i, int val) {
    // for (++i; i < len(data); i += i & -i) data[i] += val;
  // }
// };

set<int> unfilled;
int filled_val[maxn];
bool is_filling[maxn];
int cur_val = 0;

vector<pair<int, function<void(int)>>> st;
void init(int u);
void process(int u);

void init(int u) {
  if (filled_val[u] != -1) return ;
  is_filling[u] = true;
  st.emplace_back(u, process);
}

void process(int u) {
  auto it = unfilled.lower_bound(range[u].xx);
  if (it == unfilled.end() || *it > range[u].yy) {
    filled_val[u] = ++cur_val;
    is_filling[u] = false;
    unfilled.erase(u);
    return ;
  }
  range[u].xx = *it + 1;
  st.emplace_back(u, process);
  if (*it != u) {
    if (is_filling[*it]) 
      throw "has cycle";
    init(*it);
  }
}

void do_fill(int u) {
  st.clear();
  init(u);
  while (len(st)) {
    auto top = st.back(); st.pop_back();
    top.yy(top.xx);
  }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest ;cin >> ntest;
    while (ntest--) {
      cin >> n;
      rep1(i, n) range[i] = {i, i};
      rep1(i, n) {
        int nxt; cin >> nxt;
        if (nxt == -1) continue;
        range[i].yy = nxt - 1;
        range[nxt].xx = min(range[nxt].xx, i);
      }

      unfilled.clear();
      rep1(i, n) {
        unfilled.insert(i);
        is_filling[i] = 0;
        filled_val[i] = -1;
      }
      cur_val = 0;
      try { 
        rep1(i, n) do_fill(i);
        rep1(i, n) cout << filled_val[i] << ' ';
        cout << '\n';
      } catch (const char* s) {
        cout << "-1\n";
      }
    }

    return 0;
}