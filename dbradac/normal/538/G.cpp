#include <cstdio>
#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const int POL = 2000006, MAX = 2 * POL;

P Presjek(P a, P b)
{
  return P(max(a.X, b.X), min(a.Y, b.Y));
}

P nej[MAX];
int l, n;
ll t[MAX], x[MAX], y[MAX];
P p[MAX];
int nemoze[MAX];

ll NaGore(ll a, ll b)
{
  int st = (a < 0) ^ (b < 0);

  if (!a)
    return 0;
  if (!st)
    return (abs(a) - 1) / abs(b) + 1;
  return -(abs(a) / abs(b));
}

ll NaDolje(ll a, ll b)
{
  int st = (a < 0) ^ (b < 0);

  if (!a)
    return 0;
  if (!st)
    return abs(a) / abs(b);
  return -((abs(a) - 1) / abs(b) + 1);
}

void Ispis(int px)
{
  int ind = px + POL;
  int py, vr=0;

  if (((nej[ind].X + px) & 1) == (l & 1))
    py = nej[ind].X;
  else
    py = nej[ind].X + 1;

  for (int i=0; i<n-1; i++) {
    int deltaT, a, b;
    ll trebx, treby;
    if (i < n-2) {
      deltaT = p[i+1].X - p[i].X;
      a = (int) p[i].Y;
      b = (int) p[i+1].Y;
      trebx = x[b] - x[a] - NaDolje(t[b] - t[a], l) * px;
      treby = y[b] - y[a] - NaDolje(t[b] - t[a], l) * py;    
      vr += deltaT;
    }
    else {
      a = (int) p[n-2].Y;
      trebx = NaGore(t[a], l) * px - x[a];
      treby = NaGore(t[a], l) * py - y[a];
      deltaT = l - vr;
    }

    for (int j=0; j<deltaT; j++) {
      if (trebx > 0) {
        printf("R");
        trebx--;
      }
      else if (trebx < 0) {
        printf("L");
        trebx++;
      }
      else if (treby > 0) {
        printf("U");
        treby--;
      }
      else {
        printf("D");
        treby++;
      }
    }
  }

  printf("\n");
}

int main()
{
  scanf("%d%d", &n, &l); n+=2;

  t[0] = x[0] = y[0] = 0;
  p[0] = P(0, 0);
  t[1] = x[1] = y[1] = 0;
  p[1] = P(l, 1);

  for (int i=2; i<n; i++) {
    scanf("%I64d%I64d%I64d", &t[i], &x[i], &y[i]);
//    cin >> t[i] >> x[i] >> y[i];
    p[i] = P(t[i] % l, i);
    if ((t[i] & 1) != ((x[i] + y[i]) & 1)) {
      printf("NO\n");
      return 0;
    }
  }

  if (l == 1) {
    int pr[4] = {1, 0, -1, 0};
    int ps[4] = {0, 1, 0, -1};
    char c[5] = "RULD";

    int da=0;
    for (int i=0; i<4; i++) {
      int ne = 0;
      for (int j=2; j<n; j++)
        if (!(t[j] * pr[i] == x[j] && t[j] * ps[i] == y[j]))
          ne = 1;
      if (!ne) {
        printf("%c\n", c[i]);
        da = 1;
        break;
      }
    }

    if (!da)
      printf("NO\n");

    return 0;
  }

  sort(p, p+n);

  for (int i=0; i<MAX; i++)
    nej[i] = P(-l, l);

  for (int i=0; i<n-1; i++) {
    int a = (int) p[i].Y;
    int b = (int) p[i+1].Y;        
    ll deltaT = p[i+1].X - p[i].X;
    ll k = NaDolje(t[b] - t[a], l);    

    if (!k) {
      if (abs(x[b] - x[a]) + abs(y[b] - y[a]) > deltaT) {
        printf("NO\n");
        return 0;
      }
      continue;
    }

    int st = 1;
    if (k < 0)
      st = -1;

    ll poc = max((ll) -POL+2, NaGore(x[b] - x[a] - st * deltaT, k));
    ll kraj = min((ll) POL-2 , NaDolje(x[b] - x[a] + st * deltaT, k));
    
    if (poc > kraj) {
      printf("NO\n");
      return 0;
    }

    nemoze[0]++;
    nemoze[poc+POL]--;
    nemoze[kraj+POL+1]++;
    
    for (int i=poc; i<=kraj; i++) {
      ll deltaX = (x[b] - x[a] - k * i);
      ll deltaY = deltaT - abs(deltaX);
      P novi = P(NaGore(y[b] - y[a] - st * deltaY, k), NaDolje(y[b] - y[a] + st * deltaY, k));
      nej[i+POL] = Presjek(nej[i+POL], novi);
    }
  }

  for (int i=1; i<MAX; i++)
    nemoze[i] += nemoze[i-1];

  int da = 0;

  for (int i=-l; i<=l; i++) {
    int ind = i + POL;

    if (nej[ind].X <= nej[ind].Y && !nemoze[ind] && 
        (nej[ind].Y - nej[ind].X || ((nej[ind].X + i) & 1) == (l & 1))) {
      da = 1;
      Ispis(i);
      break;
    }
  }

  if (!da)
    printf("NO\n");

  return 0;
}