#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50005;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;
int rje[MAX], st[MAX];
vector <int> V[MAX];

int main()
{
  int n, m, q, o;

  scanf("%d%d%d%d", &n, &m, &q, &o);

  for (int i=0; i<o; i++) {
    int tmp;
    scanf("%d", &tmp);
    st[tmp] = 1;
  }

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (V[a].size() < V[b].size()) {
      V[a].push_back(b);
      rje[b] += st[a];
    }
    else {
      V[b].push_back(a);
      rje[a] += st[b];
    }
  }
  
  for (int j=0; j<q; j++) {
    char c;
    int a, b;
    scanf(" %c", &c);

    if (c == 'O' || c == 'F') {
      int prom = 1;
      if (c == 'F')
        prom = -1;
      
      scanf("%d", &a);
      
      for (int i=0; i<(int) V[a].size(); i++)
        rje[V[a][i]] += prom;

      st[a] ^= 1;
    }
    else if (c == 'A') {
      scanf("%d%d", &a, &b);
      if (V[a].size() < V[b].size()) {
        V[a].push_back(b);
        rje[b] += st[a];
      }
      else {
        V[b].push_back(a);
        rje[a] += st[b];
      }
    }
    else if (c == 'D') {
      scanf("%d%d", &a, &b);
      for (int i=0; i<(int) V[a].size(); i++) {
        if (V[a][i] == b) {
          rje[b] -= st[a];
          V[a].erase(V[a].begin() + i);
        }
      }

      for (int i=0; i<(int) V[b].size(); i++) {
        if (V[b][i] == a) {
          rje[a] -= st[b];
          V[b].erase(V[b].begin() + i);
        }
      }
    }
    else {
      scanf("%d", &a);
      int tmp = rje[a];
      for (int i=0; i<(int) V[a].size(); i++)
        tmp += st[V[a][i]];

      printf("%d\n", tmp);
    }
  }

  return 0;
}