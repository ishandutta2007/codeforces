#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

const int MAX = 1<<18;

typedef long long llint;
typedef pair<int,int> pii;
#define X first
#define Y second

vector <int> V[MAX];
int indpos = 1<<17;
int brred, brstup;
vector <int> Cv;
int indeg[MAX];
map <int, vector<int> > M;

void Izgradi()
{
  for (int i=0; i<brred; i++) {
    vector <pii> T;
    M.clear();

    for (int j=0; j<brstup; j++) {
      int tmp;
      scanf("%d", &tmp);
      if (tmp != -1)
        M[tmp].push_back(j);
    }

    for (map<int, vector<int> > :: iterator it = M.begin(); it != M.end(); it++) {
      map <int, vector<int> > :: iterator it2 = it;
      it2++;
      if (it2 == M.end())
        break;

      for (int k=0; k<(int) it->Y.size(); k++) {
        V[it->Y[k]].push_back(indpos);
        indeg[indpos]++;
      }

      for (int k=0; k<(int) it2->Y.size(); k++) {
        V[indpos].push_back(it2->Y[k]);
        indeg[it2->Y[k]]++;
      }
      indpos++;
    }
  }
}

void Topol()
{
  int br = brstup + indpos - (1<<17);

  queue <int> Q;
  for (int i=0; i<brstup; i++)
    if (!indeg[i])
      Q.push(i);

  for (int i=1<<17; i<indpos; i++)
    if (!indeg[i])
      Q.push(i);

  vector <int> R;
  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();
    br--;

    if (tmp < (1<<17))
     R.push_back(tmp + 1);

    for (int i=0; i<(int) V[tmp].size(); i++) {
      int nn = V[tmp][i];
      indeg[nn]--;
      if (!indeg[nn])
        Q.push(nn);
    }
  }

  if (br)
    printf("-1\n");
  else {
    for (int i=0; i<(int) R.size(); i++)
      printf("%d ", R[i]);
    printf("\n");
  }
}

int main() {
  scanf("%d%d", &brred, &brstup);
  Izgradi();
  Topol();

  return 0;
}