#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAXN = 5005, INF = 0x3f3f3f3f, MAXB = 92;

int p[MAXN][3];
int acc[3], mogh[3];
int n;
int rje = MAXN;
int hackao[3];
vector <int> Bitni;

int ValZad(int bracc)
{
  int ret = 500;
  for (; ret < 3000 && 2 * bracc <= n; bracc *= 2, ret += 500);
  return ret;
}

int Eval(int valz, int t)
{
  if (!t)
    return 0;
  return (valz * (250 - abs(t))) / 250;
}

int Prov()
{
  int dp[Bitni.size()+1][hackao[0]+2][hackao[1]+2][hackao[2]+2];
  int valz[3];
  int mojsc = 0;
  int bolj = 0;


  for (int i=0; i<3; i++) {
    valz[i] = ValZad(acc[i] - hackao[i]);
    mojsc += 100 * hackao[i] + Eval(valz[i], p[0][i]);
  }

  for (int i=0; i<n; i++) {
    int bitan = 0, sum = 0;
    for (int j=0; j<3; j++) {
      bitan |= (p[i][j] < 0);
      sum += Eval(valz[j], p[i][j]);
    }
    if (!bitan)
      bolj += sum > mojsc;
  }

  memset(dp, INF, sizeof dp);
  dp[0][0][0][0] = 0;

  for (int i=0; i<(int) Bitni.size(); i++)
    for (int h0=0; h0<=hackao[0]; h0++)
      for (int h1=0; h1<=hackao[1]; h1++)
        for (int h2=0; h2<=hackao[2]; h2++) {
          int ind = Bitni[i];
          for (int j=0; j<8; j++) {
            int val = 0, ne = 0;
            for (int k=0; k<3; k++) {
              int st = (j>>k & 1);
              if (p[ind][k] >= 0 && st) {
                ne = 1;
                break;
              }

              if (!st)
                val += Eval(valz[k], p[ind][k]);
            }

            if (!ne) {
              dp[i+1][h0+(j>>0&1)][h1+(j>>1&1)][h2+(j>>2&1)] = 
                min(dp[i+1][h0+(j>>0&1)][h1+(j>>1&1)][h2+(j>>2&1)], dp[i][h0][h1][h2] + (val > mojsc));
            }
          }
        }

  return dp[Bitni.size()][hackao[0]][hackao[1]][hackao[2]] + bolj;
}

void Rek(int ind)
{
  if (ind == 3) {
    rje = min(rje, Prov());
    return;
  }

  hackao[ind] = mogh[ind];
  Rek(ind + 1);

  for (int i=hackao[ind]-1; i>=0; i--)
    if (ValZad(acc[ind] - i) != ValZad(acc[ind] - i - 1)) {
      hackao[ind] = i;
      Rek(ind + 1);
    }
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    for (int j=0; j<3; j++) {
      scanf("%d", &p[i][j]);
      if (p[i][j])
        acc[j]++;
      if (p[i][j] < 0)
        mogh[j]++;
    }

    if (min(min(p[i][0], p[i][1]), p[i][2]) < 0)
      Bitni.push_back(i);
  }

  int ukhac = mogh[0] + mogh[1] + mogh[2];
  if (ukhac >= 90) {
    printf("1\n");
    return 0;
  }

  Rek(0);

  printf("%d\n", rje + 1);

  return 0;
}