#include <cstdio>
#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

typedef pair <ll, int> P;
#define X first
#define Y second
#define MP(a, b) make_pair(a, b)

const int TOUR = 1<<18;
const ll INF = 1000000000000000000ll;

P tleft[2*TOUR], tright[2*TOUR];

void Stavi(P t[2*TOUR], int pos, P val)
{
  for (t[pos+TOUR] = val, pos = (pos + TOUR) / 2; pos; pos /= 2)
    t[pos] = max(t[2*pos], t[2*pos+1]);
}

P Vrati(P t[2*TOUR], int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return MP(-INF, 0);
  if (lo >= begin && hi <= end)
    return t[pos];
  return max(Vrati(t, 2*pos+0, lo, (lo+hi)/2, begin, end),
             Vrati(t, 2*pos+1, (lo+hi)/2, hi, begin, end) );
}

int h[TOUR], dist[TOUR];
ll pref[2*TOUR];

int main()
{
  int n, q;

  scanf("%d%d", &n, &q);

  for (int i=0; i<n; i++)
    scanf("%d", &dist[i]);
  
  for (int i=0; i<n; i++)
    scanf("%d", &h[i]);

  for (int i=0; i<n; i++) {
    if (i)
      pref[i] = pref[i-1] + dist[i-1];
    Stavi(tleft , i, MP(2 * h[i] - pref[i], i));
    Stavi(tright, i, MP(2 * h[i] + pref[i], i));
  }
  
  for (int i=n; i<2*n; i++) {
    pref[i] = pref[i-1] + dist[(i-1)%n];
    Stavi(tleft , i, MP(2 * h[i-n] - pref[i], i));
    Stavi(tright, i, MP(2 * h[i-n] + pref[i], i));
  }

  for (int i=0; i<q; i++) {
    int a, b, from, to;
    scanf("%d%d", &a, &b); a--; b--;
    
    if (a > b) {
      from = b + 1;
      to = a - 1;
    }
    else {
      from = b + 1;
      to = a - 1 + n;
    }

    P l = Vrati(tleft , 1, 0, TOUR, from, to + 1);
    P r = Vrati(tright, 1, 0, TOUR, from, to + 1);
    ll rje;

    if (l.Y != r.Y)
      rje = l.X + r.X;
    else {
      rje = max(l.X + Vrati(tright, 1, 0, TOUR, l.Y + 1, to + 1).X,
                r.X + Vrati(tleft,  1, 0, TOUR, from, r.Y).X);
    }

    cout << rje << endl;
  }

  return 0;
}