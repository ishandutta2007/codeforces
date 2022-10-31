#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1<<17;

bool Manji(vector <int> A, vector <int> B)
{
  return A.size() < B.size();
}

void Nope()
{
  printf("NO\n");
  exit(0);
}

int p[MAX];
int bio[MAX];
vector <vector<int> > V;

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }

  for (int i=0; i<n; i++) {
    if (p[i] == i) {
      printf("YES\n");
      for (int j=0; j<n; j++)
        if (i != j)
          printf("%d %d\n", i + 1, j + 1);
      
      return 0;
    }
  }

  for (int i=0; i<n; i++) {
    if (!bio[i]) {
      vector <int> T;
      for (int j=i; j != i || !T.size(); bio[j]=1, j=p[j])
        T.push_back(j);

      V.push_back(T);
    }
  }

  sort(V.begin(), V.end(), Manji);

  if (V[0].size() > 2)
    Nope();

  for (int i=0; i<(int) V.size(); i++)
    if (V[i].size() % 2)
      Nope();

  printf("YES\n");
  printf("%d %d\n", V[0][0] + 1, V[0][1] + 1);

  for (int i=1; i<(int) V.size(); i++)
    for (int j=0; j<(int) V[i].size(); j++)
      printf("%d %d\n", V[0][j%2] + 1, V[i][j] + 1);

  return 0;
}