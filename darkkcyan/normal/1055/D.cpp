#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < (n); )
#define rep1(i,n) for (int i = 0; i ++ < (n); )
#define len(x) ((int)x.size())
#define lamb(args, ret) [&]args {return ret;}
#define rem1 ((llong)1e9 + 8181)
#define lul pair<llong, unsigned llong>

template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}
vector<lul> p29(1, {1, 1});
lul getp29(int i) {
  while (len(p29) <= i) 
    p29.push_back({
        p29.back().xx * 29 % rem1,
        p29.back().yy * 29
    });
  return p29[i];
}

vector<lul> genhash(const string& a) {
  vector<lul> ans(1, {a[0] - 'a' + 1, a[0] - 'a' + 1});
  rep1(i, len(a) - 1) {
    char ch = char(a[i] - 'a' + 1);
    ans.push_back(ans.back());
    ans.back().xx = (ans.back().xx * 29 + ch) % rem1;
    ans.back().yy = (ans.back().yy * 29 + ch);
  }

  return ans;
}

lul query(const vector<lul>& hs, int l, int r) {
  lul ans = hs[r];
  if (l-- == 0) return ans;
  lul t = hs[l];
  t.xx *= getp29(r - l).xx;
  t.yy *= getp29(r - l).yy;
  (ans.xx -= t.xx) %= rem1;
  ans.yy -= t.yy;
  if (ans.xx < 0) ans.xx += rem1;
  return ans;
}
int findorc(const string& s, lul h0, int anslen) {
  vector<lul> hs = genhash(s);
  //clog << s << ' ' << anslen << endl;
  rep(f, len(hs) - anslen + 1) {
    //clog << query(hs, f, f + anslen - 1) << endl;
    if (query(hs, f, f + anslen - 1) == h0) return f;
  }
  return -1;
}


#define maxn 3010
int n;
string vars[maxn], newvars[maxn];

void noAns() {
  puts("NO");
  exit(0);
}

ii diff(const string& a, const string& b) {
  assert(len(a) == len(b));
  int l = 0, r = len(a) - 1;
  while (l < len(a) and a[l] == b[l]) ++l;
  if (l == len(a)) return {-1, -1};
  while (r >= 0 and a[r] == b[r]) -- r;
  return {l, r};
}

ii difflist[maxn];
pair<string, string> getdiffval(int i) {
  int l = difflist[i].xx, le = difflist[i].yy - l + 1;
  return {
    vars[i].substr(l, le),
    newvars[i].substr(l, le)
  };
}

int main(void ){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  rep(i, n) cin >> vars[i];
  int non = -1;
  rep(i, n) {
    cin >> newvars[i];
    difflist[i] = diff(vars[i], newvars[i]);
    if (difflist[i].xx != -1) non = i;
  }
  rep(i, n) {
    if (difflist[i].xx == -1) continue;
    if (getdiffval(i) != getdiffval(non)) noAns();
  }

  assert(non != -1);

  int exl = 0, exr = 0;
  while (true) {
    if (difflist[non].xx - exl < 1) break;
    bool ok = 1;
    char ch1 = vars[non][difflist[non].xx - exl - 1];
    char ch2 = newvars[non][difflist[non].xx - exl - 1];
    rep(i, n) {
      if (difflist[i].xx == -1) continue;
      if (difflist[i].xx - exl - 1 < 0) {
        ok = 0;
        break;
      }
      if (vars[i][difflist[i].xx - exl - 1] != ch1) {
        ok = false;
        break;
      }
      if (newvars[i][difflist[i].xx - exl - 1] != ch2) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
    ++exl;
  }
  while (true) {
    if (difflist[non].yy + exr >= len(vars[non]) - 1) break;
    bool ok = 1;
    char ch1 = vars[non][difflist[non].yy + exr + 1];
    char ch2 = newvars[non][difflist[non].yy + exr + 1];
    rep(i, n) {
      if (difflist[i].xx == -1) continue;
      if (difflist[i].yy + exl + 1 > len(vars[i])) {
        ok = 0;
        break;
      }
      if (vars[i][difflist[i].yy + exr + 1] != ch1) {
        ok = false;
        break;
      }
      if (newvars[i][difflist[i].yy + exr + 1] != ch2) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
    ++exr;
  }
  ii t = difflist[non];
  t.xx -= exl;
  t.yy += exr;
  pair<string, string> ans = {
    vars[non].substr(t.xx, t.yy - t.xx + 1),
    newvars[non].substr(t.xx, t.yy - t.xx + 1)
  };
  lul h0 = genhash(ans.xx).back();
  rep(i, n) {
    int u = findorc(vars[i], h0, len(ans.xx));
    if (u != -1) {
      for (int f = u, g = len(ans.xx); g--; ++f) {
        vars[i][f] = ans.yy[f - u];
      }
    }
    if (vars[i] != newvars[i]) noAns();
  }

  cout << "YES\n" << ans.xx << '\n' << ans.yy;

  return 0;
}