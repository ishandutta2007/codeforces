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

vector <int> Pl, Mn;
int rje[105];

int Ok(int pl, int mn, int n, int sum)
{
  int maxx = pl * n - mn;
  int minn = pl - n * mn;
  return sum >= minn && sum <= maxx;
}

int main()
{
  int n;

  scanf(" %*s");
  Pl.push_back(0);
  for (int ind=1;; ind++) {
    char s[30];
    scanf("%s", s);
    if (s[0] == '-') {
      scanf(" %*s");
      Mn.push_back(ind);
    }    
    else if (s[0] == '+') {
      scanf(" %*s");
      Pl.push_back(ind);
    }
    else {
      scanf(" %d", &n);
      break;
    }
  }

  int br = (int) Pl.size() + (int) Mn.size();

  if (!Ok((int) Pl.size(), (int) Mn.size(), n, n)) {
    printf("Impossible\n");
    return 0;
  }

  int sum = n;
  for (; !Pl.empty(); ) {
    for (int i=1; i<=n; i++) {
      if (Ok((int) Pl.size() - 1, (int) Mn.size(), n, sum - i)) {
        sum -= i;
        rje[Pl.back()] = i;
        Pl.pop_back();
        break;
      }
    }
  }

  for (; !Mn.empty(); ) {
    for (int i=1; i<=n; i++) {
      if (Ok(0, (int) Mn.size() - 1, n, sum + i)) {
        sum += i;
        rje[Mn.back()] = -i;
        Mn.pop_back();
      }
    }
  }

  printf("Possible\n");
  printf("%d ", rje[0]);
  for (int i=1; i<br; i++) {
    if (rje[i] < 0)
      printf("- %d ", -rje[i]);
    else
      printf("+ %d ", rje[i]);
  }

  printf("= %d\n", n);

  return 0;
}