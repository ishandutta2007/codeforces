#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17, LOG = 17, INF = 0x3f3f3f3f;

vector <int> Vec[MAX];
vector <int> V[MAX], C[MAX];
int bitanlc[MAX], bitan[MAX];
int dub[MAX], disc[MAX], fin[MAX], vr = 1;
int koji[MAX];
int lca[MAX][LOG];
int n;
ll dp[MAX][2];
int zgrada[MAX];

void Dfs(int node, int prosli)
{
  dub[node] = dub[prosli] + 1;
  koji[vr] = node;
  disc[node] = vr++;

  lca[node][0] = prosli;
  for (int i=1; i<LOG; i++)
    lca[node][i] = lca[lca[node][i-1]][i-1];

  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn == prosli)
      V[node].erase(V[node].begin() + i--);
    else
      Dfs(nn, node);
  }
  
  for (int i=0; i<(int) V[node].size(); i++)
    C[node].push_back(disc[V[node][i]]);

  fin[node] = vr;
}

int Lca(int a, int b)
{
  if (dub[a] > dub[b])
    swap(a, b);

  for (int i=0, raz=dub[b] - dub[a]; raz; raz /= 2, i++)
    if (raz & 1)
      b = lca[b][i];

  if (a == b)
    return a;

  for (int i=LOG-1; i>=0; i--) {
    if (lca[a][i] != lca[b][i]) {
      a = lca[a][i];
      b = lca[b][i];
    }
  }

  return lca[a][0];
}

void Stavi(int node, int p[MAX], vector <int> &T)
{
  if (!p[node]) {
    p[node] = 1;
    T.push_back(node);
  }
}

ll Rek(int node)
{
  dp[node][0] = dp[node][1] = 0;

  for (int i=0; i<(int) Vec[node].size(); i++)
    Rek(Vec[node][i]);

  if (zgrada[node]) {
    dp[node][0] = INF;
    for (int i=0; i<(int) Vec[node].size(); i++)
      dp[node][1] += dp[Vec[node][i]][0];
  }
  else {
    ll maxraz = 0, sum1 = 0, sum0 = 0;
    for (int i=0; i<(int) Vec[node].size(); i++) {
      int nn = Vec[node][i];

      maxraz = max(maxraz, dp[nn][0] - dp[nn][1]);
      sum1 += dp[nn][1];
      sum0 += dp[nn][0];
    }
  
    dp[node][0] = min(sum0, sum1 + 1);
    dp[node][1] = min(dp[node][0], sum0 - maxraz);
  }

  return dp[node][1];
}

ll Rijesi(const vector <int> &T)
{
  vector <int> Bitni;
  vector <int> Lcaovi;
  vector <P> Dtime;
  vector <P> Dub;

  for (int i=0; i<(int) T.size(); i++) {
    Dtime.push_back(P(disc[T[i]], T[i]));
    Stavi(T[i], bitanlc, Lcaovi);
    zgrada[T[i]] = 1;
  }

  sort(Dtime.begin(), Dtime.end());

  for (int i=0; i<(int) Dtime.size() - 1; i++)
    Stavi(Lca(Dtime[i].Y, Dtime[i+1].Y), bitanlc, Lcaovi);

  for (int i=0; i<(int) Lcaovi.size(); i++)
    Stavi(Lcaovi[i], bitan, Bitni);
  
  for (int i=0; i<(int) Lcaovi.size(); i++)
    Dub.push_back(P(dub[Lcaovi[i]], Lcaovi[i]));

  sort(Dub.begin(), Dub.end(), greater<P>());
  set <int> S;

  for (int i=0; i<(int) Dub.size(); i++) {
    int node = Dub[i].Y;
    for (set <int> :: iterator it = S.lower_bound(disc[node]); it != S.end() && *it < fin[node];) {
      vector <int> :: iterator itv = lower_bound(C[node].begin(), C[node].end(), *it);
      if (itv == C[node].end() || *itv > *it)
        itv--;
      
      int nn = koji[*itv];
      if (nn == koji[*it])
        Vec[node].push_back(nn);
      else {
        Stavi(nn, bitan, Bitni);
        Vec[node].push_back(nn);
        Vec[nn].push_back(koji[*it]);
      }

      set <int> :: iterator it2 = it++;
      S.erase(it2);
    }

    S.insert(disc[node]);
  }

  int prvi = Bitni[0];
  for (int i=0; i<(int) Bitni.size(); i++)
    if (dub[Bitni[i]] < dub[prvi])
      prvi = Bitni[i];

  ll ret = Rek(prvi);

  for (int i=0; i<(int) Bitni.size(); i++) {
    int nn = Bitni[i];
    Vec[nn].clear();
    bitan[nn] = bitanlc[nn] = zgrada[nn] = 0;
  }

  return ret < MAX ? ret : -1;
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  Dfs(0, 0);

  int brq;
  scanf("%d", &brq);

  for (; brq--; ) {
    int k;
    scanf("%d", &k);
    vector <int> T;

    for (; k--; ) {
      int tmp;
      scanf("%d", &tmp); tmp--;
      T.push_back(tmp);
    }

    printf("%lld\n", Rijesi(T));
  }

  return 0;
}