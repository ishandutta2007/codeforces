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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 256;
char s[SIZE][SIZE];
LL v[SIZE][SIZE];
int n,m;
bool Out(int x,int y){return x<0||x>=n||y<0||y>=m||s[x][y]=='*';}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
PII bfs[SIZE*SIZE];
int u[SIZE*SIZE];
int used[SIZE][SIZE],tt;
void go(int x,int y,int g){
    int rr=1;
    bfs[0]=MP(x,y);
    tt++;
    used[x][y]=tt;
    u[0]=g;
    REP(i,rr){
        v[bfs[i].F][bfs[i].S]+=u[i];
        if(u[i]<=1)continue;
        REP(j,4){
            int nx=bfs[i].F+dx[j];
            int ny=bfs[i].S+dy[j];
            if(Out(nx,ny)||used[nx][ny]==tt)continue;
            used[nx][ny]=tt;
            u[rr]=u[i]>>1;
            bfs[rr++]=MP(nx,ny);
        }
    }
}
int main(){
    RII(n,m);DRII(q,p);
    REP(i,n)RS(s[i]);
    REP(i,n)REP(j,m){
        if(s[i][j]!='.'&&s[i][j]!='*')go(i,j,(s[i][j]-'A'+1)*q);
    }
    int an=0;
    REP(i,n)REP(j,m){
        if(v[i][j]>p)an++;
    }
    printf("%d\n",an);
    return 0;
}