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
const int SIZE = 1001;
LL row[SIZE],col[SIZE],V[2][1000010];
int K,P;
void get(LL v[],LL rc[],int n,int m){
    priority_queue<LL>heap;
    REP(i,n)heap.push(rc[i]);
    LL now=0;
    v[0]=0;
    REP(i,K){
        LL me=heap.top();
        heap.pop();
        now+=me;
        v[i+1]=v[i]+me;
        heap.push(me-P*m);
    }
}
int main(){
    DRII(n,m);
    RII(K,P);
    REP(i,n)REP(j,m){
        DRI(x);
        row[i]+=x;
        col[j]+=x;
    }
    get(V[0],row,n,m);
    get(V[1],col,m,n);
    LL res=-1e18;
    REP(i,K+1){
        res=max(res,V[0][i]+V[1][K-i]-(LL)P*i*(K-i));
    }
    cout<<res<<endl;
    return 0;
}