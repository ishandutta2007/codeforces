#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define point pair<llong, llong>

point operator- (const point& a, const point& b) {
  return {a.xx - b.xx, a.yy - b.yy};
}

llong cross(const point& a, const point& b) {
  return a.xx * b.yy - a.yy * b.xx;
}

#define maxn 2222
int n;
point a[maxn];
string winding;
bool picked[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i].xx >> a[i].yy;
    cin >> winding;
    memset(picked, 0, sizeof picked);

    vector<int> ans;
    int first = (int)(min_element(a, a + n) - a);
    picked[first] = 1;
    ans.push_back(first);

    for (auto w: winding) {
      int nxt = -1;
      int sign = w == 'L' ? -1 : 1;
      rep(i, n) if (!picked[i])
        if (nxt == -1 or cross(a[nxt] - a[ans.back()], a[i] - a[ans.back()]) * sign > 0) 
          nxt = i;
      picked[nxt] = 1;
      ans.push_back(nxt);
    }

    rep(i, n) if (!picked[i]) ans.push_back(i);
    for (auto i: ans) cout << i + 1 << ' ';
    

    return 0;
}