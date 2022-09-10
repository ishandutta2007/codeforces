#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
// template end here


long long mul(long long a,long long b,long long m){
    if(a<=9000000000000000000LL/b)return a*b%m;
    long long i,res=0;
    for(i=1;i<=b;i*=2,(a*=2)%=m)
        if(b&i)(res+=a)%=m;
    return res;
}
long long pow(long long n,long long k,long long m){
    if(k==0)return 1;
    if(k%2==1)
        return mul(n,pow(n,k-1,m),m);
    n=pow(n,k/2,m);
    return mul(n,n,m);
}
bool witness(long long a,long long n){
    long long x,y,u,t;
    for(u=n-1,t=0;u%2==0;u/=2,t++);
    x=pow(a,u,n);
    while(t--){
        y=x;
        x=pow(x,2,n);
        if(x==1 && y!=1 && y!=n-1)
            return 1;
    }
    return x!=1;
}
bool mr(long long n,int s=25){
    if(n-1>=2 && witness(2,n))return 0;
    if(n-1>=3 && witness(3,n))return 0;
    if(n-1>=5 && witness(5,n))return 0;
    if(n-1>=179 && witness(179,n))return 0;
    if(n-1>=9137 && witness(9137,n))return 0;
    if(n-1>=28087 && witness(28087,n))return 0;
    return 1;
}
bitset<1000000>p;
PLL pp[200000],ker[200000];
int pn,kn;
int main(){
    LL A;
    cin>>A;
    for(int i=2;i<1000000;i++){
        if(!p[i]){
            for(LL j=(LL)i*i;j<1000000;j+=i)p[j]=1;
            LL now=i;
            while(now<1000000000000LL){
                pp[pn++]=MP(now,i);
                now*=i;
            }
        }
    }
    sort(pp,pp+pn);
    for(LL i=1;i*i<=A;i++){
        if(A%i==0){
            if(i!=1){
                int it=lower_bound(pp,pp+pn,MP(i-1LL,0LL))-pp;
                if(pp[it].F+1==i)ker[kn++]=MP(pp[it].S,i);
            }
            if(A/i!=i){
                int it=lower_bound(pp,pp+pn,MP(A/i-1LL,0LL))-pp;
                if(pp[it].F+1==A/i)ker[kn++]=MP(pp[it].S,A/i);
                else{
                    if(A/i>1000000){
                        if(mr(A/i-1)){
                            ker[kn++]=MP(A/i-1,A/i);
                        }
                    }
                }
            }
        }
    }
    sort(ker,ker+kn);
    map<LL,LL> dp[2];
    int lv=0;
    dp[lv][1LL]=1;
    for(int i=0,j;i<kn;i=j){
        dp[lv^1].clear();
        for(map<LL,LL>::iterator it=dp[lv].begin();it!=dp[lv].end();it++){
            dp[lv^1][it->F]+=it->S;
            for(j=i;j<kn&&ker[j].F==ker[i].F;j++){
                if((A/it->F)%ker[j].S)continue;
                dp[lv^1][it->F*ker[j].S]+=it->S;
            }
        }
        lv^=1;
    }
    LL an=0;
    for(map<LL,LL>::iterator it=dp[lv].begin();it!=dp[lv].end();it++){
        if(it->F==A)an+=it->S;
    }
    cout<<an<<endl;
    return 0;
}