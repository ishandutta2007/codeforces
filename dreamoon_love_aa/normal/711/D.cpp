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
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE],p[SIZE],vi[SIZE],t2;
bool u[SIZE];
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
int main(){
    LL an=1;
    DRI(n);
    REP(i,n)an=an*2%MOD;
    REP(i,n)RI(a[i+1]);
    REPP(i,1,n+1){
        if(!u[i]){
            t2++;
            int x=i,id;
            p[x]=id=1;
            u[x]=1;
            vi[x]=t2;
            while(!p[a[x]]){
                x=a[x];
                vi[x]=t2;
                u[x]=1;
                p[x]=++id;
            }
            if(vi[a[x]]==t2){
                int tt=id+1-p[a[x]];
                int two=1;
                REP(j,tt)two=two*2%MOD;
                an=(an*(two-2)%MOD)*mypow(two,MOD-2)%MOD;
            }
        }
    }
    cout<<an<<endl;
    return 0;
}