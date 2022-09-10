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
const int SIZE = 4e5+10;
// template end here
int a[SIZE],b[SIZE];
void ADD(int &x,LL v){
    x=(x+v)%MOD;
}
struct SegTree{
    int lv;
    LL num[SIZE],mi[SIZE],ma[SIZE],pv[SIZE];
    int ll,rr,v,N;
    void push(int id){
        if(!pv[id])return;
        mi[id]+=pv[id];
        ma[id]+=pv[id];
        if(num[id]!=1){
            pv[id*2]+=pv[id];
            pv[id*2+1]+=pv[id];

        }
        pv[id]=0;
    }
    void __init(int L,int R,int id){
        pv[id]=0;
        if(L==R){
            num[id]=1;
            mi[id]=ma[id]=0;
            return;
        }
        int mm=(L+R)>>1;
        __init(L,mm,id*2);
        __init(mm+1,R,id*2+1);
        mi[id]=min(mi[id*2],mi[id*2+1]);
        ma[id]=min(ma[id*2],ma[id*2+1]);
        num[id]=num[id*2]+num[id*2+1];
    }
    void init(int _N){
        N=_N;
        __init(0,N,1);
    }
    void __ins(int L,int R,int id){
        push(id);
        if(L>rr||R<ll)return;
        if(L>=ll&&R<=rr){
            pv[id]+=v;
            push(id);
            return;
        }
        int mm=(L+R)>>1;
        __ins(L,mm,id*2);
        __ins(mm+1,R,id*2+1);
        mi[id]=min(mi[id*2],mi[id*2+1]);
        ma[id]=min(ma[id*2],ma[id*2+1]);
    }
    void ins(int _x,int _y,int _v){
        ll=_x;rr=_y;v=_v;
        __ins(0,N,1);
    }
    LL __qq(int L,int R,int id){
        push(id);
        if(mi[id]>v)return -1;
        if(L==R)return L;
        int mm=(L+R)>>1;
        push(id*2+1);
        if(mi[id*2+1]<=v)return __qq(mm+1,R,id*2+1);
        return __qq(L,mm,id*2);
    }
    int qq(int _v){
        v=_v;
        return __qq(0,N,1);
    }
}seg;
int p[SIZE];
int main(){
    DRI(N);
    seg.init(N);
    int now=0;
    REP(i,N){
        DRII(x,ty);
        if(ty==1){
            DRI(v);
            p[x-1]=v;
            seg.ins(x,N,1);
            now++;
        }
        else{
            seg.ins(x,N,-1);
            now--;
        }
        int id=seg.qq(now-1);
        if(id==-1)puts("-1");
        else printf("%d\n",p[id]);
    }
    return 0;
}