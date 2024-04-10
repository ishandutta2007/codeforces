#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;

const int MAX = 4005;

int p[MAX], v[MAX], d[MAX];
queue <int> Q;
vector <int> R;

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    cin >> v[i] >> d[i] >> p[i];

  for (int i=0; i<n; i++) {
    for (; !Q.empty(); ) {
      int tmp = Q.front();
      Q.pop();
      for (int j=tmp+1; j<n; j++) {
        if (p[j] >= 0) {
          p[j] -= d[tmp];
          if (p[j] < 0)
            Q.push(j);
        }
      }
    }

    if (p[i] >= 0) {
      R.push_back(i);
      int kol = v[i];
      for (int j=i+1; j<n; j++) {
        if (p[j] >= 0) {
          p[j] -= kol;
          kol = max(0, kol - 1);
          if (p[j] < 0)
            Q.push(j);
        }
      }

      p[i] = -1;
    }
  }

  printf("%d\n", (int) R.size());
  for (int i=0; i<(int) R.size(); i++)
    printf("%d ", R[i] + 1);
  printf("\n");

  return 0;
}