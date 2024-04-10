#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct str {
  int val, par;
};

const int TOUR = 1<<18;
int nepar[2*TOUR];
vector <str> Tour[2*TOUR];
int prop[2*TOUR];
int p[TOUR];
int n, q;

void Postavi(vector <str> &T, int &nep)
{
  nep = 0;

  int ind=0;
  for (int i=0; i<30; i++) {
    for (int j=ind; j<(int) T.size(); j++) {
      if (T[j].val & (1<<i)) {
        swap(T[j], T[ind]);
        for (int k=ind+1; k<(int) T.size(); k++)
          if (T[k].val & (1<<i)) {
            T[k].val ^= T[ind].val;
            T[k].par ^= T[ind].par;
          }

        ind++;
        break;
      }
    }
  }

  for (int i=ind; i<(int) T.size(); i++)
    if (T[i].par)
      nep = 1;

  for (; !T.empty() && !T.back().val;)
    T.pop_back();
}

void Merge(vector <str> &A, vector <str> B, int &nep)
{
  nep = 0;
  int ima[35];
  memset(ima, 0, sizeof ima);

  int ind=0;
  for (int i=0; i<(int) A.size(); i++) {
    for (; ind<30 && !(A[i].val & (1<<ind)); ind++);
    ima[ind] = 1;

    for (int j=0; j<(int) B.size(); j++) {
      if (B[j].val & (1<<ind)) {
        B[j].val ^= A[i].val;
        B[j].par ^= A[i].par;
      }
    }

    ind++;
  }
  
  ind = 0;
  for (int i=0; i<30; i++) {
    if (ima[i])
      continue;

    for (int j=ind; j<(int) B.size(); j++) {
      if (B[j].val & (1<<i)) {
        ima[i] = 2;
        swap(B[j], B[ind]);
        for (int k=ind+1; k<(int) B.size(); k++) {
          if (B[k].val & (1<<i)) {
            B[k].val ^= B[ind].val;
            B[k].par ^= B[ind].par;
          }
        }

        ind++;
        break;
      }
    }
  }

  for (int i=ind; i<(int) B.size(); i++)
    if (B[i].par)
      nep = 1;

  vector <str> T;
  int inda=0, indb=0;
  for (int i=0; i<30; i++) {
    if (ima[i] == 1)
      T.push_back(A[inda++]);
    else if (ima[i] == 2)
      T.push_back(B[indb++]);
  }

  A = T;
}

vector <str> Prom(vector <str> V, int st, int &nep)
{
  if (!st)
    return V;

  for (int i=0; i<(int) V.size(); i++) {
    int tmp = V[i].val;
    if (V[i].par)
      tmp ^= st;
    V[i].val = tmp;
  }

  if (nep && st)
    V.push_back(str {st, 1});

  Postavi(V, nep);

  return V;
}

void Propagiraj(int pos)
{
  for (int i=2*pos; i<=2*pos+1; i++) {
    prop[i] ^= prop[pos];
    Tour[i] = Prom(Tour[i], prop[pos], nepar[i]);
  }

  prop[pos] = 0;
}

void Stavi(int pos, int lo, int hi, int begin, int end, int val)
{
  if (lo >= end || hi <= begin)
    return;
  if (lo >= begin && hi <= end) {
    prop[pos] ^= val;
    Tour[pos] = Prom(Tour[pos], val, nepar[pos]);
    return;
  }

  Propagiraj(pos);
  Stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  Stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);

  Tour[pos] = Tour[2*pos+0];
  nepar[pos] = nepar[2*pos+0];

  Merge(Tour[pos], Tour[2*pos+1], nepar[pos]);
  nepar[pos] |= nepar[2*pos+0] | nepar[2*pos+1];
}

vector <str> Vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return vector <str>();
  if (lo >= begin && hi <= end)
    return Tour[pos];

  Propagiraj(pos);
  vector <str> T1 = Vrati(2*pos+0, lo, (lo+hi)/2, begin, end);
  vector <str> T2 = Vrati(2*pos+1, (lo+hi)/2, hi, begin, end);

  int nep=0;
  Merge(T1, T2, nep);

  return T1;
}

void Init()
{
  for (int i=0; i<n; i++) {
    if (!p[i])
      nepar[TOUR+i] = 1;
    else
      Tour[TOUR+i].push_back(str {p[i], 1 });
  }

  for (int i=TOUR-1; i; i--) {
    Tour[i] = Tour[2*i];
    nepar[i] = nepar[2*i];
    Merge(Tour[i], Tour[2*i+1], nepar[i]);
    nepar[i] |= nepar[2*i+0] | nepar[2*i+1];
  }
}

int main()
{
  scanf("%d%d", &n, &q);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  Init();

  for (; q; q--) {
    int st;
    scanf("%d", &st);

    if (st == 1) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k); l--; r--;
      Stavi(1, 0, TOUR, l, r + 1, k);
    }
    else {
      int l, r;
      scanf("%d%d", &l, &r); l--; r--;
      vector <str> Tmp = Vrati(1, 0, TOUR, l, r + 1);
      printf("%d\n", 1<<((int) Tmp.size()));
    }
  }

  return 0;
}