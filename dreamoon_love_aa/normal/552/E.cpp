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
char s[SIZE];
vector<int>d[20];
int dn;
LL solve(int L,int R){
    LL res=0;
    LL res2=0;
    LL now=1;
    LL now2=1;
    REP(i,dn){
        if(i>=L&&i<=R){
            now2*=d[i][0];
            REPP(j,1,SZ(d[i])){
                res2+=now2;
                now2=d[i][j];
            }
        }
        else{
            if(i==R+1)now*=res2+now2;
            now*=d[i][0];
            REPP(j,1,SZ(d[i])){
                res+=now;
                now=d[i][j];
            }
        }
    }
    if(R==dn-1)now*=res2+now2;
    return res+now;
}
int main(){
    RS(s);
    int n=LEN(s);
    REP(i,n){
        if(i){
            if(s[i]=='*')dn++;
            i++;
        }
        d[dn].PB(s[i]-'0');
    }
    dn++;
    LL an=0;
    REP(i,dn)REP(j,i+1)
        an=max(an,solve(j,i));
    cout<<an;
    return 0;
}