#include<bits/stdc++.h>
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
using namespace std;

ii getinfo(const string& s) {
  vector<char> st;
  for (auto& i: s) {
    if (i == '(') {
      st.push_back(i);
      continue;
    }
    if (!len(st)) st.push_back(i);
    else if (st.back() == '(') st.pop_back();
    else st.push_back(i);
  }
  ii ans;
  for (auto i: st) 
    (i == '(' ? ans.xx : ans.yy)++;
  return ans;
}

#define maxn 301010
int cnto[maxn] = {0}, cntc[maxn] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  llong ans = 0;
  rep(i, n) {
    string s; cin >> s;
    ii info = getinfo(s);
    if (info.xx and info.yy) continue;
    if (info.xx) {
      ans += cntc[info.xx];
      cnto[info.xx]++;
    }
    else if (info.yy) {
      ans += cnto[info.yy];
      cntc[info.yy]++;
    }
    else {
      ans += 2 * cntc[0] + 1;
      cntc[0]++;
    }
  }
  cout << ans;

  return 0;
}