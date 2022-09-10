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
int p[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
int cnt[20];
int up,d[10000000],dn;
void dfs(int x,int v,int n){
    if(x==n){
        d[dn++]=v;
        return;
    }
    dfs(x+1,v,n);
    while(v*p[x]<=up){
        v*=p[x];
        dfs(x+1,v,n);
    }
}
int main(){
    DRI(K);
    up=2*K*K;
    for(int i=2;;i++){
        dn=0;
        dfs(0,1,i);
        if(dn<K*2)continue;
        sort(d,d+dn);
        MS0(cnt);
        REP(j,K){
            if(j)printf(" ");
            REP(k,i)if(d[dn-1-j]%p[k]==0)cnt[k]++;
            printf("%d",d[dn-1-j]);
        }
        REP(j,i)
            if(cnt[j]*2<K)fprintf(stderr,"haha!\n");
        puts("");
        return 0;
    }
    return 0;
}