#include <bits/stdc++.h>

using namespace std;

bool home = 1;

class SuffixArray {
private:
  bool stringSet;
  string s;
public:
  explicit SuffixArray(string s) : s(s), stringSet(1) {
  }

  SuffixArray() : stringSet(0) {
  }

  SuffixArray(SuffixArray& other) = default;
  SuffixArray(SuffixArray&& other) = default;
  ~SuffixArray() = default;

  SuffixArray operator = (SuffixArray& other) {}
  SuffixArray operator = (SuffixArray&& other) noexcept {}


  bool isStringSet() {
    return stringSet;
  }

  void setString(string newString) {
    stringSet = 1;
    s = newString;
  }

  void unsetString() {
    stringSet = 0;
  }

  vector<int> computeSuffixOrder() {
    assert(stringSet);

    map<char, int> stringChars;
    for (auto &ch : s) {
      stringChars[ch] = 0;
    }

    int maxValue = 0;

    for (auto &it : stringChars) {
      it.second = maxValue++;
    }

    int n = (int) s.size();

    vector<int> v(n);
    vector<int> cnt(n, 0);
    vector<int> order(n, -1);
    vector<int> equivalenceClass(n);
    vector<int> equivalenceClassCopy(n);
    vector<int> newOrder(n);

    for (int i = 0; i < n; i++) {
      v[i] = stringChars[s[i]];
      cnt[v[i]]++;
      equivalenceClass[i] = v[i];
    }
    for (int i = 1; i < maxValue; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
      order[--cnt[v[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
      cnt[i] = 0;
    }

    int currentLength = 1;
    while (currentLength < n) {
      for (auto &i : order) {
        cnt[equivalenceClass[i]]++;
        equivalenceClassCopy[i] = equivalenceClass[i];
      }
      for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
      }
      for (int it = n - 1; it >= 0; it--) {
        int j = (order[it] - currentLength + n) % n;
        newOrder[--cnt[equivalenceClass[j]]] = j;
      }
      order = newOrder;
      int currentClass = 0;
      for (int j = 0; j < n; j++) {
        currentClass += (j == 0 || make_pair(equivalenceClassCopy[order[j]], equivalenceClassCopy[(order[j] + currentLength) % n]) != make_pair(equivalenceClassCopy[order[j - 1]], equivalenceClassCopy[(order[j - 1] + currentLength) % n]));
        equivalenceClass[order[j]] = currentClass - 1;
        cnt[j] = 0;
      }
      currentLength *= 2;
    }

    return order;
  }

  pair<vector<int>, vector<int>> computeSuffixOrderAndLcp() {
    assert(stringSet);

    map<char, int> stringChars;
    for (auto &ch : s) {
      stringChars[ch] = 0;
    }

    int maxValue = 0;

    for (auto &it : stringChars) {
      it.second = maxValue++;
    }

    int n = (int) s.size();

    vector<int> v(n);
    vector<int> cnt(n, 0);
    vector<int> order(n, -1);
    vector<int> equivalenceClass(n);
    vector<int> equivalenceClassCopy(n);
    vector<int> newOrder(n);

    for (int i = 0; i < n; i++) {
      v[i] = stringChars[s[i]];
      cnt[v[i]]++;
      equivalenceClass[i] = v[i];
    }
    for (int i = 1; i < maxValue; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
      order[--cnt[v[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
      cnt[i] = 0;
    }

    int currentLength = 1;
    while (currentLength < n) {
      for (auto &i : order) {
        cnt[equivalenceClass[i]]++;
        equivalenceClassCopy[i] = equivalenceClass[i];
      }
      for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
      }
      for (int it = n - 1; it >= 0; it--) {
        int j = (order[it] - currentLength + n) % n;
        newOrder[--cnt[equivalenceClass[j]]] = j;
      }
      order = newOrder;
      int currentClass = 0;
      for (int j = 0; j < n; j++) {
        currentClass += (j == 0 || make_pair(equivalenceClassCopy[order[j]], equivalenceClassCopy[(order[j] + currentLength) % n]) != make_pair(equivalenceClassCopy[order[j - 1]], equivalenceClassCopy[(order[j - 1] + currentLength) % n]));
        equivalenceClass[order[j]] = currentClass - 1;
        cnt[j] = 0;
      }
      currentLength *= 2;
    }

    vector<int> lcp(n, 0);
    int k = 0;

    for (auto &i : equivalenceClass) {
      k = max(0, k - 1);
      if (i) {
        int a = order[i - 1], b = order[i];
        while (max(a, b) + k < n && v[a + k] == v[b + k]) {
          k++;
        }
        lcp[i] = k;
      }
    }

    vector<int> newLcp(n - 1);
    for (int i = 0; i < n - 1; i++) {
      newLcp[i] = lcp[i + 1];
    }

    return {order, newLcp};
  }
};


typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

const int INF = (int) 1e9;
string s1, s2, s3;
int n1, n2, n3;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }


  string s;
  cin >> s1 >> s2 >> s3;
  n1 = (int) s1.size();
  n2 = (int) s2.size();
  n3 = (int) s3.size();

  s = s1 + "0" + s2 + "1" + s3 + "2";

  SuffixArray suf(s);

  auto dt = suf.computeSuffixOrderAndLcp();

  function<int(int, int)> getMinimum = [&] (int l, int r) {
    assert(l != r);
    if (l > r) {
      swap(l, r);
    }
    r--;
    assert(0 <= l && l <= r && r <= (int) dt.second.size());
    int sol = INF;
    for (int i = l; i <= r; i++) {
      sol = min(sol, dt.second[i]);
    }
    return sol;
  };

  vector<int> where((int) s.size(), -1);

  for (int i = 0; i < (int) s.size(); i++) {
    where[dt.first[i]] = i;
  }

  for (auto &x : where) {
    assert(x != -1);
  }

  vector<int> type((int) s.size(), 0);
  vector<int> cnt(min({n1, n2, n3}) + 1, 0);

  for (int i = 0; i < n1; i++) type[where[i]] = 1;
  for (int i = 0; i < n2; i++) type[where[n1 + 1 + i]] = 2;
  for (int i = 0; i < n3; i++) type[where[n1 + 1 + n2 + 1 + i]] = 3;


  vector<int> stk;
  vector<int> l((int) dt.second.size());
  vector<int> r((int) dt.second.size());

  for (int i = 0; i < (int) dt.second.size(); i++) {
    while (!stk.empty() && dt.second[i] < dt.second[stk.back()]) stk.pop_back();
    if (stk.empty()) l[i] = 0;
    else l[i] = stk.back() + 1;
    stk.push_back(i);
  }

  stk.clear();
  for (int i = (int) dt.second.size() - 1; i >= 0; i--) {
    while (!stk.empty() && dt.second[i] <= dt.second[stk.back()]) stk.pop_back();
    if (stk.empty()) r[i] = (int) dt.second.size() - 1;
    else r[i] = stk.back() - 1;
    stk.push_back(i);
  }
  stk.clear();
  vector<vector<int>> pref(3, vector<int>((int) type.size(), 0));

  for (int x = 0; x < 3; x++) {
    int cur = 0;
    for (int i = 0; i < (int) type.size(); i++) {
      cur += (type[i] == x + 1);
      pref[x][i] = cur;
    }
  }

  function<int(int, int, int)> gcnt = [&] (int l, int r, int x) {
    int sol = pref[x][r];
    if (l) sol -= pref[x][l - 1];
    return sol;
  };


  function<int(int, int)> get = [&] (int l, int r) {
    return mul(mul(gcnt(l, r, 0), gcnt(l, r, 1)), gcnt(l, r, 2));
  };

  for (int it = 0; it < (int) dt.second.size(); it++) {

    int sol = 0;
    addup(sol, get(l[it], r[it] + 1));
    addup(sol, -get(l[it], it));
    addup(sol, -get(it + 1, r[it] + 1));

    addup(cnt[dt.second[it]], sol);
  }

  for (int i = (int) cnt.size() - 2; i >= 1; i--) {
    addup(cnt[i], cnt[i + 1]);
  }

  for (int i = 1; i < (int) cnt.size(); i++) {
    cout << cnt[i] << " ";
  }
  cout << "\n";

  return 0;
}