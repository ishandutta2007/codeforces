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
VI step[2];
int dp[2][SIZE];
int lose_cnt[2][SIZE];
string str[3]={"Loop","Lose","Win"};
int main(){
    DRI(N);
    REP(i,2){
        DRI(m);
        REP(j,m){
            DRI(x);
            step[i].PB(x);
        }
    }
    bool go=true;
    MS1(dp);
    dp[0][0]=dp[1][0]=0;
    queue<PII>qq;
    qq.push(MP(0,0));
    qq.push(MP(1,0));

    while(SZ(qq)){
        PII now=qq.front();qq.pop();
        if(dp[now.F][now.S]==1){
            REP(i,SZ(step[now.F^1])){
                int v=step[now.F^1][i];
                lose_cnt[now.F^1][(now.S+v)%N]++;
                if(lose_cnt[now.F^1][(now.S+v)%N]==SZ(step[now.F^1])){
                    dp[now.F^1][(now.S+v)%N]=0;
                    qq.push(MP(now.F^1,(now.S+v)%N));
                }
            }
        }
        else if(dp[now.F][now.S]==0){
            REP(i,SZ(step[now.F^1])){
                int v=step[now.F^1][i];
                if(dp[now.F^1][(now.S+v)%N]==-1){
                    dp[now.F^1][(now.S+v)%N]=1;
                    qq.push(MP(now.F^1,(now.S+v)%N));
                }
            }
        }
        else{
            assert(0);
        }
    }
    REP(i,2){
        for(int j=N-1;j>0;j--)printf("%s%c",str[dp[i][j]+1].c_str()," \n"[j==1]);
    }
    return 0;
}