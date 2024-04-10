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
const int SIZE = 262144;
// template end here
int a[SIZE],b[SIZE],M;
bool p[1111];
bitset<1000> pp,emp;
void ADD(int &x,LL v){
    x=(x+v)%M;
}
struct SegTree{
    int num[SIZE],shi[SIZE];
    bitset<1000>v[SIZE];
    int ll,rr,N;
    int u;
    void push(int id){
        if(!shi[id])return;
        v[id]=(v[id]<<shi[id])|(v[id]>>(M-shi[id]));
        if(num[id]!=1){
            ADD(shi[id*2],shi[id]);
            ADD(shi[id*2+1],shi[id]);
        }
        shi[id]=0;
    }
    void __init(int L,int R,int id){
        shi[id]=0;
        if(L==R){
            num[id]=1;
            v[id].reset();
            v[id][a[L]]=1;
            return;
        }
        int mm=(L+R)>>1;
        __init(L,mm,id*2);
        __init(mm+1,R,id*2+1);
        v[id]=v[id*2]|v[id*2+1];
        num[id]=num[id*2]+num[id*2+1];
    }
    void init(int _N){
        N=_N;
        __init(1,N,1);
    }
    void __add(int L,int R,int id){
        push(id);
        if(L>rr||R<ll)return;
        if(L>=ll&&R<=rr){
            ADD(shi[id],u);
            push(id);
            return;
        }
        int mm=(L+R)>>1;
        __add(L,mm,id*2);
        __add(mm+1,R,id*2+1);
        v[id]=v[id*2]|v[id*2+1];
    }
    void add(int _x,int _y,int _u){
        ll=_x;rr=_y;u=_u;
        __add(1,N,1);
    }
    bitset<1000> __qq(int L,int R,int id){
        if(L>rr||R<ll)return emp;
        push(id);
        if(L>=ll&&R<=rr)
            return v[id];
        int mm=(L+R)>>1;
        return __qq(L,mm,id*2)|__qq(mm+1,R,id*2+1);
    }
    bitset<1000> qq(int _x,int _y){
        ll=_x;rr=_y;
        return (pp&__qq(1,N,1)).count();
    }
}seg;
VI e[SIZE];
int ID[SIZE],Lside[SIZE],Rside[SIZE],tmpV;
bool used[SIZE];
void dfs(int x){
    used[x]=1;
    a[++tmpV]=b[x];
    Lside[x]=Rside[x]=tmpV;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y])continue;
        dfs(y);
        Rside[x]=Rside[y];
    }
}
void pre(){
    REPP(i,2,M)pp[i]=1;
    REPP(i,2,M)
        for(int j=i+i;j<M;j+=i)pp[j]=0;
}
int main(){
    DRI(N);
    RI(M);
    pre();
    REPP(i,1,N+1){
        RI(b[i]);
        b[i]%=M;
    }
    REPP(i,1,N){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1);
    seg.init(N);
    DRI(Q);
    while(Q--){
        DRI(ty);
        if(ty==1){
            DRII(x,v);
            v%=M;
            if(v==0)continue;
            seg.add(Lside[x],Rside[x],v);
        }
        else if(ty==2){
            DRI(x);
            int res=0;
            printf("%d\n",seg.qq(Lside[x],Rside[x]));
        }
    }
    return 0;
}