#include <bits/stdc++.h>
using namespace std;
#define min(...) minn(__VA_ARGS__)
#define max(...) maxx(__VA_ARGS__)
#define stringio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
char _;
typedef long long ll;
typedef pair<int,int> pii;
#define getchar_unlocked getchar
template<typename t>constexpr const t minn(const t x,const t y){return x<y?x:y;}
template<typename t,typename ...r>constexpr const t minn(const t x,const r ...xs){return minn(x,minn(xs...));}
template<typename t>constexpr const t maxx(const t x,const t y){return x>y?x:y;}
template<typename t,typename ...r>constexpr const t maxx(const t x,const r ...xs){return maxx(x,maxx(xs...));}
template <typename t> void scan (t& x) {do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MAXN = 1005;
int cnt[27], cnt2[27];
int main() {
    stringio();
    int q; string s,t,p;
    cin >> q;
    while (q--) {
      memset(cnt,0,sizeof cnt); memset(cnt2, 0, sizeof cnt2);
      cin >> s >> t >> p;
      int curtind = 0;
      for (int i = 0; i < s.length(); i++) cnt[s[i]-'a']++;
      for (int i = 0; i < p.length(); i++) cnt[p[i]-'a']++;
      for (int i = 0; i < t.length(); i++) cnt2[t[i]-'a']++;
      for (int i = 0; i < 26; i++) if (cnt2[i] > cnt[i]) {cout << "NO\n";goto done;}
      for (int i = 0; i < s.length(); i++) {
        while (curtind < t.length() && t[curtind] != s[i]) curtind++;
        if (curtind++ >= t.length()) {cout << "NO\n"; goto done;}
      }
      cout << "YES\n";
      done:;
    }
    return 0;
}