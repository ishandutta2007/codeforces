#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

struct Update {
  int i;
  string value;
};

const int N = (int) 2e5 + 7;
int n, q, a[N], ret[N], aib[N];
string s;
vector<Update> updates;
int mod_pos[N], mod_val[N];

void add(int i, int x) {
  while (i <= n) {
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

void clr() {
  for (int i = 1; i <= n; i++) {
    aib[i] = 0;
  }
}

int sum(int l, int r) {
  if (l < 1) {
    l = 1;
  }
  if (r > n) {
    r = n;
  }
  if (l > r) {
    return 0;
  }
  return pre(r) - pre(l - 1);
}

void add(string zero, string poz, string neg) {
  clr();
  set<int> mic, mare;
  for (int i = 1; i <= n; i++) {
    a[i] = 3;
    if (s[i - 1] == zero[0]) a[i] = 0;
    if (s[i - 1] == poz[0]) a[i] = +1;
    if (s[i - 1] == neg[0]) a[i] = -1;
    if (a[i] == -1) {
      mic.insert(i);
    }
    if (a[i] == +1) {
      mare.insert(i);
    }
    assert(a[i] != 3);
    if (a[i] == 0) {
      add(i, +1);
    }
  }
  for (int i = 1; i <= q; i++) {
    mod_pos[i] = updates[i - 1].i;
    mod_val[i] = 3;
    if (updates[i - 1].value == zero) mod_val[i] = 0;
    if (updates[i - 1].value == poz) mod_val[i] = +1;
    if (updates[i - 1].value == neg) mod_val[i] = -1;
    assert(mod_val[i] != 3);
  }
  for (int it = 0; it <= q; it++) {
    if (it) {
      if (a[mod_pos[it]] == 0) add(mod_pos[it], -1);
      if (a[mod_pos[it]] == -1) {
        mic.erase(mod_pos[it]);
      }
      if (a[mod_pos[it]] == +1) {
        mare.erase(mod_pos[it]);
      }
      a[mod_pos[it]] = mod_val[it];
      if (a[mod_pos[it]] == -1) {
        mic.insert(mod_pos[it]);
      }
      if (a[mod_pos[it]] == +1) {
        mare.insert(mod_pos[it]);
      }

      if (a[mod_pos[it]] == 0) {
        add(mod_pos[it], +1);
      }
    }
    int pre1 = 0, suf1 = 0, pre2 = 0, suf2 = 0;
    int first_mic = -1, first_mare = -1;
    if (!mic.empty()) {
      first_mic = *mic.begin();
    }
    if (!mare.empty()) {
      first_mare = *mare.begin();
    }
    if (first_mic == -1) {
      pre1 = n;
      suf1 = n + 1;
    } else {
      if (first_mare == -1) {
        pre1 = first_mic - 1;
        suf1 = n + 1;
      } else {
        if (first_mare <= first_mic) {
          pre1 = n;
          suf1 = n + 1;
        } else {
          pre1 = first_mic - 1;
          suf1 = first_mare;
        }
      }
    }
    int last_mic = -1, last_mare = -1;
    if (!mic.empty()) {
      auto it = mic.end();
      it--;
      last_mic = *it;
    }
    if (!mare.empty()) {
      auto it = mare.end();
      it--;
      last_mare = *it;
    }
    if (last_mic == -1) {
      pre2 = 0;
      suf2 = 1;
    } else {
      if (last_mare == -1) {
        suf2 = last_mic + 1;
        pre2 = 0;
      } else {
        if (last_mic <= last_mare) {
          pre2 = 0;
          suf2 = 1;
        } else {
          suf2 = last_mic + 1;
          pre2 = last_mare;
        }
      }
    }
    assert(pre1 < suf1);
    assert(pre2 < suf2);
    ret[it] += sum(1, min(pre1, pre2));
    ret[it] += sum(suf1, pre2);
    ret[it] += sum(max(suf1, suf2), n);
    ret[it] += sum(suf2, pre1);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> q >> s;
  updates.resize(q);
  for (auto &it : updates) {
    cin >> it.i >> it.value;
  }
  add("R", "S", "P");
  add("S", "P", "R");
  add("P", "R", "S");
  for (int i = 0; i <= q; i++) {
    cout << ret[i] << "\n";
  }

}