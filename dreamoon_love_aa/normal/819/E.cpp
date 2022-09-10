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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
VI d[SIZE];
int dn;
void add(int x,int y,int z){
    d[dn].PB(x);
    d[dn].PB(y);
    d[dn++].PB(z);
}
void add(int x,int y,int z,int w){
    d[dn].PB(x);
    d[dn].PB(y);
    d[dn].PB(z);
    d[dn++].PB(w);
}
void go(int n){
    if(n==3){
        add(1,2,3);
        add(1,2,3);
        return;
    }
    if(n==4){
        add(1,2,3);
        add(2,3,4);
        add(1,2,4);
        add(1,3,4);
        return;
    }
    if(n==5){
        add(5, 4, 2);
        add(3, 1, 5);
        add(4, 5, 2, 3);
        add(4, 3, 2, 1);
        add(4, 2, 1);
        add(3, 1, 5);
        return;
    }
    int nxt_n=n-3;
    if(nxt_n%2==0){
        for(int i=1;i<nxt_n;i+=2){
            int u=i,v=i+1;
            add(n,u,n-1,v);
            add(n-1,u,n-2,v);
            add(n-2,u,n,v);
        }
        add(n-2,n-1,n);
        add(n-2,n-1,n);
    }
    else{
        add(n,n-1,1);
        add(n-1,n-2,1);
        add(n-2,n,1);
        add(n,n-1,n-2);
        for(int i=2;i<nxt_n;i+=2){
            int u=i,v=i+1;
            add(n,u,n-1,v);
            add(n-1,u,n-2,v);
            add(n-2,u,n,v);
        }
    }
    go(nxt_n);

}
int main(){
    DRI(n);
    go(n);
    printf("%d\n",dn);
    REP(i,dn){
        printf("%d",SZ(d[i]));
        REP(j,SZ(d[i])){
            printf(" %d",d[i][j]);
        }
        puts("");
    }
    return 0;
}