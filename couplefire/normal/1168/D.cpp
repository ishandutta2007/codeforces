#include <bits/stdc++.h>
using namespace std;
const int K = 26;

int n, p[200200], depth[200200], c[200200], isGood[200200];
int f[200200][K + 1], sumF[200200];
pair<int, int> parB[200200];
vector<int> cnt[200200];
vector<pair<int, int>> a[200200];
int b[200200][2], cntEdge[200200][2][K + 1];
int leafDepth;

void dfsA(int x, int z, int branch) // compress to z if x has only 1 child
{
  if (x != 1)
    parB[x] = {z, branch};

  if ((a[x].empty() || a[x].size() == 2) && x != z)
  {
    b[z][branch] = x;
    for (int i = 0; i <= K; i++)
      cntEdge[z][branch][i] = cnt[x][i] - cnt[z][i];
  }

  if (a[x].empty())
  {
    if (!leafDepth) leafDepth = depth[x];
    else if (leafDepth != depth[x]) leafDepth = -1;
  }
  else
    for (int i = 0; i < a[x].size(); i++)
    {
      int y = a[x][i].first;
      depth[y] = depth[x] + 1;
      cnt[y] = cnt[x];
      cnt[y][a[x][i].second]++;
      if (a[x].size() == 2) dfsA(y, x, i);
      else dfsA(y, z, branch);
    }
}

void dfsB(int x)
{
  isGood[x] = 1;
  for (int i = 0; i < 2; i++)
  {
    int y = b[x][i];
    if (!y)
      continue;
    dfsB(y);
    for (int j = 0; j <= K; j++)
      f[x][j] = max(f[x][j], f[y][j] + cntEdge[x][i][j]);
    isGood[x] &= isGood[y];
  }

  for (int i = 0; i < K; i++)
    sumF[x] += f[x][i];

  isGood[x] &= sumF[x] <= leafDepth - depth[x];
}

void update(int x, int c)
{
  sumF[x] -= f[x][c];
  f[x][c] = 0;
  for (int i = 0; i < 2; i++)
  {
    int y = b[x][i];
    if (!y)
      continue;
    f[x][c] = max(f[x][c], f[y][c] + cntEdge[x][i][c]);
    isGood[x] &= isGood[y];
  }
  sumF[x] += f[x][c];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q, v;
  char ch;
  cin >> n >> q;
  for (int i = 2; i <= n; i++)
  {
    cin >> p[i] >> ch;
    c[i] = ch == '?' ? K : ch - 'a';
    a[p[i]].push_back({i, c[i]});
  }

  cnt[1] = vector<int>(K + 1, 0);
  dfsA(1, 1, 0);
  if (leafDepth < 0)
  {
    while (q--)
      cout << "Fou\n";
    return 0;
  }

  dfsB(1);
  while (q--)
  {
    cin >> v >> ch;
    int x = parB[v].first, branch = parB[v].second;
    int oldChar = c[v];
    cntEdge[x][branch][c[v]]--;
    c[v] = ch == '?' ? K : ch - 'a';
    cntEdge[x][branch][c[v]]++;

    if (oldChar != c[v])
      for (; x; x = parB[x].first)
      {
        isGood[x] = 1;
        if (oldChar < K)
          update(x, oldChar);
        if (c[v] < K)
          update(x, c[v]);
        isGood[x] &= sumF[x] <= leafDepth - depth[x];
      }

    if (!isGood[1]) cout << "Fou\n";
    else
    {
      int ans = 0, free = leafDepth - sumF[1];
      for (int i = 0; i < K; i++)
        ans += (f[1][i] + free) * (i + 1);
      cout << "Shi " << ans << '\n';
    }
  }
}