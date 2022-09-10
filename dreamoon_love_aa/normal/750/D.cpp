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
#define PB push
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
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int v[400][400][8],used[400][400];
int main(){
    DRI(n);
    VI d;
    d.push_back(0);
    REP(i,n){
        DRI(x);
        d.push_back(x);
    }
    queue<int>bfs[2];
    int now=0,nxt=1;
    bfs[now].PB(200);bfs[now].PB(200);bfs[now].PB(0);
    REPP(lv,1,n+1){
        int dd=d[lv];
        while(SZ(bfs[now])){
            int x=bfs[now].front();bfs[now].pop();
            int y=bfs[now].front();bfs[now].pop();
            int dir=bfs[now].front();bfs[now].pop();
            used[x][y]=1;
            REPP(i,1,dd){
                x+=dx[dir];
                y+=dy[dir];
                used[x][y]=1;
            }
            int nxt_dir=(dir+1)&7;
            if(v[x+dx[nxt_dir]][y+dy[nxt_dir]][nxt_dir]!=lv){
                v[x+dx[nxt_dir]][y+dy[nxt_dir]][nxt_dir]=lv;
                bfs[nxt].push(x+dx[nxt_dir]);
                bfs[nxt].push(y+dy[nxt_dir]);
                bfs[nxt].push(nxt_dir);
            }
            nxt_dir=(dir+7)&7;
            if(v[x+dx[nxt_dir]][y+dy[nxt_dir]][nxt_dir]!=lv){
                v[x+dx[nxt_dir]][y+dy[nxt_dir]][nxt_dir]=lv;
                bfs[nxt].push(x+dx[nxt_dir]);
                bfs[nxt].push(y+dy[nxt_dir]);
                bfs[nxt].push(nxt_dir);
            }
        }
        swap(now,nxt);
    }
    int an=0;
    REP(i,400)REP(j,400)
        if(used[i][j])an++;
    cout<<an<<endl;
    return 0;
}