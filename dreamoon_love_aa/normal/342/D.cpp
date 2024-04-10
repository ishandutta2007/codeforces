#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
#define F first
#define S second
using namespace std;
#define SIZE 10010
const int MOD=(int)1e9+7;
char s[3][SIZE];
int ban[SIZE];
long long dp[SIZE][8][2];
int get_bit(int x,int v){
    return (x>>v)&1;
}
void add(long long &x,long long v){
    x+=v;
    x%=MOD;
    if(x<0)x+=MOD;
}
int main(){
    DRI(n);
    REP(i,3)scanf("%s",s[i]+1);
    REP(i,3)
        REP(j,n)if(s[i][j+1]!='.')ban[j+1]|=1<<i;
    dp[0][7][0]=1;
    REPP(i,1,n+1){
        REP(j,8){
            if(!dp[i-1][j])continue;
            bool no=false;
            int tmp=ban[i],oo=0;
            REP(k,3){
                if(!get_bit(j,k)){
                    if(get_bit(ban[i],k))no=true;
                    else{
                        tmp|=1<<k;
                        if(s[k][i+1]=='O'||s[k][i-2]=='O')oo=1;
                    }
                }
            }
            if(no)continue;
            switch(tmp){
                case 0:
                    REP(k,2){
                        add(dp[i][0][k|oo],dp[i-1][j][k]);
                        add(dp[i][3][k|oo],dp[i-1][j][k]);
                        add(dp[i][6][k|oo],dp[i-1][j][k]);
                    }
                    break;
                case 1:
                    REP(k,2){
                        add(dp[i][1][k|oo],dp[i-1][j][k]);
                        if(s[0][i]=='O')add(dp[i][7][1],dp[i-1][j][k]);
                        else add(dp[i][7][k|oo],dp[i-1][j][k]);
                    }
                    break;
                case 2:
                    REP(k,2){
                        add(dp[i][2][k|oo],dp[i-1][j][k]);
                    }
                    break;
                case 3:
                    REP(k,2){
                        add(dp[i][3][k|oo],dp[i-1][j][k]);
                    }
                    break;
                case 4:
                    REP(k,2){
                        add(dp[i][4][k|oo],dp[i-1][j][k]);
                        if(s[2][i]=='O')add(dp[i][7][1],dp[i-1][j][k]);
                        else add(dp[i][7][k|oo],dp[i-1][j][k]);
                    }
                    break;
                case 5:
                    REP(k,2){
                        add(dp[i][5][k|oo],dp[i-1][j][k]);
                    }
                    break;
                case 6:
                    REP(k,2){
                        add(dp[i][6][k|oo],dp[i-1][j][k]);
                    }
                    break;
                case 7:
                    REP(k,2){
                        add(dp[i][7][k|oo],dp[i-1][j][k]);
                    }
                    break;
            }
        }
    }
    cout<<dp[n][7][1]<<endl;
    return 0;
}