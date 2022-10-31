#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2005;

int poc[MAX];
int per[MAX];
int poz[MAX];
int n;
int pare=0;
vector <pair<int, int> > R;

void Dovedi(int x)
{
  int ind = -1;

  for (int i=1; i<=n; i++)
    if (poc[i] == x) {
      ind = i;
      break;
    }

  for (; ind != x;) {
    for (int i=ind-1; i>=x; i--) {
      if (poc[i] >= ind) {
        R.push_back(make_pair(i, ind));
        swap(poc[i], poc[ind]);
        pare += abs(ind - i);
        ind = i;
        break;
      }
   }
  }
}

int main()
{
  scanf("%d", &n);

  for (int i=1; i<=n; i++) {
    scanf("%d", &poc[i]);
    poz[poc[i]] = i;
  }

  for (int i=1; i<=n; i++) {
    scanf("%d", &per[i]);
    poc[poz[per[i]]] = i; 
  }

  for (int i=1; i<=n; i++)
    Dovedi(i);

  printf("%d\n%d\n", pare, (int) R.size());
  for (int i=0; i<(int) R.size(); i++)
    printf("%d %d\n", R[i].first, R[i].second);

  return 0;
}