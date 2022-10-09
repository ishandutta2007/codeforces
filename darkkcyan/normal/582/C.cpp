#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 201010
int n;
int a[maxn];
vector<int> group[maxn];

llong process(int x) {
  vector<int> lookup(n + 1, 0);
  vector<llong> prefsum(1, 0);
  rep(i, len(group[x])) {
    lookup[group[x][i]] = i + 1;
    prefsum.push_back(prefsum[i] + group[x][i]);
  }

  rep1(i, n) if (lookup[i] == 0)
    lookup[i] = lookup[i - 1];

  assert(n % x == 0);
  vector<int> maxInRing(x, -1);
  rep(i, n) {
    int pos = i % len(maxInRing);
    maxInRing[pos] = max(maxInRing[pos], a[i]);
  }

  // cheated a little bit using string :)
  string s(n, '0');
  rep(i, n) {
    if (a[i] == maxInRing[i % len(maxInRing)])
      s[i] = '1';
  }
  // clog << s << endl;
  vector<int> groupOf1;
  for (char* t = strtok(&s[0], "0"); t; t = strtok(0, "0"))
    groupOf1.push_back((int)strlen(t));

  assert(len(groupOf1));
  if (len(groupOf1) == 1 and groupOf1[0] == n)
    return 1ll * n * len(group[x]);

  if (s[0] == '1' and s.back() == '1') {
    groupOf1[0] += groupOf1.back();
    groupOf1.pop_back();
  }
  llong res = 0;
#define count(num) (((num) + 1) * lookup[num] - x * prefsum[lookup[num]])
  for (auto i: groupOf1) {
    int l = lookup[i];
    res += 1ll * (i + 1) * l - prefsum[l];
  }

  return res;
#undef count
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i];
    rep1(i, n - 1) {
      group[__gcd(i, n)].push_back(i);
    }

    llong ans = 0;
    rep1(i, n) if (len(group[i]))
      ans += process(i);

    cout << ans;

    return 0;
}