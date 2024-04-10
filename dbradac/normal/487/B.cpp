#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int TOUR = 1<<17;

multiset <int> S;
int dokud[TOUR], p[TOUR];
int t[2*TOUR];

void Stavi(int pos, int lo, int hi, int begin, int end, int val)
{
  if (lo >= end || hi <= begin)
    return;
  if (lo >= begin && hi <= end) {
    t[pos] = min(t[pos], val);
    return;
  }

  Stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  Stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);
}

int Vrati(int pos)
{
  int r = t[pos+TOUR];

  for (pos = (pos + TOUR) / 2; pos; pos /= 2)
    r = min(r, t[pos]);
  return r;
}

int main()
{
  int n, raz, l;
  
  scanf("%d%d%d", &n, &raz, &l);
  
  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  p[n] = 2 * (1e9 + 5);
  int left=0;
  for (int right=0; right<=n; ) {
    for (; right<=n && (S.empty() || *(--S.end()) - *S.begin() <= raz); right++)
      S.insert(p[right]);
    
    for (; left<right && !S.empty() && *(--S.end()) - *S.begin() > raz; left++) {
      dokud[left] = right - 2;
      S.erase(S.find(p[left]));
    }
  }

  for (; left<n; left++)
    dokud[left] = n-1;

  for (int i=0; i<2*TOUR; i++)
    t[i] = TOUR;

  for (int i=0; i<n; i++) {
    int tmp;
    if (!i)
      tmp  = 0;
    else
      tmp = Vrati(i-1);
    if (dokud[i] < i + l - 1)
      continue;
    Stavi(1, 0, TOUR, i+l-1, dokud[i]+1, tmp+1);
  }
   
  int r = Vrati(n-1);
  if (r >= TOUR)
    printf("-1\n");
  else
    printf("%d\n", r);

  return 0;
}