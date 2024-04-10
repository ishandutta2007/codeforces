#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 500500;

struct str {
  int root, kad;
  ll val;
} uni[MAX], mil[MAX];

vector <P> Pref[MAX];
vector <int> Uni[MAX], Mil[MAX];
int kojiuni[MAX], kojimil[MAX];
int milpraz[MAX];
int n, brq;

int ZadPraz(int x)
{
  ll ret = mil[x].val;
  if (milpraz[mil[x].root] > mil[x].kad)
    ret = milpraz[mil[x].root];

  return (int) ret;
}

void MergeMil(int poca, int pocb, int tren)
{
  int a = kojimil[poca];
  int b = kojimil[pocb];

  if (Mil[a].size() < Mil[b].size()) {
    kojimil[poca] = b;
    swap(a, b);
  }
 
  for (int i=0; i<(int) Mil[b].size(); i++) {
    int tmp = Mil[b][i];
    Mil[a].push_back(tmp);
    mil[tmp].val = (ll) ZadPraz(tmp);
    mil[tmp].root = a;
    mil[tmp].kad = tren;    
  }
}

void PrazniMil(int x, int tren)
{
  x = kojimil[x];
  milpraz[x] = tren;
}

ll BrLjud(int x)
{
  int praz = ZadPraz(x);
  int vr = praz;
  int rt = uni[x].root;
  ll ret = 0;

  if (praz < uni[x].kad) {
    ret = uni[x].val;
    vr = uni[x].kad;
  }
  
  ret += Pref[rt].back().Y - (--lower_bound(Pref[rt].begin(), Pref[rt].end(), P(vr, -1)))->Y;

  return ret;
}

void MergeUni(int poca, int pocb, int tren)
{
  int a = kojiuni[poca];
  int b = kojiuni[pocb];

  if (Uni[a].size() < Uni[b].size()) {
    kojiuni[poca] = b;
    swap(a, b);
  }
  
  for (int i=0; i<(int) Uni[b].size(); i++) {
    int tmp = Uni[b][i];
    Uni[a].push_back(tmp);
    uni[tmp].val = BrLjud(tmp);
    uni[tmp].root = a;
    uni[tmp].kad = tren;
  }
}

void DosloUni(int x, int tren)
{
  x = kojiuni[x];
  Pref[x].push_back(P(tren, Pref[x].back().Y + Uni[x].size()));
}

void Init()
{
  for (int i=0; i<n; i++) {
    kojiuni[i] = kojimil[i] = i;
    Uni[i].push_back(i);
    Mil[i].push_back(i);
    mil[i] = str { i, -1, 0 };
    uni[i] = str { i, -1, 0 };
    Pref[i].push_back(P(-1, 0));
  }
}


int main()
{
  scanf("%d%d", &n, &brq);

  Init();

  for (int i=1; i<=brq; i++) {
    char c;
    scanf(" %c", &c);
    if (c == 'M' || c == 'U') {
      int a, b;
      scanf("%d%d", &a, &b); a--; b--;
      if (c == 'M')
        MergeMil(a, b, i);
      else
        MergeUni(a, b, i);
    }
    else {
      int ind;
      scanf("%d", &ind); ind--;

      if (c == 'A')
        DosloUni(ind, i);
      else if (c == 'Z')
        PrazniMil(ind, i);
      else
        printf("%lld\n", BrLjud(ind));
    }
  }

  return 0;
}