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
#define MAX 1000000000000000010
vector<long long>res;
long long f(long long two,int pp,long long x,long long n){
    if((1ll<<pp)-1>n/x)return MAX;
    return x*(x-1)/2+((1ll<<pp)-1)*x;
}
void check(long long two,int pp,long long n){
    long long ll=1,rr=1500000001ll;
    while(ll<rr){
        long long mm=(ll+rr)/2;
        long long v=f(two,pp,mm*2-1,n);
        if(v<n)ll=mm+1;
        else if(v>n)rr=mm-1;
        else{
            ll=rr=mm;
            break;
        }
    }
    if(f(two,pp,ll*2-1,n)==n)res.PB((ll*2-1)<<pp);
}
int main(){
    long long n;
    cin>>n;
    REP(i,60){
        check(1ll<<i,i,n);
    }
    sort(ALL(res));
    if(SZ(res)==0)puts("-1");
    else REP(i,SZ(res))cout<<res[i]<<endl;
    return 0;
}