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
int row[26],cc[26][2];
int tt,used[3][100][500];
int M,K;
char s[3][125];
int dx[4]={1,0,-1};
int dy[4]={1,1,1};
bool suc;
bool Out(int x,int y){
    return x<0||y<0||x>=3||y>=M;
}
void dfs(int x,int y,int step){
    used[x][y][step]=tt;
    if(step>=450)return;
    if(y==M-1){
        suc=1;
        return;
    }
    REP(i,3){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(Out(nx,ny))continue;
        if(used[nx][ny][step+1]==tt)continue;
        bool err=0;
        REP(k,26){
            if(cc[k][0]==-1)continue;
            if(nx==row[k]){
                if(ny<=cc[k][1]-2*step&&ny>=cc[k][0]-2*step-2){
                    err=1;
                    break;
                }
            }
            if(x==row[k]){
                if(ny<=cc[k][1]-2*step&&ny>=cc[k][0]-2*step){
                    err=1;
                    break;
                }
            }
        }
        if(err)continue;
        dfs(nx,ny,step+1);
    }
}
int main(){
    CASET{
        suc=0;
        tt++;
        MS1(cc);
        int st_x;
        RII(M,K);
        REP(i,3){
            RS(s[i]);
            REP(j,M){
                if(s[i][j]=='s')st_x=i;
                else if(s[i][j]!='.'){
                    int me=s[i][j]-'A';
                    row[me]=i;
                    if(cc[me][0]==-1)cc[me][0]=j;
                    cc[me][1]=j;
                }
            }
        }
        dfs(st_x,0,0);
        puts(suc?"YES":"NO");
    }
    return 0;
}