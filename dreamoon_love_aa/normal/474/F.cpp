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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
const int INF = 2e9;
int gg[SIZE<<2],mi[SIZE<<2],num[SIZE<<2],a[SIZE],r1,r2;
void fresh(int x,int y){
    if(x<r1){
        r1=x;
        r2=y;
    }
    else if(x==r1){
        r2+=y;
    }
}
void build(int L,int R,int id){
    if(L==R){
        mi[id]=a[L];
        num[id]=1;
        gg[id]=a[L];
        return;
    }
    int mm=(L+R)>>1;
    build(L,mm,id*2);
    build(mm+1,R,id*2+1);
    gg[id]=__gcd(gg[id*2],gg[id*2+1]);
    if(mi[id*2]==mi[id*2+1]){
        mi[id]=mi[id*2];
        num[id]=num[id*2+1]+num[id*2];
    }
    else if(mi[id*2]<mi[id*2+1]){
        mi[id]=mi[id*2];
        num[id]=num[id*2];
    }
    else{
        mi[id]=mi[id*2+1];
        num[id]=num[id*2+1];
    }
}
int qq(int L,int R,int id,int ll,int rr){
    if(L>=ll&&R<=rr){
        fresh(mi[id],num[id]);
        return gg[id];
    }
    int mm=(L+R)>>1;
    if(mm>=rr)return qq(L,mm,id*2,ll,rr);
    if(mm+1<=ll)return qq(mm+1,R,id*2+1,ll,rr);
    return __gcd(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
}
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i]);
    }
    build(0,n-1,1);
    DRI(Q);
    while(Q--){
        DRII(x,y);
        x--;y--;
        r1=INF;
        r2=0;
        int me=qq(0,n-1,1,x,y);
        //printf("me:%d\n",me);
        if(r1==me)printf("%d\n",y-x+1-r2);
        else printf("%d\n",y-x+1);
    }
    return 0;
}