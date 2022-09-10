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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[750];
VPLL q;
int an[SIZE],n,m;
void f(int id_L,int id_R,int v_L,int v_R){
    if(id_L>id_R)return;
    if(v_L==v_R){
        REPP(i,id_L,id_R+1)an[q[i].S]=v_L;
        return;
    }
    int mm=(id_L+id_R)/2;
    LL now=q[mm].F;
    priority_queue<int>heap;
    int res=0;
    REP(i,n){
        now+=a[i];
        if(a[i]<0)heap.push(-a[i]);
        if(now<0){
            now+=heap.top();
            heap.pop();
            res++;
        }
    }
    an[q[mm].S]=res;
    f(id_L,mm-1,res,v_R);
    f(mm+1,id_R,v_L,res);
}
int main(){
    RII(n,m);
    REP(i,n)RI(a[i]);
    REP(i,m){
        LL x;
        scanf("%I64d",&x);
        q.PB(MP(x,i));
    }
    sort(ALL(q));
    f(0,m-1,0,n);
    REP(i,m)printf("%d\n",an[i]);
    return 0;
}