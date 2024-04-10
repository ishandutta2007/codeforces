#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 2000100, H = 3137, MOD = 1e9 + 7;

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

vector <P> Vel, Mal;
vector <int> Hvel, Hmal;
string svel;
int pot[MAX];

int GetH(int l, int len)
{
//  TRACE(l);
  //TRACE(len);
  return Sub(Hvel[l+len-1], Mul(pot[len], Hvel[l-1]));
}

void DodajBr(string &s, ll br)
{
  string tmp = "";
  for (; br; br /= 10)
    tmp.push_back((char) ('0' + br % 10));

  for (int i=(int) tmp.size()-1; i>=0; i--)
    s.push_back(tmp[i]);
}

void Input(vector <P> &V, vector <int> &Hash, int len, int st)
{
  V.push_back(P(0, 0));

  for (int i=0; i<len; i++) {
    int tmp;
    char cc;
    scanf("%d-%c", &tmp, &cc);
    int c = cc - 'a' + 1;
    
    if (!V.empty() && V.back().X == c) {
      P bb = V.back();
      V.pop_back();
      V.push_back(P(c, bb.Y + tmp));
    }
    else
      V.push_back(P(c, tmp));
  }

  string tmp = "";
  int poc = 1, kraj = (int) V.size();
  if (st) {
    poc++;
    kraj--;
  }

  for (int i=poc; i<kraj; i++) {
    DodajBr(tmp, V[i].Y);
    tmp.push_back((char) (V[i].X + 'a' - 1));
  }

  Hash.push_back(0);
  for (int i=0; i<(int) tmp.size(); i++) {
    Hash.push_back(Add(Mul(Hash.back(), H), tmp[i]));
//    if (!st)
  //    TRACE(Hash.back());
  }

  if (!st) {
    svel = tmp;
    //TRACE(svel);
  }
//  else
  //  TRACE(tmp);
}

int main()
{
  pot[0] = 1;
  for (int i=1; i<MAX; i++)
    pot[i] = Mul(pot[i-1], H);

  int n, m;

  scanf("%d%d", &n, &m);

  Input(Vel, Hvel, n, 0);
  Input(Mal, Hmal, m, 1);

  if (Mal.size() == 2) {
    ll br=0;
    for (int i=0; i<(int) Vel.size(); i++)
      if (Vel[i].X == Mal[1].X)
        br += max(0ll, Vel[i].Y - Mal[1].Y + 1);

    printf("%lld\n", br);
    return 0;
  }

  TRACE(svel);

  //printf("%d %d\n", '2', 'b');
  int br=0;
  for (int i=1; i<(int) Hvel.size() - ((int) Hmal.size() - 1); i++) {
//    printf("SAJZ %d %d\n", (int) Hmal.size(), Hmal.back());
//    printf("GET %d %d\n", i, GetH(i, (int) Hmal.size() - 1));
    if (GetH(i, (int) Hmal.size() - 1) == Hmal.back()) {
  //    printf("DA\n");

      int pocr = i + (int) Hmal.size() - 2;
  //    TRACE(svel[i-2]);
    //  TRACE(Mal[1].X);
      //TRACE(pocr);
      if (svel[i-2] - 'a' + 1 != Mal[1].X || pocr >= (int) svel.size())
        continue;

//      printf("DDD\n");
      ll lijev = 0;
      ll tpot=1;
      for (int j=i-3; j>=0 && svel[j] >= '0' && svel[j] <= '9'; j--, tpot*=10)
        lijev += tpot * (svel[j] - '0');

//      TRACE(lijev);

      if (lijev < (ll) Mal[1].Y)
        continue;

      ll des = 0;
      int j = pocr;
      for (; j < (int) svel.size() && svel[j] >= '0' && svel[j] <= '9'; j++)
        des = des * 10 + svel[j] - '0';

      if (svel[j] - 'a' + 1 == Mal.back().X && des >= Mal.back().Y)
        br++;
    }
  }

  printf("%d\n", br);

  return 0;
}