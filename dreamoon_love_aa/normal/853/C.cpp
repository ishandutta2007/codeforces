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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int INF = 1e9+7;
const int SIZE = 2e5+10;
int BIT[SIZE],n,q;
LL an[SIZE];
VPII pp;
void ins(int x){
    for(;x<SIZE;x+=x&-x)BIT[x]++;
}
LL qq(int x){
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res*(res-1LL)/2;
}
VPII rec[SIZE];
int dn;
struct data{
    int x,y,id;
    data(int _x=0,int _y=0,int _id=-1):x(_x),y(_y),id(_id){}
    bool operator<(const data& b)const{
        return x<b.x||(x==b.x&&y<b.y)||(x==b.x&&y==b.y&&id<b.id);
    }
}d[SIZE*5];
void solve(){
    MS0(BIT);
    dn=0;
    REP(i,SZ(pp)){
        d[dn++]=data(pp[i].F,pp[i].S,-INF);
    }
    REP(i,q){
        d[dn++]=data(rec[i][0].F-1,rec[i][0].S-1,i+1);
        d[dn++]=data(n,rec[i][0].S-1,-(i+1));
    }
    sort(d,d+dn);
    REP(i,dn){
        if(d[i].id==-INF){
            ins(d[i].y);
        }
        else{
            if(d[i].id<0){
                an[-d[i].id-1]-=qq(d[i].y);
            }
            else{
                an[d[i].id-1]+=qq(d[i].y);
            }
        }
    }
}
void rotate(PII& X){
    X=MP(n+1-X.S,X.F);
}
int main(){
    RII(n,q);
    REPP(i,1,n+1){
        DRI(x);
        pp.PB(MP(x,i));
    }
    REP(i,q){
        DRII(l,d);
        DRII(r,u);
        rec[i].PB(MP(d,l));
        rec[i].PB(MP(d,r));
        rec[i].PB(MP(u,l));
        rec[i].PB(MP(u,r));
    }
    LL all=n*(n-1LL)/2;
    REP(i,4){
        REP(j,SZ(pp))rotate(pp[j]);
        REP(j,q){
            REP(k,4)rotate(rec[j][k]);
            sort(ALL(rec[j]));
        }
        solve();
    }
    REP(i,q)printf("%I64d\n",an[i]+all);
    return 0;
}