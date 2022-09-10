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
const int SIZE = 1002;
int cnt[26][SIZE][SIZE];
LL base_dif[SIZE][SIZE],sp_dif[26][SIZE][SIZE];
char s[SIZE][SIZE];
PII input[300000][2];
int rc[300000],n,m,K;
LL get(PII LU,PII RD,int cc){
    LL res=base_dif[n][m]-base_dif[RD.F][RD.S]-base_dif[LU.F][LU.S]+base_dif[RD.F][LU.S]+base_dif[LU.F][RD.S];
    //printf("{%I64d}",res);
    return res+sp_dif[cc][RD.F][RD.S]+sp_dif[cc][LU.F][LU.S]-sp_dif[cc][RD.F][LU.S]-sp_dif[cc][LU.F][RD.S];
}
int main(){
    RIII(n,m,K);
    REP(i,n){
        RS(s[i+1]+1);
        REP(j,m)s[i+1][j+1]-='a';
    }
    REP(i,K){
        DRII(x1,y1);
        DRII(x2,y2);
        x2++;y2++;
        char c[4];
        RS(c);
        c[0]-='a';
        cnt[c[0]][x1][y1]++;
        cnt[c[0]][x2][y2]++;
        cnt[c[0]][x1][y2]--;
        cnt[c[0]][x2][y1]--;

        input[i][0]=MP(x1-1,y1-1);
        input[i][1]=MP(x2-1,y2-1);
        rc[i]=c[0];
    }
    REP(i,26){
        REPP(j,1,n+1)REPP(k,1,m+1)cnt[i][j][k]+=cnt[i][j][k-1];
        REPP(j,1,n+1)REPP(k,1,m+1)cnt[i][j][k]+=cnt[i][j-1][k];
        REPP(j,1,n+1)REPP(k,1,m+1)base_dif[j][k]+=cnt[i][j][k]*abs(i-s[j][k]);
    }
    REP(cc,26){
        REPP(j,1,n+1)REPP(k,1,m+1){
            int all=K;
            REP(i,26){
                sp_dif[cc][j][k]+=cnt[i][j][k]*abs(i-cc);
                all-=cnt[i][j][k];
            }
            sp_dif[cc][j][k]+=all*abs(s[j][k]-cc);
        }
    }
    REPP(i,1,n+1)REPP(j,1,m+1)base_dif[i][j]+=base_dif[i][j-1];
    REPP(i,1,n+1)REPP(j,1,m+1)base_dif[i][j]+=base_dif[i-1][j];
    REP(cc,26){
        REPP(i,1,n+1)REPP(j,1,m+1)sp_dif[cc][i][j]+=sp_dif[cc][i][j-1];
        REPP(i,1,n+1)REPP(j,1,m+1)sp_dif[cc][i][j]+=sp_dif[cc][i-1][j];
    }
    LL an=1e18;
    REP(i,K){
        //printf("[%I64d]\n",get(input[i][0],input[i][1],rc[i]));
        an=min(an,get(input[i][0],input[i][1],rc[i]));
    }
    printf("%I64d\n",an);
    return 0;
}