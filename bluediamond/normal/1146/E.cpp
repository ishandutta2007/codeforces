#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n, q, a[N], tp[N], x[N], eid[N], suf[N], nrm[N], nemo[N];

struct T {
  int l, r, i;
};

bool operator < (T a, T b) {
  return a.l < b.l;
}

struct F {
  int x;
  int i;
};

bool operator < (F a, F b) {
  return a.x < b.x;
}

int nadal, aib[2 * N];

void add(int i, int x) {
  while (i <= nadal) {
    aib[i] += x;
    i += i & (-i);
  }
}

int pre(int i) {
  int ret = 0;
  while (i) {
    ret += aib[i];
    i -= i & (-i);
  }
  return ret;
}

struct SufAutomaton {
  int suf, query;
};

bool operator < (SufAutomaton a, SufAutomaton b) {
  return a.suf > b.suf;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= q; i++) {
    string s;
    cin >> s >> x[i];
    if (s == ">") tp[i] = +1;
    else tp[i] = -1;
  }
  for (int i = 1; i <= n; i++) eid[i] = -1;
  for (int itr = 1; itr >= -1; itr -= 2) {
    vector<F> nums;
    for (int i = 1; i <= q; i++) if (tp[i] == itr) nums.push_back({x[i], i});
    vector<T> segs;
    for (int i = 1; i <= n; i++) {
      int l = min(a[i], -a[i]), r = max(a[i], -a[i]);
      if (itr == 1) r--; else l++;
      segs.push_back({l, r, i});
    }
    segs.push_back({-(int) 1e9, (int) 1e9, 0});
    sort(segs.begin(), segs.end());
    sort(nums.begin(), nums.end());
    int l = 0, r = (int) nums.size() - 1;
    set<int> index;
    for (int i = 1; i <= q; i++) if (tp[i] == itr) index.insert(i);
    for (auto &it : segs) {
      while (l <= r && nums[r].x > it.r) index.erase(nums[r--].i);
      while (l <= r && nums[l].x < it.l) index.erase(nums[l++].i);
      if (index.empty()) {
        eid[it.i] = max(eid[it.i], -1);
      } else {
        auto nd = index.end();
        nd--;
        eid[it.i] = max(eid[it.i], *nd - 1);
      }
    }
  }
  for (int i = 1; i <= n; i++) eid[i]++, eid[i] += !eid[i];
  for (int j = 1; j <= q; j++) x[j] = max(x[j], x[j] + tp[j]);
  for (int j = q; j >= 1; j--) suf[j] = max(suf[j + 1], suf[j + 1] - tp[j]);
  map<int, int> tsitsipas;
  for (int i = 1; i <= n; i++) tsitsipas[a[i]] = 0;
  for (int j = 1; j <= q; j++) tsitsipas[x[j]] = 0;
  for (auto &it : tsitsipas) it.second = ++nadal;
  for (int i = 1; i <= n; i++) nrm[i] = a[i], a[i] = tsitsipas[a[i]];
  for (int j = 1; j <= q; j++) x[j] = tsitsipas[x[j]];
  vector<SufAutomaton> vls;
  for (int i = 1; i <= n; i++) vls.push_back({eid[i], i});
  sort(vls.begin(), vls.end());
  int done = q + 1;
  for (auto &it : vls) {
    while (done > it.suf) {
      done--;
      add(x[done], +1);
    }
    nemo[it.query] = pre(a[it.query]);
  }
  for (int i = 1; i <= n; i++) if ((1 + suf[eid[i]] + nemo[i]) & 1) cout << nrm[i] << " "; else cout << -nrm[i] << " ";
  cout << "\n";
}