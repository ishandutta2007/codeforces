#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9; 
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;
            
bool cmp (const vi& a, const vi& b)
{
  assert(a.size()==b.size());
  for (int i=0; i<(int)a.size(); i++)
    if (a[i]!=b[i])
      return a[i]<b[i];
  return 0;
}

vi A[8];
int e, V[1231][3];
ll Len[1231];
vi T[8];

ll vp (int a, int b)
{
  return V[a][0]*1ll*V[b][0]+V[a][1]*1ll*V[b][1]+V[a][2]*1ll*V[b][2];
}

void gen (int a, int b, int c)
{
  int M[3]={a,b,c};
  for (int i=0; i<8; i++)
    T[i]=A[0];
  for (int i=0; i<8; i++)
    for (int j=0; j<3; j++)
      if (i&(1<<j))
        for (int k=0; k<3; k++)
          T[i][k]+=V[M[j]][k];
}

int main()
{
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (int i=0; i<8; i++)
  {
    A[i].resize(3);
    for (int j=0; j<3; j++)
      scanf("%d", &A[i][j]);
    sort(A[i].begin(),A[i].end());
  }  
  vi AA[8];
  for (int i=0; i<8; i++)
    AA[i]=A[i];
  sort(A,A+8,cmp);
  for (int i=1; i<8; i++)
  {
    int Tp[3]={0,1,2};
    do {
      for (int j=0; j<3; j++)
        V[e][j]=A[i][Tp[j]]-A[0][j], Len[e]+=V[e][j]*1ll*V[e][j];
      //if (Len[e]==3)
      //  cerr<<V[e][0]<<" "<<V[e][1]<<" "<<V[e][2]<<endl;
      e++;
    } while (next_permutation(Tp,Tp+3));
  }
  for (int i1=0; i1<e; i1++)
    for (int i2=i1+1; i2<e; i2++)
      for (int i3=i2+1; i3<e; i3++)
      {
        if (Len[i1]==0 || Len[i2]!=Len[i1] || Len[i3]!=Len[i1])
          continue;


        /*cerr<<V[i1][0]<<" "<<V[i1][1]<<" "<<V[i1][2]<<endl;
        cerr<<V[i2][0]<<" "<<V[i2][1]<<" "<<V[i2][2]<<endl;
        cerr<<V[i3][0]<<" "<<V[i3][1]<<" "<<V[i3][2]<<endl;

        cerr<<endl;
        cerr<<endl;
        cerr<<endl;*/

        if (vp(i1,i2)!=0 || vp(i1,i3)!=0 || vp(i2,i3)!=0)
          continue;
        gen(i1,i2,i3);
        for (int i=0; i<8; i++)
          sort(T[i].begin(),T[i].end());
        vi TT[8];
        for (int i=0; i<8; i++)
          TT[i]=T[i];
        sort(T,T+8,cmp);
        bool fl=0;
        for (int i=0; i<8; i++)
          for (int j=0; j<3; j++)
            if (T[i][j]!=A[i][j])
              fl=1;
        if (fl)
           continue;
        gen(i1,i2,i3);
        puts("YES");
        for  (int i=0; i<8; i++, printf("\n"))
          for (int id=0; id<8; id++)
            if (TT[id]==AA[i])
            {
              for (int j=0; j<3; j++)
                printf("%d ", T[id][j]);
              TT[id].clear();
              break;
            }
        return 0;
      }
  puts("NO");
  TIMESTAMP(end);
  return 0;
}