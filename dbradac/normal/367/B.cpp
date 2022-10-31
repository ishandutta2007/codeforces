#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int MAX = 400005;

map <int, vector <pair <int, int> > > M;
vector <int> V;
int a[MAX], b[MAX];
int treba[MAX], poj[MAX];
int rje[MAX];

int main()
{
  int n, m, p;

  scanf("%d%d%d", &n, &m, &p);

  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
    M[a[i]].push_back(make_pair(0, i));
  }

  for (int i=0; i<m; i++) {
    scanf("%d", &b[i]);
    M[b[i]].push_back(make_pair(1, i));
  }

  int ind=0;
  for (map <int, vector <pair <int, int > > > :: iterator it = M.begin(); it != M.end(); it++, ind++) {
    for (int j=0; j<(int) it->second.size(); j++) {
      if (!it->second[j].first)
        a[it->second[j].second] = ind;
      else
        b[it->second[j].second] = ind;
    }
  }

  for (int i=0; i<m; i++)
    treba[b[i]]++;

  for (int i=0; i<p; i++) {
    for (int j=0; j<(int) V.size(); j++)
      poj[V[j]] = 0;
    V.clear();

    int poc = i, kraj = i, raz = m;
    if (poc + (long long) p * (m - 1) >= n)
      break;

    for (int j=0; j<m; j++, kraj += p) {
      if (poj[a[kraj]] < treba[a[kraj]])
        raz--;
      else
        raz++;
      poj[a[kraj]]++;
      V.push_back(a[kraj]);
    }
    kraj -= p;
  
    for (; kraj < n; kraj += p, poc += p) {
      if (!raz)
        rje[poc] = 1;
      if (kraj + p < n) {
        int nk = kraj + p;
        if (poj[a[nk]] < treba[a[nk]])
          raz--;
        else
          raz++;
        poj[a[nk]]++;
        V.push_back(a[nk]);

        if (poj[a[poc]] > treba[a[poc]])
          raz--;
        else
          raz++;
        poj[a[poc]]--;
      }
    }
  }

  int br=0;
  for (int i=0; i<n; i++)
    br += rje[i];
  printf("%d\n", br);

  for (int i=0; i<n; i++)
    if (rje[i])
      printf("%d ", i+1);
  printf("\n");

  return 0;
}