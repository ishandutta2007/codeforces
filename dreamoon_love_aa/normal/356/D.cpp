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
#define SIZE 70005
int dp[SIZE][2],s,n,contain[SIZE],a[SIZE];
vector<int>id[SIZE];
vector<int>an[SIZE];
int cnt[SIZE],use[SIZE];
void go(int x,int m){
    int two=1;
    while(m>0){
        int mi=min(m,two);
        if((long long)x*mi<=s){
            for(int i=s-x*mi;i>=0;i--){
                if(dp[i][0]&&!dp[i+x*mi][0]){
                    dp[i+x*mi][0]=x;
                    dp[i+x*mi][1]=mi;
                }
            }
        }
        m-=mi;
        two<<=1;
    }
}
int main(){
    int ma=0;
    RII(n,s);
    REP(i,n){
        DRI(x);
        a[i]=x;
        cnt[x]++;
        id[x].PB(i);
        ma=max(ma,x);
    }
    if(ma>s){
        puts("-1");
        return 0;
    }
    cnt[ma]--;
    s-=ma;
    dp[0][0]=1;
    REPP(i,1,ma+1){
        if(cnt[i]){
            go(i,cnt[i]);
        }
        if(dp[s][0])break;
    }
    if(!dp[s][0])puts("-1");
    else{
        int now=s;
        while(now){
            use[dp[now][0]]+=dp[now][1];
            now-=dp[now][0]*dp[now][1];
        }
        REPP(i,1,ma+1){
            REP(j,use[i])contain[id[i][j]]=i;
        }
        int lst=-1;
        for(int i=ma;i>=0;i--){
            REP(j,SZ(id[i])){
                if(!contain[id[i][j]]){
                    if(lst!=-1){
                        contain[lst]=a[lst]-a[id[i][j]];
                        an[lst].PB(id[i][j]);
                    }
                    lst=id[i][j];
                }
            }
        }
        if(lst!=-1)contain[lst]=a[lst];
        REP(i,n){
            printf("%d %d",contain[i],SZ(an[i]));
            REP(j,SZ(an[i]))printf(" %d",an[i][j]+1);
            puts("");
        }
    }
    //pp
    return 0;
}