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
typedef long double LD;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL f(LL x,LL y,LL z){
    return min(x,min(y,z));
}
map<PII,int>pH;
set<PII>H[SIZE];
PII r[SIZE];
int id;
int add(PII x){
    if(x.F>x.S)swap(x.F,x.S);
    if(pH.count(x))return pH[x];
    r[id]=x;
    return pH[x]=id++;
}
int main(){
    DRI(n);
    LD ma=0;
    VI an;
    REP(i,n){
        DRIII(x,y,z);
        if(f(x,y,z)>ma){
            ma=f(x,y,z);
            an.clear();
            an.PB(i+1);
        }
        H[add(MP(x,y))].insert(MP(z,i+1));
        H[add(MP(x,z))].insert(MP(y,i+1));
        H[add(MP(y,z))].insert(MP(x,i+1));
    }
    REP(i,id){
        if(SZ(H[i])>1){
            set<PII>::iterator it=H[i].end();it--;
            PII h1=*it;
            it--;
            PII h2=*it;
            if(f(r[i].F,r[i].S,h1.F+h2.F)>ma){
                ma=f(r[i].F,r[i].S,h1.F+h2.F);
                an.clear();
                an.PB(h1.S);
                an.PB(h2.S);
            }
        }
    }
    printf("%d\n",SZ(an));
    REP(i,SZ(an))printf("%d ",an[i]);
    return 0;
}