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
int n,m;
char s[SIZE][SIZE];
bool Out(int x,int y){return x<0||y<0||x>=n||y>=m;}
deque<PII>bfs[3];
int dis[3][SIZE][SIZE];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void Go(deque<PII> &BFS,int DIS[][SIZE]){
    while(SZ(BFS)){
        PII me=BFS.front();
        BFS.pop_front();
        REP(k,4){
            PII nxt=MP(me.F+dx[k],me.S+dy[k]);
            if(Out(nxt.F,nxt.S)||s[nxt.F][nxt.S]=='#')continue;
            int v=DIS[me.F][me.S];
            if(s[nxt.F][nxt.S]=='.')v++;
            if(DIS[nxt.F][nxt.S]!=-1&&DIS[nxt.F][nxt.S]<=v)continue;
            DIS[nxt.F][nxt.S]=v;
            if(s[nxt.F][nxt.S]=='.')
                BFS.PB(nxt);
            else
                BFS.push_front(nxt);
        }
    }
}
int main(){
    MS1(dis);
    RII(n,m);
    REP(i,n)RS(s[i]);
    REP(i,n)REP(j,m){
        if(s[i][j]!='#'&&s[i][j]!='.'){
            bfs[s[i][j]-'1'].PB(MP(i,j));
            dis[s[i][j]-'1'][i][j]=0;
        }
    }
    REP(i,3)Go(bfs[i],dis[i]);
    int an=MOD;
    REP(i,n)REP(j,m){
        if(s[i][j]=='#')continue;
        if(dis[0][i][j]!=-1&&dis[1][i][j]!=-1&&dis[2][i][j]!=-1){
            if(s[i][j]=='.'){
                an=min(an,dis[0][i][j]+dis[1][i][j]+dis[2][i][j]-2);
            }
            else{
                an=min(an,dis[0][i][j]+dis[1][i][j]+dis[2][i][j]);
            }
        }
    }
    if(an==MOD)an=-1;
    cout<<an;
    return 0;
}