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
const int MAX = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE],b[SIZE],t[SIZE],c[SIZE],day[SIZE];
int n,m,k,s;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
bool mii(T& x,T y){
    if(x>y){
        x=y;
        return 1;
    }
    return 0;
}
VPLL res;
int a_id,b_id;
bool suc(int mm){
        LL x=MAX,y=MAX;
        REP(i,mm){
            if(mii(x,(LL)a[i]))a_id=i+1;
            if(mii(y,(LL)b[i]))b_id=i+1;
        }
        VPLL pp;
        REP(i,m){
            pp.PB(MP(t[i]==1?(x*c[i]):(c[i]*y),i+1));
            day[i]=t[i]-1;
        }
        sort(ALL(pp));
        LL now=0;
        REP(i,k){
            now+=pp[i].F;
        }
        if(now>s)return 0;
        res=pp;
        return 1;
}
int main(){
    RII(n,m);
    RII(k,s);
    REP(i,n)RI(a[i]);
    REP(i,n)RI(b[i]);
    REP(i,m){
        RII(t[i],c[i]);
    }
    int ll=1,rr=n+1;
    while(ll<rr){
        int mm=(ll+rr)>>1;
        if(suc(mm))rr=mm;
        else ll=mm+1;
    }
    if(ll==n+1)return 0*puts("-1");
    else{
        suc(ll);
        printf("%d\n",ll);
        REP(i,k){
            int id=res[i].S;
            printf("%d ",id);
            id--;
            printf("%d\n",day[id]?b_id:a_id);
        }
    }
    return 0;
}