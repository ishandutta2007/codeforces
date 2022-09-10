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
const int SIZE = 1e5+5;
const int MAX = 1e9;
int a[SIZE],dp[SIZE];
vector<int>pos[SIZE];
int main(){
    DRII(n,m);
    DRII(s,e);
    REP(i,n)RI(a[i+1]);
    REP(i,m){
        DRI(x);
        pos[x].PB(i+1);
    }
    int an=0;
    REPP(i,1,n+1)dp[i]=MAX;
    REPP(i,1,1000){
        if(i*e>s)break;
        int ll=MAX;
        if(i==1)ll=0;
        int mi=MAX;
        REPP(j,1,n+1){
            int now=a[j];
            int it=lower_bound(ALL(pos[now]),ll+1)-pos[now].begin();
            ll=min(dp[j],ll);
            if(it==pos[now].size())dp[j]=m+1;
            else{
                dp[j]=pos[now][it];
                mi=min(mi,j+dp[j]);
            }
        }
        if(mi+i*e<=s)an=max(an,i);
    }
    printf("%d\n",an);
    return 0;
}