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
#define SIZE 100010
#define MAX 2147483647
int a[SIZE];
vector<int>res;
int main(){
    int ma=-1;
    DRI(n);
    REP(i,n)RI(a[i]);
    REP(i,30){
        int now=MAX;
        vector<int>tmp;
        REP(j,n){
            if((a[j]>>i)&1){
                tmp.PB(a[j]);
                now&=a[j];
            }
        }
        REP(j,30){
            if((now>>j)&1){
                if(j>ma||(j==ma&&SZ(tmp)>SZ(res))){
                    ma=j;
                    res=tmp;
                }
                break;
            }
        }
    }
    printf("%d\n",SZ(res));
    REP(i,SZ(res)){
        if(i)printf(" ");
        printf("%d",res[i]);
    }
    puts("");
    return 0;
}