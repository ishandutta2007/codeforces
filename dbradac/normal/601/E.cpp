#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAXK = 1005, TOUR = 1<<16, MOD = 1e9 + 7, PP = 1e7 + 19;

int n, k;
int dp[2][MAXK];
int inddp;
int poc[TOUR], kraj[TOUR], val[TOUR], masa[TOUR];
int ind=0;
int jelq[TOUR];
vector <int> T[2*TOUR];

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((long long) a * b) % MOD);
}

int Eval()
{
  int mnoz = 1, ret = 0;
  
  for (int i=1; i<=k; i++) {
    ret = Add(ret, Mul(mnoz, dp[inddp][i]));
    mnoz = Mul(mnoz, PP);
  }
  
  return ret;
}

void Stavi(int pos, int lo, int hi, int begin, int end, int vv)
{
  if (lo >= end || hi <= begin)
    return;
  if (lo >= begin && hi <= end) {
    T[pos].push_back(vv);
    return;
  }

  Stavi(2*pos+0, lo, (lo+hi)/2, begin, end, vv);
  Stavi(2*pos+1, (lo+hi)/2, hi, begin, end, vv);
}

void Dfs(int pos)
{
  int tmp[2][MAXK];

  memcpy(tmp, dp, sizeof dp);
  int pocind = inddp;

  for (int i=0; i<(int) T[pos].size(); i++, inddp ^= 1) {
    int a = T[pos][i];
    for (int j=0; j<=k; j++)
      dp[1^inddp][j] = dp[inddp][j];

    for (int j=0; j<=k-masa[a]; j++)
      dp[1^inddp][j+masa[a]] = max(dp[1^inddp][j+masa[a]], dp[inddp][j] + val[a]);
  }

  if (pos < TOUR) {
    Dfs(2*pos);
    Dfs(2*pos+1);
  }
  else if (jelq[pos - TOUR])
    printf("%d\n", Eval());

  inddp = pocind;
  memcpy(dp, tmp, sizeof dp);
}

int main()
{
  scanf("%d%d", &n, &k);

  for (int i=0; i<n; i++) {
    scanf("%d%d", &val[ind], &masa[ind]);
    ind++;
  }

  int brq;
  scanf("%d", &brq);

  for (int i=1; i<=brq; i++) {
    int st;
    scanf("%d", &st);

    if (st == 1) {
      scanf("%d%d", &val[ind], &masa[ind]);
      poc[ind++] = i;
    }
    else if (st == 2) {
      int koji;
      scanf("%d", &koji); koji--;
      kraj[koji] = i;
    }
    else
      jelq[i] = 1;
  }

  for (int i=0; i<ind; i++) {
    if (!kraj[i])
      kraj[i] = brq + 1;

//    printf("POC KRAJ %d %d\n", poc[i], kraj[i]);
    Stavi(1, 0, TOUR, poc[i], kraj[i], i);
  }

  Dfs(1);

  return 0;
}