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
int a[SIZE];
int inc[SIZE];
int decc[SIZE];
int BIT[SIZE];
void ins(int x,int v){
    for(;x<SIZE;x+=x&-x)BIT[x]=max(BIT[x],v);
}
int qq(int x){
    int res=0;
    for(;x;x-=x&-x)res=max(BIT[x],res);
    return res;
}
int used[SIZE],tt;
int tag[SIZE][2],ker[SIZE];
int main(){
    DRI(n);
    REP(i,n)RI(a[i]);
    tt++;
    int ma=0;
    REP(i,n){
        inc[i]=qq(a[i]-1)+1;
        if(used[inc[i]]!=tt){
            used[inc[i]]=tt;
            tag[i][0]=inc[i];
        }
        ma=max(ma,inc[i]);
        ins(a[i],inc[i]);
    }
    MS0(BIT);
    tt++;
    for(int i=n-1;i>=0;i--){
        decc[i]=qq(SIZE-a[i]-1)+1;
        if(used[decc[i]]!=tt){
            used[decc[i]]=tt;
            tag[i][1]=decc[i];
        }
        ins(SIZE-a[i],decc[i]);
    }
    map<int,int>H;
    REP(i,n){
        if(inc[i]+decc[i]==ma+1){
            ker[i]=1;
            H[inc[i]]++;
        }
    }
    REP(i,n){
        if(inc[i]+decc[i]!=ma+1)putchar('1');
        else if(H[inc[i]]==1)putchar('3');
        else putchar('2');
    }
    return 0;
}