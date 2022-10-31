#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 505;

int tab[MAX*MAX];
int rje[MAX];
multiset <int> S;

int gcd(int a, int b)
{
  if (!b)
    return a;
  return gcd(b, a % b);
}

void Makni(int ind)
{
  for (int i=0; i<=ind; i++) {
    int tmp = -gcd(rje[i], rje[ind]);    
    S.erase(S.find(tmp));
    if (i != ind)
      S.erase(S.find(tmp));
  }
}

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n*n; i++) {
    scanf("%d", &tab[i]);
    S.insert(-tab[i]);
  }

  for (int i=0; i<n; i++) {
    rje[i] = -*(S.begin());
    Makni(i);
    printf("%d ", rje[i]);
  }
  
  printf("\n");
  
  return 0;
}