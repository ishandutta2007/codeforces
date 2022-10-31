#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1000000007, MAX = 200005;

vector <int> C[MAX];
vector <int> L[MAX], R[MAX];
int par[MAX];
int dpdown[MAX], dpup[MAX], poz[MAX];

int Mul(int a, int b)
{
  return ((ll) a * b) % MOD;
}

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int DfsDown(int node)
{
  L[node].push_back(1);
  for (int i=0; i<(int) C[node].size(); i++)
    L[node].push_back(Mul(L[node].back(), Add(DfsDown(C[node][i]), 1)));
  
  R[node].push_back(1);
  for (int i=(int) C[node].size()-1; i>=0; i--)
    R[node].push_back(Mul(R[node].back(), Add(dpdown[C[node][i]], 1)));
  
  for (int i=0; i<(int) R[node].size() / 2; i++)
    swap(R[node][i], R[node][R[node].size()-i-1]);

  return dpdown[node] = L[node].back();
}

void DfsUp(int node)
{
  if (!node)
    dpup[node] = 1;
  else
    dpup[node] = Add(1, Mul(dpup[par[node]], Mul(L[par[node]][poz[node]], R[par[node]][poz[node] + 1])));

  for (int i=0; i<(int) C[node].size(); i++)
    DfsUp(C[node][i]);
}

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=1; i<n; i++) {
    scanf("%d", &par[i]); par[i]--;
    poz[i] = (int) C[par[i]].size();
    C[par[i]].push_back(i);
  }

  DfsDown(0);
  DfsUp(0);

  for (int i=0; i<n; i++)
    printf("%d ", Mul(dpup[i], dpdown[i]));
  printf("\n");

  return 0;
}