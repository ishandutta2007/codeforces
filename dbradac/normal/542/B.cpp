#include <cstdio>
#include <algorithm>
#include <queue>
#include <ctime>

using namespace std;

typedef long long ll;

const int MAX = 200100, MIL = 1000000100;
const int TOUR = 1<<21;

struct event {
  int t, ind, st; //-1 dode, 0 query, 1 ode
};

bool operator < (const event &a, const event &b)
{
  if (a.t != b.t)
    return a.t > b.t;
  if (a.st != b.st)
    return a.st > b.st;
  return a.ind > b.ind;
}

struct node {
  int maxx, prop;
};

int vremena[10*MAX], indvr;

struct tour {
  node t[2*TOUR];
  void propagiraj(int p) {
    for (int i=2*p; i<=2*p+1; i++) {
      t[i].maxx += t[p].prop;
      t[i].prop += t[p].prop;
    }
    
    t[p].prop = 0;
  }

  void set(int pos, int lo, int hi, int gdje, int val) {
    if (lo >= gdje + 1 || hi <= gdje)
      return;
    if (lo == gdje && hi == gdje + 1) {
      t[pos].maxx = max(t[pos].maxx, val);
      return;
    }

    propagiraj(pos);
    set(2*pos+0, lo, (lo+hi)/2, gdje, val);
    set(2*pos+1, (lo+hi)/2, hi, gdje, val);

    t[pos].maxx = max(t[2*pos+0].maxx, t[2*pos+1].maxx);
  }

  void set(int gdje, int val) {
    set(1, 0, TOUR, gdje, val);
  }

  void insert(int pos, int lo, int hi, int begin, int end, int val) {
    if (lo >= end || hi <= begin)
      return;
    if (lo >= begin && hi <= end) {
      t[pos].maxx += val;
      t[pos].prop += val;
      return;
    }

    propagiraj(pos);

    insert(2*pos+0, lo, (lo+hi)/2, begin, end, val);
    insert(2*pos+1, (lo+hi)/2, hi, begin, end, val);

    t[pos].maxx = max(t[2*pos+0].maxx, t[2*pos+1].maxx);
  }

  void insert(int begin, int end, int val) {
    insert(1, 0, TOUR, begin, end, val);
  }

  int query(int pos, int lo, int hi, int begin, int end) {
    if (lo >= end || hi <= begin)
      return 0;
    if (lo >= begin && hi <= end)
      return t[pos].maxx;

    propagiraj(pos);
    return max(query(2*pos+0, lo, (lo+hi)/2, begin, end),
               query(2*pos+1, (lo+hi)/2, hi, begin, end) );
  }

  int query(int begin, int end) {
    return query(1, 0, TOUR, begin, end);
  }
} T;

priority_queue <event> Q;
int poc[MAX], kraj[MAX];
int best[2*MAX];
vector <int> E;

int Gpoz(int x)
{
  return lower_bound(vremena, vremena + indvr, x) - vremena;
}

void DodajVr(int x)
{
  if (*lower_bound(vremena, vremena + indvr, x - 1) != x - 1)
    vremena[indvr++] = x - 1;
  if (*lower_bound(vremena, vremena + indvr, x) != x)
    vremena[indvr++] = x;
}

int main()
{
  int n, r, rje = 0;

  scanf("%d%d", &n, &r);

  for (int i=0; i<n; i++) {
    scanf("%d%d", &poc[i], &kraj[i]); poc[i] += MIL; kraj[i] += MIL;
    poc[i] = max(MIL, poc[i]);
    if (kraj[i] >= MIL) {
      E.push_back(poc[i]);
      E.push_back(kraj[i] + 1);
      Q.push(event { poc[i], i, -1 });
      Q.push(event { kraj[i], i, 1 });
      Q.push(event { poc[i], 0, 0 });
    }
  }

  sort(E.begin(), E.end());
  vremena[0] = 0; indvr = 1;

  for (; !Q.empty(); ) {
    event tmp = Q.top();
    Q.pop();

    DodajVr(tmp.t);

    if (tmp.st == -1)
      T.insert(0, Gpoz(tmp.t), 1);
    else if (tmp.st == 1)
      T.insert(0, Gpoz(poc[tmp.ind]), -1);
    else {      
      int val = T.query(0, Gpoz(tmp.t - r + 1));
      T.set(Gpoz(tmp.t), val);

      if ((ll) tmp.t + r < 2 * MIL) {
        int izmedu = lower_bound(E.begin(), E.end(), tmp.t) - E.begin();
        if (val > best[izmedu]) {
          best[izmedu] = val;
          if (val > tmp.ind)            
            Q.push(event { tmp.t + r, val, 0 });
        }
      }

      rje = max(rje, val);
    }
  }

  printf("%d\n", rje);

  return 0;
}