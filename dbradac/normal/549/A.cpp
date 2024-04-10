#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

char s[55][55];

int main()
{
  int n, m;

  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++)
    scanf("%s", s[i]);

  int rje=0;
  for (int i=0; i<n-1; i++)
    for (int j=0; j<m-1; j++) {
      string tmp = "";
      for (int k=0; k<2; k++)
        for (int l=0; l<2; l++)
          tmp += s[i+k][j+l];

      sort(tmp.begin(), tmp.end());
      if (tmp == "acef")
        rje++;
    }

  printf("%d\n", rje);

  return 0;
}