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
int N,M;
char s[SIZE][SIZE];
bool used[SIZE][SIZE];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool Out(int x,int y){return x<0||y<0||x>=N||y>=M;}
PII bfs[SIZE*SIZE];
int v[SIZE*SIZE],step[1000][1000];
void Go(int sx,int sy){
    bfs[0]=MP(sx,sy);
    used[sx][sy]=1;
    int rr=1;
    int me;
    REP(i,rr){
        int x=bfs[i].F;
        int y=bfs[i].S;
        REP(k,4){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(Out(nx,ny)||s[nx][ny]=='T'||used[nx][ny])continue;
            used[nx][ny]=1;
            step[nx][ny]=step[x][y]+1;
            if(s[nx][ny]!='S')v[step[nx][ny]]+=s[nx][ny]-'0';
            else me=step[nx][ny];
            bfs[rr++]=MP(nx,ny);
        }
    }
    int an=0;
    REP(i,me+1)an+=v[i];
    cout<<an;
}
int main(){
    RII(N,M);
    int sx,sy;
    REP(i,N){
        RS(s[i]);
        REP(j,M){
            if(s[i][j]=='E')sx=i,sy=j;
        }
    }
    Go(sx,sy);
    return 0;
}