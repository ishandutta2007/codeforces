#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MAXL = 5005, MAXK = 55, MOD = 1e9 + 7;

int Add(int a, int b)
{
  int tmp = a + b;
  if (tmp >= MOD)
    tmp -= MOD;
  return tmp;
}

int Sub(int a, int b)
{
  int tmp = a - b;
  if (tmp < 0)
    tmp += MOD;
  return tmp;
}

int Mul(int a, int b)
{
  return (int) (((long long) a * b) % MOD);
}

struct node {
  int p[10], par, sufflink, jelkraj, val;
  node () { memset(p, 0, sizeof p); }
} cvor[MAXL*25];

char s[MAXL];
char a[MAXL], b[MAXL];
int vr=2;
int lenmal, pollen, lenvel;
int dokraja[MAXK][2], dp[MAXK][MAXL*MAXK/2][2];
queue <int> Q;

void Stavi(int poc)
{
  int poz = 1;

  for (int i=poc; i<pollen+poc; i++) {
    int c = s[i] - '0';

    if (!cvor[poz].p[c]) {
      cvor[vr].par = poz;
      cvor[vr].val = c;
      cvor[poz].p[c] = vr++;
    }

    poz = cvor[poz].p[c];
  }

  cvor[poz].jelkraj = 1;
}

void Bfs()
{
  Q.push(1);

  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();

    int suff = cvor[cvor[tmp].par].sufflink;
    if (cvor[tmp].par != 1) {
      for (; suff != 1; suff = cvor[suff].sufflink)
        if (cvor[suff].p[cvor[tmp].val])
          break;

      if (cvor[suff].p[cvor[tmp].val])
        suff = cvor[suff].p[cvor[tmp].val];
    }

    cvor[tmp].sufflink = suff;

    for (int i=0; i<10; i++)
      if (cvor[tmp].p[i])
        Q.push(cvor[tmp].p[i]);
  }
}

int RekDoKraja(int poz, int st, char rijec[MAXK])
{  
  if (poz == lenmal)
    return 1;

  if (dokraja[poz][st] != -1)
    return dokraja[poz][st];

  if (st)
    return dokraja[poz][st] = Mul(10, RekDoKraja(poz + 1, st, rijec));

  return dokraja[poz][st] = Add(Mul(rijec[poz] - '0', RekDoKraja(poz + 1, 1, rijec)),
                                RekDoKraja(poz + 1, 0, rijec));
}

int Rek(int poz, int ind, int st, char rijec[MAXK])
{
  if (poz == lenmal)
    return 0;

  if (dp[poz][ind][st] != -1)
    return dp[poz][ind][st];

  int ret=0;
  for (int i=0; i<10; i++) {    
    if (!st && rijec[poz] - '0' < i)
      break;

    int nst = 1;
    if (!st && rijec[poz] - '0' == i)
      nst = 0;

    int nind = ind;
    for (; nind != 1; nind = cvor[nind].sufflink)
      if (cvor[nind].p[i])
        break;
    
    if (cvor[nind].p[i])
      nind = cvor[nind].p[i];

    if (cvor[nind].jelkraj)
      ret = Add(ret, RekDoKraja(poz + 1, nst, rijec));
    else
      ret = Add(ret, Rek(poz + 1, nind, nst, rijec));
  }

  return dp[poz][ind][st] = ret;
}

int Ima()
{
  for (int i=0; i+pollen<=lenmal; i++) {
    for (int j=0; j+pollen<=lenvel; j++) {
      int da = 1;
      for (int k=0; k<pollen; k++) {
        if (s[j+k] != a[i+k]) {
          da = 0;
          break;
        }
      }

      if (da)
        return 1;
    }
  }

  return 0;
}

int main()
{
  cvor[1].par = cvor[1].sufflink = 1;

  scanf("%s%s%s", s, a, b);
  lenmal = (int) strlen(a); pollen = lenmal / 2;
  
  lenvel = (int) strlen(s);
  for (int i=0; i+pollen<=lenvel; i++)
    Stavi(i);

  Bfs();

  memset(dokraja, -1, sizeof dokraja);
  memset(dp, -1, sizeof dp);
  int rje = Rek(0, 1, 0, b);

  memset(dokraja, -1, sizeof dokraja);
  memset(dp, -1, sizeof dp);    
  int tmp = Sub(Rek(0, 1, 0, a), Ima());
    
  rje = Sub(rje, tmp);
  printf("%d\n", rje);

  return 0;
}