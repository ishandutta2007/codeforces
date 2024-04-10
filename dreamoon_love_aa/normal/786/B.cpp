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
const LL INF = 1e18;
priority_queue<pair<LL,PII>,vector<pair<LL,PII> >,greater<pair<LL,PII> > >pq;
struct SegTree{
    VPII e[SIZE];
    int N;
    void init(int _N){N=_N;}
    void insert(int L,int R,int id,int ll,int rr,PII v){
        if(L>rr||R<ll)return;
        if(L>=ll&&R<=rr){
            e[id].PB(v);
            return;
        }
        int mm=(L+R)/2;
        insert(L,mm,id*2,ll,rr,v);
        insert(mm+1,R,id*2+1,ll,rr,v);
    }
    void go(int L,int R,int id,int x,LL v){
        if(SZ(e[id])){
            for(VPII::iterator it=e[id].begin();it!=e[id].end();it++){
                pq.push(MP(v+it->S,MP(it->F,it->F)));
            }
            e[id]=VPII();
        }
        if(L==R)return;
        int mm=(L+R)/2;
        if(x<=mm)go(L,mm,id*2,x,v);
        else go(mm+1,R,id*2+1,x,v);
    }
}seg;
VI e[SIZE];
VPII e_range[SIZE];
LL an[SIZE];
int main(){
    DRIII(n,q,s);
    REP(i,q){
        DRI(ty);
        if(ty==1){
            DRIII(x,y,v);
            e[x].PB(v);
            e_range[x].PB(MP(y,y));
        }
        else if(ty==2){
            DRI(x);
            DRII(l,r);
            DRI(v);
            e[x].PB(v);
            e_range[x].PB(MP(l,r));
        }
        else{
            DRI(y);
            DRII(l,r);
            DRI(v);
            seg.insert(1,n,1,l,r,MP(y,v));
        }
    }
    pq.push(MP(0,MP(s,s)));
    VI RR(n);
    REP(i,n)RR[i]=i+1;
    set<int>R(ALL(RR));
    MS1(an);
    while(!pq.empty()){
        pair<LL,PII>now=pq.top();pq.pop();
        set<int>::iterator it0=R.lower_bound(now.S.F);
        set<int>::iterator it;
        for(it=it0;it!=R.end()&&*it<=now.S.S;it++){
            int me=*it;
            an[me]=now.F;
            REP(i,SZ(e[me])){
                pq.push(MP(now.F+e[me][i],e_range[me][i]));
            }
            seg.go(1,n,1,me,now.F);
        }
        R.erase(it0,it);
    }
    REPP(i,1,n+1)printf("%I64d%c",an[i]," \n"[i==n]);
    return 0;
}