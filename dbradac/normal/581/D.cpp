#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct str {
  int w, h, ind;
};

bool operator < (const str &a, const str &b)
{
  return a.ind < b.ind;
}

int Rijesi(vector <str> V, int st)
{
  if (!st) {
    if (V[0].w != V[1].w || V[1].w != V[2].w || V[0].w != V[0].h + V[1].h + V[2].h)
      return 0;
    
    printf("%d\n", V[0].w);

    for (int i=0; i<3; i++) {
      for (int j=0; j<V[i].h; j++) {
        for (int k=0; k<V[i].w; k++)
          printf("%c", V[i].ind + 'A');
        printf("\n");
      }              
    }

    return 1;
  }

  if (V[1].w != V[2].w || V[0].h != V[1].h + V[2].h || V[0].h != V[0].w + V[1].w)
    return 0;
  
  printf("%d\n", V[0].h);

  for (int i=0; i<V[0].h; i++) {
    for (int j=0; j<V[0].w; j++)
      printf("%c", V[0].ind + 'A');

    for (int j=0; j<V[1].w; j++) {
      if (i < V[1].h)
        printf("%c", V[1].ind + 'A');
      else
        printf("%c", V[2].ind + 'A');
    }

    printf("\n");
  }

  return 1;
}

int main()
{
  int x[3], y[3];

  for (int i=0; i<3; i++)
    scanf("%d%d", &x[i], &y[i]);

  for (int i=0; i<8; i++) {
    for (int j=0; j<2; j++) {      
      int per[3] = {0, 1, 2};
      do {
        vector <str> V;
        
        for (int k=0; k<3; k++) {
          if (i & (1<<k))
            V.push_back(str { y[per[k]], x[per[k]], per[k] });
          else
            V.push_back(str { x[per[k]], y[per[k]], per[k] });        
        }

        if (Rijesi(V, j))      
          return 0;
      } while(next_permutation(per, per + 3));
    }
  }

  printf("-1\n");

  return 0;
}