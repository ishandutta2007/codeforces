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
const int SIZE = 1e5+10;
int from[SIZE],a[SIZE],b[SIZE];
int cnt[1<<21];
LL an[SIZE];
struct data{
    int x,y,id;
    bool operator<(const data& b)const{
        return from[x]<from[b.x]||(from[x]==from[b.x]&&y<b.y);
    }
}qq[SIZE];
int main(){
    DRIII(N,M,K);
    int sqN=sqrt(N+0.1);
    REP(i,N){
        RI(a[i+1]);
        a[i+1]^=a[i];
    }
    N++;
    REP(i,N){
        from[i]=i/sqN;
    }
    REP(i,M){
        RII(qq[i].x,qq[i].y);
        qq[i].x--;
        qq[i].id=i;
    }
    sort(qq,qq+M);
    int lt=-1;
    int ll=0,rr=-1;
    LL v=0;
    REP(i,M){
        while(rr<qq[i].y){
            rr++;
            v+=cnt[a[rr]^K];
            cnt[a[rr]]++;
        }
        while(rr>qq[i].y){
            cnt[a[rr]]--;
            v-=cnt[a[rr]^K];
            rr--;
        }
        while(ll>qq[i].x){
            ll--;
            v+=cnt[a[ll]^K];
            cnt[a[ll]]++;
        }
        while(ll<qq[i].x){
            cnt[a[ll]]--;
            v-=cnt[a[ll]^K];
            ll++;
        }
        an[qq[i].id]=v;
    }
    REP(i,M)printf("%I64d\n",an[i]);
    return 0;
}