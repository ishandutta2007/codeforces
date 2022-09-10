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
#define SIZE 10010
#define MAX 10000000000000ll
long long n,m,a[SIZE];
vector<long long>fac;
int k;
bitset<1000000>p;
void fresh(long long& mod1,long long& r1,long long mod2,long long r2){
    if(mod1>mod2){
        swap(mod1,mod2);
        swap(r1,r2);
    }
    REP(i,mod1){
        if((mod2*i+r2)%mod1==r1){
            r1=mod2*i+r2;
            mod1*=mod2;
            return;
        }
    }
}
int main(){
    cin>>n>>m>>k;
    if(k>m){
        puts("NO");
        return 0;
    }
    REP(i,k)cin>>a[i];
    long long now=a[0];
    REPP(i,1,k){
        long long tmp1=now/__gcd(now,a[i]);
        long long tmp2=a[i];
        if(tmp1>MAX/tmp2){
            puts("NO");
            return 0;
        }
        now=tmp1*tmp2;
    }
    if(now>n){
        puts("NO");
        return 0;
    }
    if(now==1){
        puts("YES");
        return 0;
    }
    for(int i=2;(long long)i*i<=now;i++){
        if(now%i==0){
            long long tmp=i;
            now/=i;
            while(now%i==0){
                now/=i;
                tmp*=i;
            }
            fac.PB(tmp);
        }
    }
    if(now!=1)fac.PB(now);
    sort(ALL(fac));
    long long mod=1,r=0;
    REP(i,SZ(fac)){
        int idx;
        REP(j,k){
            if(a[j]%fac[i]==0){
                idx=j;
                break;
            }
        }
        fresh(mod,r,fac[i],(fac[i]-idx%fac[i])%fac[i]);
    }
    if(r==0)r=mod;
    if(r+k>m+1){
        puts("NO");
        return 0;
    }
    REP(i,k){
        if(__gcd(mod,r+i)!=a[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}