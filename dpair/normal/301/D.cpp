#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using std :: sort;
using std :: vector;

#ifndef SCANNER_H_
#define SCANNER_H_ 1
#include <stdio.h>
#include <stdlib.h>
class Scanner
{
private:
  static const int BUFFER_SIZE = 10000;
  char buff[BUFFER_SIZE];
  int buffPos, buffLim;

public:
  Scanner()
  {
    buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
    buffPos = 0;
  }

private:
  inline void flushBuff()
  {
    buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
    if (buffLim == 0) {
      buff[buffLim++] = '\n';
    }
    buffPos = 0;
  }
  inline bool isWS(char t) { return t == ' ' || t == '\n'; }
  inline bool isDig(char t) { return t >= '0' && t <= '9'; }
  void nextPos()
  {
    buffPos++;
    if (buffPos == buffLim) {
      flushBuff();
    }
  }
#define getChar() buff[buffPos]
public:
  inline char getchar()
  {
    char ch = getChar();
    nextPos();
    return ch;
  }
  inline void next(char* s)
  {
    while (isWS(getChar())) {
      nextPos();
    }
    while (!isWS(getChar())) {
      *s = getChar();
      s++;
      nextPos();
    }
    *s = '\0';
  }
  inline void nextLine(char* s)
  {
    while (getChar() != '\n') {
      nextPos();
    }
    if (getChar() == '\n') {
      nextPos();
    }
    while (getChar() != '\n') {
      *s = getChar();
      s++;
      buffPos++;
    }
    *s = '\0';
  }
  inline int nextInt()
  {
    while (!isDig(getChar()) && getChar() != '-') {
      nextPos();
    }
    int sign = (getChar() == '-') ? nextPos(), -1 : 1;
    int res = 0;
    while (isDig(getChar())) {
      res = res * 10 + getChar() - '0';
      nextPos();
    }
    return res * sign;
  }
  inline long long nextLong()
  {
    while (!isDig(getChar()) && getChar() != '-') {
      nextPos();
    }
    long long sign = (getChar() == '-') ? nextPos(), -1 : 1;
    long long res = 0;
    while (isDig(getChar())) {
      res = res * 10 + getChar() - '0';
      nextPos();
    }
    return res * sign;
  }
  inline int n()
  {
    while (getChar() < '0' || getChar() > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    int res = 0;
    while (getChar() >= '0' && getChar() <= '9') {
      res = res * 10 + (getChar() - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nl()
  {
    while (getChar() < '0' || getChar() > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (getChar() >= '0' && getChar() <= '9') {
      res = res * 10 + (getChar() - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nlm(const int MOD)
  {
    while (getChar() < '0' || getChar() > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (getChar() >= '0' && getChar() <= '9') {
      res = (res * 10 + (getChar() - '0')) % MOD;
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline double nextDouble()
  {
    while (isWS(getChar())) {
      nextPos();
    }
    int sign = (getChar() == '-') ? nextPos(), -1 : 1;
    double res = 0;
    while (isDig(getChar())) {
      res = res * 10 + getChar() - '0';
      nextPos();
    }
    if (getChar() == '.') {
      nextPos();
      double ep = 1;
      while (isDig(getChar())) {
        ep *= 0.1;
        res += ep * (getChar() - '0');
        nextPos();
      }
    }
    return sign * res;
  }
  inline char nextChar()
  {
    while (isWS(getChar()))
      nextPos();
    char res = getChar();
    nextPos();
    return res;
  }
#undef getChar
};
Scanner sc;
#endif /* SCANNER_H_ */
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}
typedef long long LL;
#define MAXN 200005
#define block 455
#define limit 70
int n, m;
int bel[MAXN];
struct Quest{
    int l, r, id;
    inline bool operator < (const Quest &tmp) const{
        return bel[l] ^ bel[tmp.l]? l < tmp.l : (bel[l] & 1? r < tmp.r : r > tmp.r);
    }
}q[MAXN];

int cnt[MAXN], a[MAXN];
int cc[limit + 5], tot;
LL ans[MAXN], pre[MAXN];
vector <int> num[MAXN];
inline void Add(int x){
    if(num[x].empty()){
        for (register int i = 1;i * i <= x;++ i){
            if(x % i == 0){
                cnt[i] ++;num[x].emplace_back(i);
                if(i * i != x) cnt[x / i] ++, num[x].emplace_back(x / i);
            }
        }
    }
    else for (register int i = 0;i < num[x].size();i ++) cnt[num[x][i]] ++;
    if(x <= limit) cc[x] ++;
    else for (register int i = x;i <= tot;i += x) cnt[i] ++;
}
struct DPair{
    int l, r, id, pos;
    inline bool operator < (const DPair &tmp) const{
        return pos < tmp.pos;
    }
}b[MAXN << 1];
int Total;
int pref[MAXN];
int main(){
    n = sc.n();m = sc.n();
    for (register int i = 1;i <= n;++ i){
        a[i] = sc.n();
        if(tot < a[i]) tot = a[i];
        bel[i] = (i - 1) / block + 1;
    }
    for (register int i = 1;i <= n;i ++){
        pre[i] = cnt[a[i]];
        for (register int j = 1;j <= limit && j <= a[i];++ j)
            if(a[i] % j == 0) pre[i] += cc[j];
        pre[i] += pre[i - 1];
        Add(a[i]);
    }
    for (register int i = 1;i <= m;++ i){
        q[i].l = sc.n();q[i].r = sc.n();
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    int l = q[1].l, r = l - 1;
    for (register int i = 1;i <= m;++ i){
        if(r < q[i].r) ans[q[i].id] += pre[q[i].r] - pre[r], b[++ Total] = (DPair{r + 1, q[i].r, -q[i].id, l - 1}), r = q[i].r;
        if(l > q[i].l) ans[q[i].id] -= pre[l - 1] - pre[q[i].l - 1] + ((l - q[i].l) << 1), b[++ Total] = (DPair{q[i].l, l - 1, q[i].id, r}), l = q[i].l;
        if(r > q[i].r) ans[q[i].id] -= pre[r] - pre[q[i].r], b[++ Total] = (DPair{q[i].r + 1, r, q[i].id, l - 1}), r = q[i].r;
        if(l < q[i].l) ans[q[i].id] += pre[q[i].l - 1] - pre[l - 1] + ((q[i].l - l) << 1), b[++ Total] = (DPair{l, q[i].l - 1, -q[i].id, r}), l = q[i].l;
    }
    memset(cnt, 0, sizeof(cnt));
    sort(b + 1, b + Total + 1);
    int it = 0;
    for (register int i = 1;i <= Total;++ i){
        while(it < b[i].pos) Add(a[++ it]);
        DPair x = b[i];
        for (register int k = x.l;k <= x.r;++ k)
            ans[abs(x.id)] += (x.id < 0? -1ll : 1ll) * cnt[a[k]];
    }
    for (register int p = 1;p <= limit && p <= tot;++ p){
        for (register int i = 1;i <= n;++ i) pref[i] = pref[i - 1] + (a[i] % p == 0);
        int Cnt = 0;it = 0;
        for (register int i = 1;i <= Total;++ i){
            while(it < b[i].pos) Cnt += (a[++ it] == p);
            DPair x = b[i];
            ans[abs(x.id)] += (x.id < 0? -1ll : 1ll) * Cnt * (pref[x.r] - pref[x.l - 1]);
        }
    }
    for (register int i = 2;i <= m;++ i) ans[q[i].id] += ans[q[i - 1].id];
    for (register int i = 1;i <= m;++ i) ans[q[i].id] += q[i].r - q[i].l + 1;
    for (register int i = 1;i <= m;++ i) fprint(ans[i], 10);
}