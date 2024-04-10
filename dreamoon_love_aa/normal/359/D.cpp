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
#define SIZE 300010
int a[SIZE],used[SIZE],ma;
vector<int>res;
vector<pair<int,int> >pp;

int main(){
    DRI(n);
    REP(i,n){
        RI(a[i]);
        pp.PB(MP(a[i],i));
    }
    sort(ALL(pp));
    REP(i,n){
        int idx=pp[i].S;
        if(used[idx])continue;
        int ll=idx,rr=idx;
        used[idx]=1;
        while(ll-1>=0&&used[ll-1]==0&&a[ll-1]%a[idx]==0){
            ll--;
            used[ll]=1;
        }
        while(rr+1<n&&used[rr+1]==0&&a[rr+1]%a[idx]==0){
            rr++;
            used[rr]=1;
        }
        if(rr-ll>ma){
            ma=rr-ll;
            res.clear();
            res.PB(ll+1);
        }
        else if(rr-ll==ma)res.PB(ll+1);
        used[ll]=used[rr]=0;
    }
    sort(ALL(res));
    res.resize(unique(ALL(res))-res.begin());
    printf("%d %d\n",SZ(res),ma);
    REP(i,SZ(res)){
        if(i)printf(" ");
        printf("%d",res[i]);
    }
    puts("");
    return 0;
}