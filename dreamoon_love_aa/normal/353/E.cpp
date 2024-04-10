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
char s[2000100];
int an;
int dp[1000100][3];
int get(int x){
    if(x==1)return 0;
    return 1;
}
void fresh(int &x,int v){
    x=max(x,v);
}
int main(){
    vector<int>d;
    gets(s);
    int len=LEN(s);
    int st=1;
    while(s[st]==s[st-1])st++;
    REP(i,st)s[len+i]=s[i];
    for(int i=0,j;i<len;i=j){
        for(j=i+1;j<len&&s[st+j]==s[st+i];j++);
        d.PB(get(j-i));
    }
    MS1(dp);
    dp[0][0]=0;
    for(int i=1;i<SZ(d);i++){
        fresh(dp[i][0],dp[i-1][0]);
        fresh(dp[i][0],dp[i-1][1]);
        fresh(dp[i][0],dp[i-1][2]);
        if(dp[i-1][0]!=-1)fresh(dp[i][1],dp[i-1][0]+1);
        if(d[i]){
            fresh(dp[i][2],dp[i-1][0]+1);
            fresh(dp[i][2],dp[i-1][1]+1);
            fresh(dp[i][2],dp[i-1][2]+1);
        }
    }
    an=max(an,dp[SZ(d)-1][0]);
    an=max(an,dp[SZ(d)-1][1]);
    an=max(an,dp[SZ(d)-1][2]);

    MS1(dp);
    dp[0][1]=1;
    for(int i=1;i<SZ(d);i++){
        fresh(dp[i][0],dp[i-1][0]);
        fresh(dp[i][0],dp[i-1][1]);
        fresh(dp[i][0],dp[i-1][2]);
        if(dp[i-1][0]!=-1)fresh(dp[i][1],dp[i-1][0]+1);
        if(d[i]){
            fresh(dp[i][2],dp[i-1][0]+1);
            fresh(dp[i][2],dp[i-1][1]+1);
            fresh(dp[i][2],dp[i-1][2]+1);
        }
    }
    an=max(an,dp[SZ(d)-1][0]);
    if(d[0]){
        MS1(dp);
        dp[0][2]=1;
        for(int i=1;i<SZ(d);i++){
            fresh(dp[i][0],dp[i-1][0]);
            fresh(dp[i][0],dp[i-1][1]);
            fresh(dp[i][0],dp[i-1][2]);
            if(dp[i-1][0]!=-1)fresh(dp[i][1],dp[i-1][0]+1);
            if(d[i]){
                fresh(dp[i][2],dp[i-1][0]+1);
                fresh(dp[i][2],dp[i-1][1]+1);
                fresh(dp[i][2],dp[i-1][2]+1);
            }
        }
        an=max(an,dp[SZ(d)-1][0]);
        an=max(an,dp[SZ(d)-1][1]);
        an=max(an,dp[SZ(d)-1][2]);
    }
    printf("%d\n",an);
    return 0;
}