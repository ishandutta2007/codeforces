#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define maxn 2222

string s; int n;
int ec[maxn], temp[maxn], cnt[maxn];
int cost[maxn][2];
int suff[maxn], pos[maxn];

void gensa() {
  rep(i, n) ec[i] = i, pos[i] = s[i];
  for (int i = 1; i < n; i <<= 1) {
    rep(f, n) {
      cost[f][1] = pos[f];
      cost[f][0] = f + i < n ? pos[i + f] + 1: 0;
    }
    rep(t, 2) {
      memset(cnt, 0, sizeof(cnt));
      rep(i, n) cnt[cost[temp[i] = ec[i]][t]]++;
      rep1(i, maxn - 1) cnt[i] += cnt[i - 1];
      for (int i = n; i--; )
        ec[--cnt[cost[temp[i]][t]]] = temp[i];
    }
    pos[ec[0]] = 0;
    llong *lcost = (llong*) cost;
    rep1(f, n - 1)
      pos[ec[f]] = pos[ec[f - 1]] + (lcost[ec[f]] != lcost[ec[f - 1]]);
    //rep(i, n) {
      //clog << i << ' ' << cost[i][0] << ' ' << cost[i][1] << ' ' << (lcost[i] >> 32) << ' ' << (lcost[i] & ((1ll << 32) - 1)) << endl;;
    //}
  }
  rep(i, n) suff[pos[i]] = i;
}

int lcp[maxn];
void genlcp() {
  int x = 0;
  for (int i = 0; i < n; ++i, x && --x) {
    if (pos[i] == n - 1) {x = 0; continue; }
    for (int f = suff[pos[i] + 1]; i + x < n and f + x < n and s[i + x] == s[f + x]; ++x);
    lcp[pos[i]] = x;
  }
}

int findlower(const string& t) {
  int l = 0, r = n;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (s.substr(suff[mid], t.size()) >= t) r = mid;
    else l = mid + 1;
  }
  return l;
}

int findupper(const string& t) {
  int l = 0, r = n;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (s.substr(suff[mid], t.size()) > t) r = mid;
    else l = mid + 1;
  }
  return l;
}

string head, tail;
vector<int> tp;
int main() {
  ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
  cin >> s; n = s.size();
  cin >> head >> tail;

  gensa();
  genlcp();
  //rep(i, n) clog << suff[i] << ' ' << s.substr(suff[i]) << endl;
  int hl = findlower(head), hu = findupper(head);
  int tl = findlower(tail), tu = findupper(tail);

  //clog << hl << ' ' << hu << ' ' << tl << ' ' << tu << endl;

  for (int i = tl; i < tu; ++i) tp.push_back(suff[i]);
  sort(tp.begin(), tp.end());

  llong ans = 0;
  for (int i = hl; i < hu; ++i) {
    int p = suff[i] + max((int)head.size() - (int)tail.size(), 0);
    if (i > hl)
      p = max(p, suff[i] + (lcp[i - 1] - (int)tail.size() + 1));
    int add = tp.end() - lower_bound(tp.begin(), tp.end(), p);
    ans += add;
    //clog << suff[i] << ' ' << add << endl;
  }
  cout << ans;

  return 0;
}