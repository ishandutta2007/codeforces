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
int n,m,an[5001],ty[5001],l[5001],r[5001],v[5001],add[5001];
int main(){
    RII(n,m);
    REPP(i,1,n+1)an[i]=(int)1e9;
    REP(i,m){
        RII(ty[i],l[i]);
        RII(r[i],v[i]);
        if(ty[i]==1){
            for(int j=l[i];j<=r[i];j++)add[j]+=v[i];
        }
        else{
            for(int j=l[i];j<=r[i];j++){
                an[j]=min(an[j],v[i]-add[j]);
            }
        }
    }
    int tmp[5001];
    memcpy(tmp,an,sizeof(an));
    REP(i,m){
        if(ty[i]==1){
            for(int j=l[i];j<=r[i];j++)tmp[j]+=v[i];
        }
        else{
            int ma=-((int)1e9+5);
            for(int j=l[i];j<=r[i];j++){
                ma=max(ma,tmp[j]);
            }
            if(ma!=v[i]){
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    REPP(i,1,n+1){
        if(i!=1)printf(" ");
        printf("%d",an[i]);
    }
    return 0;
}