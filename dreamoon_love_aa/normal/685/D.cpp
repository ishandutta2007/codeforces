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
const int INF = 1e9+7000;
const int SIZE = 2e5+10;
PII p[SIZE];
int y[SIZE],ynn;
int d[30000000],dn,num[30000000];
LL an[SIZE];
struct data{
    int x,y,v;
    data(int _x=0,int _y=0,int _v=0):x(_x),y(_y),v(_v){}
    bool operator<(const data& b)const{return x<b.x;}
}a[SIZE];
int main(){
    DRII(N,K);
    REP(i,N){RII(p[i].F,p[i].S);y[i]=p[i].S;}
    sort(y,y+N);
    y[N]=INF;
    REP(i,N){
        for(int j=y[i];j<y[i+1]&&j-y[i]<K;j++)d[dn++]=j;
    }
    REP(i,N)
        p[i].S=lower_bound(d,d+dn,p[i].S)-d;
    int dec=0;
    REP(i,N){
        a[i]=data(p[i].F,p[i].S,1);
        a[i+N]=data(p[i].F+K,p[i].S,-1);
    }
    N+=N;
    sort(a,a+N);
    REP(i,N){
        for(int v=a[i].y;v<a[i].y+K;v++){
            an[num[v]]+=(a[i].x-d[v]);
            d[v]=a[i].x;
            num[v]+=a[i].v;
        }
    }
    N>>=1;
    REP(i,N)printf("%I64d ",an[i+1]);
    return 0;
}