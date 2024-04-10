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
#define SIZE 100010
using namespace std;
const int MOD = (int)1e9+7;
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1){
            res=res*x%MOD;
        }
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}
int a[SIZE];
int main(){
    DRII(n,x);
    long long sum=0;
    int ma=0;
    REP(i,n){
        RI(a[i]);
        ma=max(ma,a[i]);
        sum+=a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    int now=0,it=0,cnt=0;
    while(1){
        while(it<n&&a[it]==ma-now){cnt++;it++;}
        if(cnt%x==0){
            cnt/=x;
            now++;
        }
        else break;
    }
    cout<<mypow(x,sum-ma+min(now,ma))<<endl;
    return 0;
}