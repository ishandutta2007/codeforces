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
int n,a[SIZE],b[SIZE];
bool used[SIZE];
void solve(){
    RI(n);
    LL sumA=0,sumB=0;
    REP(i,n){
        RI(a[i]);
        sumA+=a[i];
    }
    REP(i,n){
        RI(b[i]);
        sumB+=b[i];
    }
    long double da=0,db=0,one=1;
    vector<pair<long double,int> >aa;
    REP(i,n){
        aa.PB(MP(a[i]*one/sumA+b[i]*one/sumB,i));
    }
    sort(ALL(aa));
    reverse(ALL(aa));
    int rr=0,rr2=0,num=0;
    REP(i,n){
        int id=aa[i].S;
        if(used[id])continue;
        num++;
        used[id]=1;
        da+=a[id]*one/sumA;
        db+=b[id]*one/sumB;
        if(num*2>n)return;
        while(1){
            bool fail=0;
            if(da<num*one/n){
                fail=1;
                int you=aa[rr].S;
                if(used[you]){
                    rr++;
                    continue;
                }
                if(a[you]*(LL)n>=sumA){
                    used[you]=1;
                    da+=a[you]*one/sumA;
                    db+=b[you]*one/sumB;
                    num++;
                    if(num*2>n)return;
                }
                rr++;
            }
            if(db<num*one/n){
                fail=1;
                int you=aa[rr2].S;
                if(used[you]){
                    rr2++;
                    continue;
                }
                if(b[you]*(LL)n>=sumB){
                    used[you]=1;
                    da+=a[you]*one/sumA;
                    db+=b[you]*one/sumB;
                    num++;
                    if(num*2>n)return;
                }
                rr2++;
            }
            if(!fail)break;
        }
    }
}
int main(){
    solve();
    printf("%d\n",n/2+1);
    REP(i,n){
        if(used[i])printf("%d ",i+1);
    }
    return 0;
}