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
#define FIRST 0
#define SECOND 1
using namespace std;
const int MM=45;
char s[25][25];
int dp[41][1<<20];
int f(char c){
    if(c=='a')return 1;
    if(c=='b')return -1;
    return 0;
}
int main(){
    int two;
    DRI(n);
    two=(1<<n);
    REP(i,n)RS(s[i]);
    dp[n+n-2][1<<(n-1)]=0;
    for(int i=n+n-3;i>=0;i--){
        int mask;
        if(i<n)mask=(1<<(i+1))-1;
        else mask=(1<<n)-(1<<(i-n+1));
        for(int now=mask;now;now=(now-1)&mask){
            bool fail=false;
            char c=0;
            int nxt[26]={};
            for(int j=0;(1<<j)<=now;j++){
                if((now>>j)&1){
                    if(!c)c=s[j][i-j];
                    else{
                        if(c!=s[j][i-j]){
                            fail=true;
                            break;
                        }
                    }
                    int y=i-j;
                    if(j+1<n)nxt[s[j+1][y]-'a']|=1<<(j+1);
                    if(y+1<n)nxt[s[j][y+1]-'a']|=1<<j;
                }
            }
            if(fail)continue;
            int player,res;
            if(i&1){
                player=FIRST;
                res=-1000;
            }
            else{
                player=SECOND;
                res=10000;
            }
            for(int j=0;j<26;j++){
                if(!nxt[j])continue;
                if(player==FIRST)res=max(res,dp[i+1][nxt[j]]+f('a'+j));
                else if(player==SECOND)res=min(res,dp[i+1][nxt[j]]+f('a'+j));
            }
            dp[i][now]=res;
        }
    }
    if(dp[0][1]+f(s[0][0])>0)puts("FIRST");
    else if(dp[0][1]+f(s[0][0])==0)puts("DRAW");
    else puts("SECOND");
    return 0;
}