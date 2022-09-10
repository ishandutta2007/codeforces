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
bool v[SIZE];
int main(){
    string s[100];
    DRII(n,k);
    REP(i,n){
        cin>>s[i];
    }
    int ll=0;
    string an;
    REP(i,k){
        DRI(x);x--;
        v[x]=1;
        if(!i){
            ll=SZ(s[x]);
            an=s[x];
        }
        else if(ll!=SZ(s[x]))return 0*puts("No");
        else{
            REP(j,SZ(s[x])){
                if(s[x][j]!=an[j])an[j]='?';
            }
        }
    }
    REP(i,n){
        if(v[i])continue;
        if(SZ(s[i])!=SZ(an))continue;
        bool suc=0;
        REP(j,SZ(an)){
            if(an[j]!='?'&&an[j]!=s[i][j])suc=1;
        }
        if(!suc)return 0*puts("No");
    }
    puts("Yes");
    cout<<an<<endl;
    return 0;
}