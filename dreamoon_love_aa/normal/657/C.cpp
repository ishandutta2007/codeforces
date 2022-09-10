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
int a[SIZE];
int main(){
    DRII(n,k);
    DRII(b,c);
    b=min(b,c*5);
    REP(i,n)RI(a[i]);
    sort(a,a+n);
    LL an=1e18;
    REP(r,5){
        LL V=-1e9+r;
        priority_queue<LL>pq;
        LL need=0;
        LL add=0;
        REP(i,n){
            int me=a[i];
            LL one=0;
            while((me%5+5)%5!=r){
                me++;
                one++;
            }
            need+=SZ(pq)*(LL)(me-V)/5*b;
            add+=(me-V)/5LL*b;
            pq.push(one*c-add);
            need+=one*c;
            if(SZ(pq)>k){
                need-=pq.top()+add;
                pq.pop();
            }
            if(SZ(pq)==k)an=min(an,need);
            V=me;
        }
    }
    cout<<an;
    return 0;
}