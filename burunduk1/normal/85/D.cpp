/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <fstream>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)

typedef double dbl;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class T> T inline sqr(T x) { return x * x; }
template <class T> inline void relaxMin( T &a, T b ) { a = min(a, b); }
template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

inline int sign( int x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
inline int myAbs( int a ) { return a > 0 ? a : -a; }

struct tree 
{
  int x, y, si;
  ll sum[5];
  tree *l, *r;
};

const int maxt = (int)1e5 + 10;

tree mem[maxt];
int mpos = 1;
tree *Null = mem;

void Calc( tree *t )
{
  if (t == Null)
    return;
  t->si = 1 + t->l->si + t->r->si;
  forn(i, 5)
    t->sum[i] = t->l->sum[i];
  int sh = t->l->si;
  t->sum[sh % 5] += t->x;
  sh++;
  forn(i, 5)
    t->sum[(i + sh) % 5] += t->r->sum[i];
}

tree *NewT( int x )
{
  tree *t = mem + mpos++;
  t->y = (rand() << 15) + rand();
  t->x = x;
  t->l = t->r = Null;
  Calc(t);
  return t;
}

void Split( tree *t, tree **l, tree **r, int x )
{
  if (t == Null)
    *l = *r = Null;
  else if (t->x < x)
    *l = t, Split(t->r, &t->r, r, x);
  else
    *r = t, Split(t->l, l, &t->l, x);
  Calc(*l), Calc(*r);  
}

void Merge( tree **t, tree *l, tree *r )
{
  if (l == Null || r == Null)
  {
    *t = max(l, r);
    return;
  }
  if (l->y < r->y)
    *t = l, Merge(&(*t)->r, (*t)->r, r);
  else
    *t = r, Merge(&(*t)->l, l, (*t)->l);
  Calc(*t);
}

void Add( tree **t, int x )
{
  tree *l, *r, *m;
  Split(*t, &l, &r, x);
  Merge(&m, l, NewT(x));
  Merge(t, m, r);
}

void Del( tree **t, int x )
{
  tree *l, *m, *r, *tmp;
  Split(*t, &l, &tmp, x);
  Split(tmp, &m, &r, x + 1);
  Merge(t, l, r);
}

void Out( tree *t, int dep )
{
  if (t == Null)
    return;
  Out(t->l, dep + 1);
  fprintf(stderr, "%*s(x=%d,si=%d,sum={%I64d,%I64d,%I64d,%I64d,%I64d})\n", dep * 2, "", t->x, t->si, t->sum[0], t->sum[1], t->sum[2], t->sum[3], t->sum[4]);
  Out(t->r, dep + 1);
}

int main()
{
  Null->l = Null->r = Null;

  tree *root = Null;
  int n;
  scanf("%d", &n);
  srand((int)1e9 + 7);
  while (n--)
  {
    char com[9];
    int x;
    scanf("%s", com);
    //fprintf(stderr, "com = %s\n", com);
    if (!strcmp(com, "add"))
    {
      scanf("%d", &x);
      Add(&root, x);
    }
    else if (!strcmp(com, "del"))
    {
      scanf("%d", &x);
      Del(&root, x);
    }
    else
    {
      printf("%I64d\n", root->sum[2]);
    }
    //fprintf(stderr, "Out\n");
    /*
    puts("");
    Out(root, 0);
    puts("");
    */
  }
  return 0;
}