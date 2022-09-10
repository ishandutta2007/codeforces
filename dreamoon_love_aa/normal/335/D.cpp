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
int dp[3002][3002],row[3001][3001],col[3001][3001],No[3001][3001],ma[3002][3002];
int get_area(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dp[x2][y2]+dp[x1][y1]-dp[x1][y2]-dp[x2][y1];
}
int get_row(int id,int ll,int rr){return row[id][rr]-row[id][ll];}
int get_col(int id,int ll,int rr){return col[id][rr]-col[id][ll];}
void print(int x1,int y1,int x2,int y2){
    vector<int>res;
    REPP(i,x1,x2+1)
        REPP(j,y1,y2+1){
            if(No[i][j])res.PB(No[i][j]);
        }
    printf("YES %d\n",SZ(res));
    REP(i,SZ(res)){
        if(i)printf(" ");
        printf("%d",res[i]);
    }
    puts("");
}
bool go(int x,int y){
    int x2=x,y2=y,n=1;
    while(x2<=3000&&y2<=3000){
        if(get_area(x,y,x2,y2)==n*n){
            if(get_row(x-1,y-1,y2)==n
            && get_row(x2,y-1,y2)==n
            && get_col(y-1,x-1,x2)==n
            && get_col(y2,x-1,x2)==n){
                print(x,y,x2,y2);
                return 1;
            }
        }
        else return 0;
        int tmp=ma[x2+1][y2+1]+1;
        n+=tmp;
        x2+=tmp;
        y2+=tmp;
    }
    return 0;
}
int main(){
    DRI(n);
    REP(i,n){
        DRII(x1,y1);
        DRII(x2,y2);
        No[x1+1][y1+1]=i+1;
        REPP(j,x1+1,x2+1)REPP(k,y1+1,y2+1){
            dp[j][k]=1;
            ma[j][k]=max(x2-j,y2-k);
        }
        REPP(j,y1+1,y2+1)row[x1][j]=row[x2][j]=1;
        REPP(j,x1+1,x2+1)col[y1][j]=col[y2][j]=1;
    }
    REPP(i,1,3001)
        REPP(j,1,3001)dp[i][j]+=dp[i][j-1];
    REPP(i,1,3001)
        REPP(j,1,3001)dp[i][j]+=dp[i-1][j];
    REP(i,3001)
        REPP(j,1,3001)row[i][j]+=row[i][j-1];
    REP(i,3001)
        REPP(j,1,3001)col[i][j]+=col[i][j-1];
    REPP(i,1,3001)
        REPP(j,1,3001){
            if(No[i][j]){
                if(go(i,j))return 0;
            }
        }
    puts("NO");
    return 0;
}