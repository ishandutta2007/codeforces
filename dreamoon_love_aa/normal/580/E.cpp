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
typedef unsigned long long UL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
// template end here
UL d[4][1570];
UL suffix[64],prefix[64];
char s[SIZE];
UL all_bit;
inline UL left_move(UL x,int v){
    if(v>=64)return 0;
    return x<<v;
}
inline void set_bit(UL a[],int L,int R,int v){
    int Lx=L>>6,Ly=L&63;
    int Rx=R>>6,Ry=R&63;
    if(Lx==Rx){
        a[Lx]|=suffix[Ly]&prefix[Ry];
        if(!v)a[Lx]^=suffix[Ly]&prefix[Ry];
        return;
    }
    a[Lx]|=suffix[Ly];
    if(!v)a[Lx]^=suffix[Ly];
    a[Rx]|=prefix[Ry];
    if(!v)a[Rx]^=prefix[Ry];
    if(v)
        memset(a+Lx+1,-1,sizeof(UL)*(Rx-Lx-1));
    else
        memset(a+Lx+1,0,sizeof(UL)*(Rx-Lx-1));
}
inline bool compare(UL a[],int A,int B,int m){
    int Ax=A>>6,Ay=A&63;
    int Bx=B>>6,By=B&63;
    if(!Ay&&!By){
        for(;m>64;m-=64,Ax++,Bx++)
            if(a[Ax]!=a[Bx])return 0;
        return (a[Ax]&prefix[m-1])==(a[Bx]&prefix[m-1]);
    }
    if(!Ay){
        for(;m>64;m-=64,Ax++,Bx++)
            if(a[Ax] != ((a[Bx]>>By)|(a[Bx+1]<<(64-By))))return 0;
        return (a[Ax]&prefix[m-1])==(((a[Bx]>>By)|(a[Bx+1]<<(64-By)))&prefix[m-1]);
    }
    if(!By){
        for(;m>64;m-=64,Ax++,Bx++)
            if(a[Bx] != ((a[Ax]>>Ay)|(a[Ax+1]<<(64-Ay))))return 0;
        return (a[Bx]&prefix[m-1])==(((a[Ax]>>Ay)|(a[Ax+1]<<(64-Ay)))&prefix[m-1]);
    }
    for(;m>64;m-=64,Ax++,Bx++)
        if(((a[Ax]>>Ay)|(a[Ax+1]<<(64-Ay))) != ((a[Bx]>>By)|(a[Bx+1]<<(64-By))))return 0;
    return (((a[Bx]>>By)|(a[Bx+1]<<(64-By)))&prefix[m-1])==(((a[Ax]>>Ay)|(a[Ax+1]<<(64-Ay)))&prefix[m-1]);
}
inline bool compare(int A,int B,int m){
    REP(i,4){
        if(!compare(d[i],A,B,m))return 0;
    }
    return 1;
}
int main(){
    REP(i,64){
        all_bit|=(UL)1<<i;
        if(!i)prefix[i]=1;
        else prefix[i]=prefix[i-1]|((UL)1<<i);
    }
    for(int i=63;i>=0;i--){
        if(i==63)suffix[i]=(UL)1<<i;
        else suffix[i]=suffix[i+1]|((UL)1<<i);
    }
    DRIII(n,m,k);
    RS(s);
    REP(i,n){
        REP(j,4){
            if(((s[i]-'0')>>j)&1)set_bit(d[j],i,i,1);
        }
    }
    REP(i,m+k){
        DRI(ty);
        DRIII(x,y,v);
        x--;y--;
        if(ty==1){
            REP(j,4){
                set_bit(d[j],x,y,(v>>j)&1);
            }
        }
        else{
            if(x+v>y)puts("YES");
            else puts(compare(x,x+v,y-x-v+1)?"YES":"NO");
        }
    }
    return 0;
}