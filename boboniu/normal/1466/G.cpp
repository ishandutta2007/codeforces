#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 1111111
#define maxM 111111
#define P 1000000007

struct node {
  node *go[27], *fail, *f;
  int cnt;
};
node nd[maxN], *r = nd, *root, *c[maxN];
node *append(node *p, int w) {
  if (!p->go[w])
    p->go[w] = r++, p->go[w]->f = p;
  return p->go[w];
}

namespace temp {
int t;
node *q[maxN];

void build() {
  t = 1;
  q[0] = root;
  for (int i = 0; i < t; i++)
    for (int j = 0; j < 26; j++)
      if (q[i]->go[j]) {
        node *v = q[i]->go[j], *p = v->f->fail;
        while (p && !p->go[j])
          p = p->fail;
        if (p)
          v->fail = p->go[j];
        else
          v->fail = root;
        q[t++] = q[i]->go[j];
      }
  for (int i = 0; i < t; i++)
    for (int j = 0; j < 26; j++) {
      if (!q[i]->go[j]) {
        node *p = q[i]->fail;
        if (!p)
          q[i]->go[j] = root;
        else
          q[i]->go[j] = p->go[j];
      }
    }
}

void count() {
  for (int i = t - 1; i >= 1; i--) {
    node *p = q[i];
    p->fail->cnt += p->cnt;
  }
}

} // namespace temp

void z1(string &a, vector<int> &nt) {
  int n = a.size();
  nt = vector<int>(n + 1, 0);
  for (int i = 1, j = 0, k = 0; i < n; i += k, j = max(0, j - k)) {
    for (; i + j < n && a[j] == a[i + j]; ++j)
      ;
    for (nt[i] = j, k = 1; k <= j && nt[k] != j - k; k++)
      nt[i + k] = min(nt[k], j - k);
  }
}
void z2(string &a, vector<int> &nt, string &b, vector<int> &ex) {
  int m = b.size();
  ex = vector<int>(m + 1, 0);
  for (int i = 0, j = 0, k = 0; i < m; i += k, j = max(0, j - k)) {
    for (; i + j < m && a[j] == b[i + j]; ++j)
      ;
    for (ex[i] = j, k = 1; k <= j && k + nt[k] != j; k++)
      ex[i + k] = min(nt[k], j - k);
  }
}

int n, q, tlen;
char t[maxM], s[maxM], tt[maxN];
i64 ans[maxM], cnt[50];
string slev[30];
vector<pair<string, int>> que[maxM], bs;
int main() {
  scanf("%d%d", &n, &q);
  scanf("%s%s", s, t);
  string ss = s;
  for (int i = 0; i <= n; i++) {
    slev[i] = ss;
    if (ss.size() > 1000000 || i == n) {
      tlen = i;
      break;
    }
    ss = ss + string(1, t[i]) + ss;
  }
  int val = 1;
  for (int i = 0; i < q; i++) {
    int lev;
    scanf("%d%s", &lev, tt);
    string ss = tt;
    que[lev].push_back(make_pair(ss, i));
    if (lev >= tlen) {
      bs.push_back(make_pair(ss, i));
    }
  }
  for (int i = 0; i <= tlen; i++) {
    root = r++;
    auto &qu = (i == tlen) ? bs : que[i];
    for (auto q : qu) {
      string s = q.first;
      int id = q.second;
      node *p = root;
      for (auto x : s)
        p = append(p, x - 'a');
      c[id] = p;
    }
    temp::build();
    node *q = root;
    for (auto x : slev[i]) {
      q = q->go[x - 'a'];
      q->cnt += 1;
    }
    temp::count();
    for (auto q : qu) {
      int id = q.second;
      ans[id] = c[id]->cnt;
    }
  }
  int multi = 1;
  string revs = slev[tlen];
  reverse(revs.begin(), revs.end());
  vector<int> nt, revnt;
  z1(slev[tlen], nt);
  z1(revs, revnt);
  for (int i = tlen; i <= n; i++) {
    for (auto q : que[i]) {
      int id = q.second;
      ans[id] = ans[id] * multi % P;
      vector<int> ex, revex;
      string revt = q.first;
      reverse(revt.begin(), revt.end());
      z2(slev[tlen], nt, q.first, ex);
      z2(revs, revnt, revt, revex);
      int m = q.first.size();
      for (int i = 0; i < m; i++) {
        if (ex[i + 1] == m - i - 1 && revex[m - i] == i) {
          ans[id] = (ans[id] + cnt[q.first[i] - 'a']) % P;
        }
      }
    }
    for (int j = 0; j < 26; j++)
      cnt[j] = cnt[j] * 2 % P;
    if (i < n)
      cnt[t[i] - 'a'] = (cnt[t[i] - 'a'] + 1) % P;
    multi = multi * 2 % P;
  }
  for (int i = 0; i < q; i++)
    printf("%lld\n", ans[i]);
}