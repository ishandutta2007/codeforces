#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL K;
int V,dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int d[SIZE],a[1111][1111],p[1111][1111],nn[SIZE],n,m,an[1111][1111];
int find(int x){
 if(d[x]==x)return x;
 return d[x]=find(d[x]);
}
void uu(int x,int y){
 x=find(x);
 y=find(y);
 if(x!=y)nn[y]+=nn[x],d[x]=y;
}
void f(int x,int y,int g,int&r){
 if(!r||x<0||x>=n||y<0||y>=m||an[x][y])return;
 if(find(p[x][y])!=g)return;
 an[x][y]=V;
 r--;
 REP(i,4){
  f(x+dx[i],y+dy[i],g,r);
 }
}
int main(){
 RII(n,m);cin>>K;
 int id=0;
 vector<pair<int,PII> >pp;
 REP(i,n)REP(j,m){
  RI(a[i][j]);
  if(a[i][j]==K){
    an[i][j]=K;puts("YES");
    REP(ii,n)REP(jj,m)
     printf("%d%c",an[ii][jj],jj==m-1?'\n':' ');
    return 0;
  }
  d[id]=id;
  nn[id]=1;
  pp.PB(MP(a[i][j],MP(i,j)));
  p[i][j]=id++;
 }
 sort(ALL(pp));
 reverse(ALL(pp));
 REP(i,SZ(pp)){
  int x=pp[i].S.F,y=pp[i].S.S;
  int v=pp[i].F;
  REP(j,4){
   int nx=x+dx[j],ny=y+dy[j];
   int me=p[x][y];
   if(nx<0||nx>=n||ny<0||ny>=m)continue;
   if(a[x][y]<=a[nx][ny])
    uu(p[x][y],p[nx][ny]);
   if(K%v==0&&nn[find(me)]>=K/v){
    puts("YES");
    int r=K/v;
    V=v;
    f(x,y,find(me),r);
    REP(ii,n)REP(jj,m)
     printf("%d%c",an[ii][jj],jj==m-1?'\n':' ');
    return 0;
   }
  }
 }
 puts("NO");
 return 0;
}