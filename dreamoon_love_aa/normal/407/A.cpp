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
int main(){
    DRII(a,b);
    for(int i=1;i*i<a*a;i++){
        for(int j=1;j*j<b*b;j++){
            int i2=sqrt(a*a-i*i+1e-9);
            int j2=sqrt(b*b-j*j+1e-9);
            if(i*i+i2*i2==a*a&&j*j+j2*j2==b*b){
                if(i*j2==i2*j){
                    if(i2!=j){
                        puts("YES");
                        printf("0 0\n");
                        printf("%d %d\n",i,i2);
                        printf("%d %d\n",-j2,j);
                        return 0;
                    }
                    if(i!=j2){
                        puts("YES");
                        printf("0 0\n");
                        printf("%d %d\n",i,i2);
                        printf("%d %d\n",j2,-j);
                        return 0;
                    }
                }
            }
        }
    }
    puts("NO");
    return 0;
}