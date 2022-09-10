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
const int SIZE = 1e3+10;
char s[SIZE][SIZE];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool in[1111][1111];
int v[1111][1111];
int n,m;
bool Out(int x,int y){return x<0||y<0||x>=n||y>=m;}
int f(int x,int y){
    if(v[x][y])return v[x][y];
    in[x][y]=1;
    v[x][y]=1;
    REP(i,4){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(Out(nx,ny)||s[nx][ny]!=(s[x][y]+1)%4)continue;
        if(in[nx][ny]){puts("Poor Inna!");exit(0);}
        v[x][y]=max(v[x][y],f(nx,ny)+1);
    }
    in[x][y]=0;
    return v[x][y];
}
int get(char c){
    if(c=='D')return 0;
    if(c=='I')return 1;
    if(c=='M')return 2;
    if(c=='A')return 3;
}
int main(){
    RII(n,m);
    REP(i,n){
        RS(s[i]);
        REP(j,m)
            s[i][j]=get(s[i][j]);
    }
    int an=0;
    REP(i,n)REP(j,m)
        if(s[i][j]==0)an=max(an,f(i,j));
    an>>=2;
    if(!an)puts("Poor Dima!");
    else printf("%d\n",an);
    return 0;
}