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
const int MOD = 1e9;
const int SIZE = 1e6+10;
const int MATRIX_SIZE = 2;
struct Matrix_Power{
    LL AA[60][MATRIX_SIZE][MATRIX_SIZE],aa[62][MATRIX_SIZE];
    int N;
    void set(LL _A[][MATRIX_SIZE],int _N,LL bb = (LL)1e18){
        N=_N;
        REP(i,N)
            REP(j,N)AA[0][i][j]=_A[i][j];
        REPP(round,1,60){
            if((1LL<<round)>bb)break;
            REP(i,N)REP(j,N)AA[round][i][j]=0;
            REP(i,N)REP(j,N)REP(k,N){
                AA[round][i][k]+=AA[round-1][i][j]*AA[round-1][j][k];
                AA[round][i][k]%=MOD;
            }
        }
    }
    LL get(LL _a[],LL v){
        MS0(aa);
        REP(i,N)aa[0][i]=_a[i];
        REP(i,61){
            if((1LL<<i)>v)return aa[i][N-1];
            if((v>>i)&1){
                REP(j,N)REP(k,N){
                    aa[i+1][j]+=AA[i][j][k]*aa[i][k];
                    aa[i+1][j]%=MOD;
                }
            }
            else REP(j,N)aa[i+1][j]=aa[i][j];
        }
        return -1;
    }
}Mat;
LL A[2][MATRIX_SIZE];
LL aa[SIZE];
LL fib[2][SIZE];
LL a[SIZE];
void ADD(LL &x,LL v){x=(x+v)%MOD;}
struct SegTree{
    int lv;
    int num[SIZE];
    LL sum[SIZE],p[SIZE],fib_sum[SIZE];
    int ll,rr,N;
    LL v;
    void push(int id,int st){
        if(!p[id])return;
        ADD(sum[id],fib_sum[id]*p[id]);
        if(num[id]!=1){
            ADD(p[id*2],p[id]);
            ADD(p[id*2+1],p[id]);
        }
        p[id]=0;
    }
    void __init(int L,int R,int id){
        p[id]=0;
        if(L==R){
            num[id]=1;
            sum[id]=a[L]*fib[lv][L]%MOD;
            fib_sum[id]=fib[lv][L];
            return;
        }
        int mm=(L+R)>>1;
        __init(L,mm,id*2);
        __init(mm+1,R,id*2+1);
        sum[id]=(sum[id*2]+sum[id*2+1])%MOD;
        num[id]=num[id*2]+num[id*2+1];
        fib_sum[id]=(fib_sum[id*2]+fib_sum[id*2+1])%MOD;
    }
    void init(int _N,int _lv){
        lv=_lv;
        N=_N;
        __init(0,N,1);
    }
    void __upd(int L,int R,int id){
        push(id,L);
        if(L>rr||R<ll)return;
        if(L>=ll&&R<=rr){
            p[id]=v;
            push(id,L);
            return;
        }
        int mm=(L+R)>>1;
        __upd(L,mm,id*2);
        __upd(mm+1,R,id*2+1);
        sum[id]=(sum[id*2]+sum[id*2+1])%MOD;
    }
    void upd(int _x,int _y,int _v){
        ll=_x;rr=_y,v=_v;
        __upd(0,N,1);
    }
    void __upd2(int L,int R,int id){
        push(id,L);
        if(L==R){
            sum[id]=v*fib[lv][L]%MOD;
            return;
        }
        int mm=(L+R)>>1;
        if(ll<=mm)__upd2(L,mm,id*2);
        else  __upd2(mm+1,R,id*2+1);
        sum[id]=(sum[id*2]+sum[id*2+1])%MOD;
    }
    void upd2(int _x,int _v){
        ll=_x;v=_v;
        __upd2(0,N,1);
    }
    LL __qq(int L,int R,int id){
        if(L>rr||R<ll)return 0;
        push(id,L);
        if(L>=ll&&R<=rr)
            return sum[id];
        int mm=(L+R)>>1;
        return (__qq(L,mm,id*2)+__qq(mm+1,R,id*2+1))%MOD;
    }
    LL qq(int _x,int _y){
        ll=_x;rr=_y;
        return __qq(0,N,1);
    }
}seg[2];
int main(){
    A[0][1]=1;
    A[1][0]=1;
    A[1][1]=MOD-1;
    Mat.set(A,2,1e7);
    DRII(N,Q);
    fib[0][1]=fib[1][0]=fib[1][1]=1;
    REPP(i,2,N+1){
        REP(j,2)fib[j][i]=(fib[j][i-2]+fib[j][i-1])%MOD;
    }
    REPP(i,1,N+1)
        scanf("%I64d",&a[i]);
    REP(i,2)seg[i].init(N,i);
    while(Q--){
        DRI(ty);
        if(ty==1){
            DRII(x,v);
            REP(i,2)
                seg[i].upd2(x,v);
        }
        else if(ty==2){
            DRII(x,y);
            aa[1]=seg[0].qq(x,y);
            aa[0]=seg[1].qq(x,y);
            printf("%I64d\n",Mat.get(aa,x-1));
        }
        else{
            DRIII(x,y,v);
            REP(i,2)
                seg[i].upd(x,y,v);
        }
    }
    return 0;
}