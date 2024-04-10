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
int n,m,p,a[SIZE],b[SIZE],used[SIZE],v[SIZE];
vector<int>pp;
long long mypow(long long x,long long y,long long mod){
    long long res=1;
    while(y){
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
bool is_root(int x){
    REP(i,SZ(pp)-1){
        if(mypow(x,pp[i],p)==1)return false;
    }
    return true;
}
vector<pair<int,int> >H;
int main(){
    RIII(n,m,p);
    if(p==2){
        puts("1");
        return 0;
    }
    for(int i=1;i*i<=p-1;i++){
        if((p-1)%i==0){
            pp.PB(i);
            pp.PB((p-1)/i);
        }
    }
    sort(ALL(pp));
    pp.resize(unique(ALL(pp))-pp.begin());
    REP(i,n)RI(a[i]);
    REP(i,m){
        RI(b[i]);
        if(i)b[0]=__gcd(b[0],b[i]);
    }
    b[0]=__gcd(b[0],p-1);
    int root=2;
    while(!is_root(root))root++;
    int mm=(int)sqrt(p),now=1;
    if(p>=1000000)mm=1000000;
    for(int i=0;i<=mm;i++){
        H.PB(MP(now,i));
        if(i<mm)now=(long long)now*root%p;
    }
    sort(ALL(H));
    now=mypow(now,p-2,p);
    REP(i,n){
        int gg;
        int idx=lower_bound(ALL(H),MP(a[i],0))-H.begin();
        if(a[i]==1){
            gg=p-1;
        }
        else if(H[idx].F==a[i]){
            if(a[i]!=1)gg=__gcd((long long)H[idx].S*b[0],(long long)p-1);
        }
        else{
            int ha=a[i];
            for(int k=1;;k++){
                ha=(long long)ha*now%p;
                idx=lower_bound(ALL(H),MP(ha,0))-H.begin();
                if(H[idx].F==ha){
                    gg=__gcd((long long)p-1,(long long)(H[idx].S+k*mm)*b[0]);
                    break;
                }
            }
        }
        REP(j,SZ(pp)){
            if(pp[j]%gg==0)used[j]=1;
        }
    }
    int an=0;
    for(int i=SZ(pp)-1;i>=0;i--){
        v[i]=(p-1)/pp[i];
        REPP(j,i+1,SZ(pp)){
            if(pp[j]%pp[i]==0)v[i]-=v[j];
        }
        if(used[i])an+=v[i];
    }
    printf("%d\n",an);
    return 0;
}