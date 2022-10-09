#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define ii pair<int, int>
#define maxn 555
int n, m, k;
pair<int, int> a[maxn];
int findLowestNotCovered(multiset<ii> seg) {
  int ans = 1;
  for (auto i: seg) {
    if (ans > i.yy) continue;
    if (ans < i.xx) break;
    ans = i.yy + 1;
  }
  return ans;
}

bool ok(int dis) {
  map<int, pair<vector<ii>, vector<ii>>> events;
  events[1];
  events[n];
  auto getEvents = [&](int num) -> pair<vector<ii>, vector<ii>>& {
    if (num > 1) events[num - 1];
    if (num < n) events[num + 1];
    return events[num];
  };
  rep(i, k) {
    int left = a[i].xx - dis;
    int right = a[i].xx + dis;
    int top = a[i].yy - dis;
    int bot = a[i].yy + dis;
    getEvents(left).xx.push_back({top, bot});
    getEvents(right + 1).yy.push_back({top, bot});
  }
  multiset<pair<int, int>> segs;
  int minX = n + 1, minY = m + 1;
  for (auto i: events) {
    for (auto addingSeg : i.yy.xx) segs.insert(addingSeg);
    for (auto removingSeg : i.yy.yy) segs.erase(segs.find(removingSeg));
    if (i.xx < 1 or i.xx > n) continue;
    int t = findLowestNotCovered(segs);
    if (t > m) continue;
    assert(t >= 1); assert(t <= m);
    minX = min(minX, i.xx);
    minY = min(minY, t);
  }

  if (minX > n and minY > m)
    return true;
  {
    int left = minX;
    int right = minX + dis * 2;
    int top = minY;
    int bot = minY + 2 * dis;
    getEvents(left).xx.push_back({top, bot});
    getEvents(right + 1).yy.push_back({top, bot});
  }

  segs.clear();
  for (auto i: events) {
    for (auto addingSeg : i.yy.xx) segs.insert(addingSeg);
    for (auto removingSeg : i.yy.yy) segs.erase(segs.find(removingSeg));
    if (i.xx < 1 or i.xx > n) continue;
    int t = findLowestNotCovered(segs);
    if (t > m) continue;
    return false;
  }
  return true;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    rep(i, k) {
      cin >> a[i].xx >> a[i].yy;
    }

    llong l = 0, r = max(n, m);
    while (l < r) {
      llong mid = l + (r - l) / 2;
      if (ok((int)mid)) r = mid;
      else l = mid + 1;
    }
    cout << l;

    return 0;
}