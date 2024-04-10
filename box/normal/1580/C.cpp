#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

// begin fast read template by CYJian (source:
// https://www.luogu.com.cn/paste/i11c3ppx)

namespace io {
const int __SIZE = (1 << 21) + 1;
char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1,
                                           __c, qu[55];
int __f, qr, _eof;
#define Gc()                                                                   \
  (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),               \
               (iS == iT ? EOF : *iS++))                                       \
            : *iS++)
inline void flush() { fwrite(obuf, 1, oS - obuf, stdout), oS = obuf; }
inline void gc(char &x) { x = Gc(); }
inline void pc(char x) {
  *oS++ = x;
  if (oS == oT)
    flush();
}
inline void pstr(const char *s) {
  int __len = strlen(s);
  for (__f = 0; __f < __len; ++__f)
    pc(s[__f]);
}
inline void gstr(char *s) {
  for (__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)
    __c = Gc();
  for (; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc())
    *s = __c;
  *s = 0;
}
template <class I> inline bool gi(I &x) {
  _eof = 0;
  for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) {
    if (__c == '-')
      __f = -1;
    _eof |= __c == EOF;
  }
  for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc())
    x = x * 10 + (__c & 15), _eof |= __c == EOF;
  x *= __f;
  return !_eof;
}
template <class I> inline void print(I x) {
  if (!x)
    pc('0');
  if (x < 0)
    pc('-'), x = -x;
  while (x)
    qu[++qr] = x % 10 + '0', x /= 10;
  while (qr)
    pc(qu[qr--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
} // namespace io
using io::gc;
using io::gi;
using io::gstr;
using io::pc;
using io::print;
using io::pstr;

// end fast read template by CYJian

const int TH = 200;

int psum[200005];
int total[200005], y[200005];

struct event {
  int t, mod, dt;
  const bool operator<(const event &o) const { return t < o.t; }
};

int dts[TH + 5][TH + 5];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  gi(n), gi(m);
  for (int i = 1; i <= n; i++) {
    gi(total[i]), gi(y[i]);
    total[i] += y[i];
  }
  vector<pair<int, pii>> ops;
  map<int, int> start;
  for (int i = 0; i < m; i++) {
    int op, k;
    gi(op), gi(k);
    if (op == 1)
      start[k] = i;
    else {
      ops.pb({k, {start[k], i}});
      start.erase(k);
    }
  }
  for (auto [i, j] : start)
    ops.pb({i, {j, m}});
  vector<event> evs;
  for (auto [tr, be] : ops) {
    auto [l, r] = be;
    if (total[tr] < TH) {
      int cnt = (r - l + total[tr] - 1) / total[tr];
      auto add = [&](int begin, int dt) {
        int pc = cnt;
        if (begin + total[tr] * (pc - 1) >= r) {
          pc--;
          psum[r] += dt;
        }
        if (pc) {
          evs.pb({begin, total[tr], dt});
          evs.pb({begin + total[tr] * pc, total[tr], -dt});
        }
      };
      add(l + total[tr] - y[tr], 1);
      add(l + total[tr], -1);
    } else {
      int pos = l;
      while (pos < r) {
        psum[min(r, pos + total[tr] - y[tr])]++;
        psum[min(r, pos + total[tr])]--;
        pos += total[tr];
      }
    }
  }
  sort(all(evs));
  int po = 0;
  for (int i = 0; i < m; i++) {
    while (po != evs.size() && evs[po].t == i) {
      dts[evs[po].mod][i % evs[po].mod] += evs[po].dt;
      po++;
    }
    for (int r = 1; r <= TH; r++)
      psum[i] += dts[r][i % r];
  }
  for (int i = 1; i < m; i++)
    psum[i] += psum[i - 1];
  for (int i = 0; i < m; i++)
    print(psum[i]), pc('\n');
}