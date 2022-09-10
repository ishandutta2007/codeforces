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
PII a[SIZE];
int used[SIZE],tt,b[SIZE],c[SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int an[SIZE];
int n,m,s;
vector<pair<PII,int> >ppp;
bool solve(int mm){
    int id=SZ(ppp)-1,need=0;
    priority_queue<PII,vector<PII>,greater<PII> >hq;
    for(int i=m-1;i>=0;i-=mm){
        while(id>=0&&ppp[id].F.F>=a[i].F){
            hq.push(MP(ppp[id].F.S,ppp[id].S));
            id--;
        }
        if(hq.empty())return 0;
        need+=hq.top().F;
        if(need>s)return 0;
        REP(j,mm){
            an[a[i-j].S]=hq.top().S;
            if(i-j==0)break;
        }
        hq.pop();
    }
    return 1;
}
int main(){
    RIII(n,m,s);
    int ma_a=0,ma_b=0;
    REP(i,m){
        RI(a[i].F);
        maa(ma_a,a[i].F);
        a[i].S=i+1;
    }
    REP(i,n)RI(b[i]);
    REP(i,n){
        RI(c[i]);
        if(c[i]<=s)maa(ma_b,b[i]);
    }
    if(ma_a>ma_b)return 0*puts("NO");
    REP(i,n){
        ppp.PB(MP(MP(b[i],c[i]),i+1));
    }
    sort(ALL(ppp));
    sort(a,a+m);
    puts("YES");
    int ll=1,rr=m;
    while(ll<rr){
        int mm=(ll+rr)>>1;
        if(solve(mm))rr=mm;
        else ll=mm+1;
    }
    solve(ll);
    REPP(i,1,m+1)printf("%d ",an[i]);
    return 0;
}