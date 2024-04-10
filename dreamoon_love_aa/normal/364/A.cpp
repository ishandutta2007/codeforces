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
const int SIZE = 400000;
char s[SIZE];
int cnt[SIZE];
int main(){
    int zero=0,non_zero=0;
    DRI(a);
    RS(s);
    int n=LEN(s);
    REP(i,n){
        int now=0;
        REPP(j,i,n){
            now+=s[j]-'0';
            cnt[now]++;
            if(now==0)zero++;
            else non_zero++;
        }
    }
    if(a==0){
        cout<<(long long)(zero+non_zero)*(zero+non_zero)-(long long)non_zero*non_zero<<endl;
    }
    else{
        long long res=0;
        for(int i=1;i<SIZE&&i<=a;i++){
            if(!cnt[i])continue;
            if(a%i==0&&a/i<SIZE){
                res+=(long long)cnt[i]*cnt[a/i];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}