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
const int SIZE = 1e5+5;
int x[SIZE],y[SIZE];
LL go(int a[],int b[],int n,int m){
    int ma=-1;
    int id=0;
    REP(i,n){
        if(a[i]>ma){
            ma=a[i];
            id=i;
        }
    }
    LL sum=0;
    REP(i,m){
        sum+=b[i];
    }
    LL res=sum;
    REP(i,n){
        if(i==id)continue;
        res+=min((LL)a[i],sum);
    }
    return res;
}
int main(){
    DRII(n,m);
    REP(i,n)RI(x[i]);
    REP(i,m)RI(y[i]);
    LL an=min(go(x,y,n,m),go(y,x,m,n));
    cout<<an<<endl;
    return 0;
}