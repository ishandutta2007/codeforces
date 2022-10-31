#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

set <int> S;
int n;
char s[MAX];
vector <int> V[MAX];
int m;

int treba(int ind)
{
  int ret = 0;

  for (auto it = S.begin(); it != S.end(); it++) {
    if (*it == n)
      break;

    int l = *it; it++;
    int r = *it; it--;

    int poz = l;
    for (; poz + m < r;) {
      int gdje = lower_bound(V[ind].begin(), V[ind].end(), poz + m) - V[ind].begin();
      if (gdje == (int) V[ind].size() || V[ind][gdje] > poz + m)
        gdje--;

      if (gdje < 0 || V[ind][gdje] == poz)
        return -1;

      poz = V[ind][gdje];
      ret++;
    }
  }
  
  return ret;
}

int main()
{

  scanf("%d", &m);
  scanf(" %s", s);
  n = (int) strlen(s);

  S.insert(-1);
  S.insert(n);
  string rje = "";

  for (int i=0; i<n; i++)
    V[s[i]].push_back(i);

  for (int i=0; i<MAX; i++) {
    int tmp = treba(i);
    if (tmp != -1) {
      for (; tmp--; )
        rje.push_back((char) i);

      printf("%s\n", rje.c_str());
      return 0;
    }
    else {
      for (auto it : V[i]) {
        S.insert(it);
        rje.push_back((char) i);
      }
    }
  }

  return 0;
}