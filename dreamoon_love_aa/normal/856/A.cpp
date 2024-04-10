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
const int SIZE = 1e6+1;
int shik[3*SIZE],tt,a[SIZE];
int main(){
    CASET{
        DRI(n);
        REP(i,n)RI(a[i]);
        sort(a,a+n);
        bool same=0;
        REPP(i,1,n){
            if(a[i]==a[i-1])same=1;
        }
        if(same){
            puts("NO");
            continue;
        }
        VI d;
        REPP(j,1,n)REP(i,j){
            d.PB(a[j]-a[i]);
        }
        sort(ALL(d));
        d.resize(unique(ALL(d))-d.begin());
        tt++;
        int r=n;
        VI res;
        REPP(now,1,SIZE){
            if(shik[now]!=tt){
                r--;
                res.PB(now);
                REP(i,SZ(d)){
                    shik[now+d[i]]=tt;
                }
                if(r==0)break;
            }
        }
        puts("YES");
        REP(i,SZ(res))printf("%d%c",res[i]," \n"[i==SZ(res)-1]);
    }
    return 0;
}