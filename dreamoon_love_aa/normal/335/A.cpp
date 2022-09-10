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
int d[128];
int main(){
    string str;
    int ma=0;
    cin>>str;
    DRI(n);
    REP(i,SZ(str)){
        d[str[i]]++;
        ma=max(ma,d[str[i]]);
    }
    int cnt=0;
    REP(i,128){
        if(d[i])cnt++;
    }
    if(cnt>n){
        puts("-1");
        return 0;
    }
    int k;
    for(k=1;;k++){
        int need=0;
        REP(i,128){
            need+=(d[i]+k-1)/k;
        }
        if(need<=n){
            printf("%d\n",k);
            REP(i,128){
                int now=0;
                while(now<d[i]){
                    printf("%c",i);
                    now+=k;
                    n--;
                }
            }
            while(n>0){
                printf("a");
                n--;
            }
            puts("");
            return 0;
        }
    }
    return 0;
}