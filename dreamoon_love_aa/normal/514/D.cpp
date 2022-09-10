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
multiset<int>H[5];
int a[SIZE][5];
void add(int id,int m){
    REP(i,m)H[i].insert(a[id][i]);
}
void ere(int id,int m){
    REP(i,m)H[i].erase(H[i].find(a[id][i]));
}
int get(int m){
    if(SZ(H[0])==0)return 0;
    int ret=0;
    REP(i,m)ret+=*H[i].rbegin();
    return ret;
}
int main(){
    DRIII(n,m,k);
    int an=0,ll=0;
    int res[5]={};
    REP(i,n){
        REP(j,m)RI(a[i][j]);
        add(i,m);
        while(get(m)>k)
            ere(ll++,m);
        if(i-ll+1>an){
            an=i-ll+1;
            REP(j,m)res[j]=*H[j].rbegin();
        }
    }
    REP(i,m)printf("%d ",res[i]);
    return 0;
}