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
int d[SIZE];
void ADD(int &x,LL v){
    x=(x+v)%MOD;
}
int a[2][2],A[2][2][2],RES[2];
void cal(int x){
    x--;
    a[0][0]=0;a[0][1]=1;
    A[0][0][0]=0;A[0][0][1]=A[0][1][0]=A[0][1][1]=1;
    int now=0;
    while(x){
        if(x&1){
            REP(i,2)a[now^1][i]=0;
            REP(i,2)
                REP(j,2)
                    ADD(a[1^now][i],A[now][i][j]*(LL)a[now][j]);
        }
        else REP(i,2)a[now^1][i]=a[now][i];
        REP(i,2)REP(j,2)A[now^1][i][j]=0;
        REP(i,2)REP(j,2)REP(k,2){
            ADD(A[now^1][i][k],A[now][i][j]*(LL)A[now][j][k]);
        }
        x>>=1;
        now^=1;
    }
    REP(i,2)RES[i]=a[now][i];
}
int B[2][2][2];
void cal2(int x){
    A[0][0][0]=0;A[0][0][1]=A[0][1][0]=A[0][1][1]=1;
    B[0][0][0]=B[0][1][1]=1;
    B[0][0][1]=B[0][1][0]=0;
    int now=0;
    while(x){
        if(x&1){
            REP(i,2)REP(j,2)B[now^1][i][j]=0;
            REP(i,2)
                REP(j,2)
                    REP(k,2)
                        ADD(B[1^now][i][k],B[now][i][j]*(LL)A[now][j][k]);
        }
        else REP(i,2)REP(j,2)B[now^1][i][j]=B[now][i][j];
        REP(i,2)REP(j,2)A[now^1][i][j]=0;
        REP(i,2)REP(j,2)REP(k,2){
            ADD(A[now^1][i][k],A[now][i][j]*(LL)A[now][j][k]);
        }
        x>>=1;
        now^=1;
    }
    if(now)REP(i,2)REP(j,2)B[0][i][j]=B[1][i][j];
}
struct SegTree{
    int sum[SIZE][2],num[SIZE],pv[SIZE][2][2];
    int ll,rr,N;
    void push(int id){
        if(pv[id][0][0]==1&&pv[id][1][1]==1&&pv[id][0][1]==0&&pv[id][1][0]==0)return;
        {
            int tmp[2]={};
            REP(i,2)REP(j,2){
                ADD(tmp[i],pv[id][i][j]*(LL)sum[id][j]);
            }
            REP(i,2)sum[id][i]=tmp[i];
        }
        if(num[id]!=1){
            int tmp[2][2]={};
            REP(i,2)REP(j,2)REP(k,2)ADD(tmp[i][k],pv[id][i][j]*(LL)pv[id*2][j][k]);
            REP(i,2)REP(j,2)pv[id*2][i][j]=tmp[i][j];
            MS0(tmp);
            REP(i,2)REP(j,2)REP(k,2)ADD(tmp[i][k],pv[id][i][j]*(LL)pv[id*2+1][j][k]);
            REP(i,2)REP(j,2)pv[id*2+1][i][j]=tmp[i][j];
        }
        pv[id][0][0]=pv[id][1][1]=1;
        pv[id][0][1]=pv[id][1][0]=0;
    }
    void __init(int L,int R,int id){
        pv[id][0][0]=pv[id][1][1]=1;
        pv[id][0][1]=pv[id][1][0]=0;
        if(L==R){
            num[id]=1;
            cal(d[L]);
            REP(i,2)sum[id][i]=RES[i];
            return;
        }
        int mm=(L+R)>>1;
        __init(L,mm,id*2);
        __init(mm+1,R,id*2+1);
        REP(i,2)sum[id][i]=0;
        REP(i,2){
            ADD(sum[id][i],sum[id*2][i]);
            ADD(sum[id][i],sum[id*2+1][i]);
        }
    }
    void init(int _N){
        N=_N;
        __init(0,N-1,1);
    }
    void __edit(int L,int R,int id){
        push(id);
        if(L>rr||R<ll)return;
        if(L>=ll&&R<=rr){
            int tmp[2][2]={};
            REP(i,2)REP(j,2)REP(k,2)ADD(tmp[i][k],pv[id][i][j]*(LL)B[0][j][k]);
            REP(i,2)REP(j,2)pv[id][i][j]=tmp[i][j];
            push(id);
            return;
        }
        int mm=(L+R)>>1;
        __edit(L,mm,id*2);
        __edit(mm+1,R,id*2+1);
        REP(i,2){
            sum[id][i]=(sum[id*2][i]+sum[id*2+1][i]);
            if(sum[id][i]>=MOD)sum[id][i]-=MOD;
        }
    }
    void edit(int _x,int _y){
        ll=_x;rr=_y;
        __edit(0,N-1,1);
    }
    int __qq(int L,int R,int id){
        if(L>rr||R<ll)return 0;
        push(id);
        if(L>=ll&&R<=rr)
            return sum[id][1];
        int mm=(L+R)>>1;
        int res=__qq(L,mm,id*2)+__qq(mm+1,R,id*2+1);
        if(res>=MOD)res-=MOD;
        return res;
    }
    int qq(int _x,int _y){
        ll=_x;rr=_y;
        return __qq(0,N-1,1);
    }
}seg;
int main(){
    DRII(N,Q);
    REP(i,N)RI(d[i]);
    seg.init(N);
    while(Q--){
        DRI(ty);
        if(ty==1){
            DRIII(l,r,x);l--;r--;
            cal2(x);
            seg.edit(l,r);
        }
        else if(ty==2){
            DRII(l,r);l--;r--;
            printf("%d\n",seg.qq(l,r));
        }
    }
    return 0;
}