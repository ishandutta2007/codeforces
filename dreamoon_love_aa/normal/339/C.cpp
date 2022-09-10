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
char s[15];
int dp[1024][11][11];
void print(int x,int y,int z){
    if(!x)return;
    print(x-1,z-y,dp[x][y][z]);
    if(x!=1)printf(" ");
    printf("%d",z);
}
int main(){
    RS(s+1);
    DRI(m);
    REPP(i,1,11){
        if(s[i]=='1')dp[1][i][i]=1;
    }
    REPP(i,1,m){
        REPP(j,1,11)
            REPP(r,1,11)
                if(dp[i][j][r]){
                    REPP(k,1,11){
                        if(s[k]=='1'&&k>j&&k!=r){
                            dp[i+1][k-j][k]=r;
                        }
                    }
                }
    }
    REPP(i,1,11){
        REPP(j,1,11)
            if(dp[m][i][j]){
                puts("YES");
                print(m,i,j);
                return 0;
            }
    }
    puts("NO");
    return 0;
}