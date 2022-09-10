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
bool ker[SIZE];
int n;
bool valid(int i){
    if(i<=0||i>=n)return 1;
    if(i%2==1){
        if(a[i]>a[i-1])return 1;
    }
    else{
        if(a[i]<a[i-1])return 1;
    }
    return 0;
}
int main(){
    RI(n);
    REP(i,n)RI(a[i]);
    bool err=0;
    int cnt=0;
    VI ee;
    REPP(i,1,n){
        if(!valid(i))ker[i]=1,ker[i-1]=1,cnt++,ee.PB(i),ee.PB(i-1);
    }
    if(cnt>=20)return 0*puts("0");
    sort(ALL(ee));
    ee.resize(unique(ALL(ee))-ee.begin());
    int an=0;
    REP(i,SZ(ee)){
        int x=ee[i];
        REP(j,n){
            if(j==x)continue;
            if(ker[j]&&j>x)continue;
            swap(a[x],a[j]);
            bool fail=0;
            ee.PB(j);
            REP(k,SZ(ee)){
                REPP(r,-2,3){
                    if(!valid(ee[k]+r))fail=1;
                }
            }
            ee.pop_back();
            if(!fail)an++;
            swap(a[x],a[j]);
        }
    }
    cout<<an;
    return 0;
}