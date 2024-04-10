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
const int SIZE = 1e6+10;
int a[26][26],dif[111];
char s[111][111];
int main(){
    DRI(n);
    REP(i,n){
        RS(s[i]);
    }
    REP(i,110){
        REPP(j,1,n){
            if(dif[j])continue;
            if(s[j][i]!=s[j-1][i]){
                if(!s[j][i]){
                    puts("Impossible");
                    return 0;
                }
                if(s[j-1][i])a[s[j-1][i]-'a'][s[j][i]-'a']=1;
                dif[j]=1;
            }
        }
    }
    REP(k,26)REP(i,26)REP(j,26)
        if(a[i][k]&&a[k][j])a[i][j]=1;
    vector<pair<int,char> >pp;
    REP(i,26){
        if(a[i][i]){
            puts("Impossible");
            return 0;
        }
        int cnt=0;
        REP(j,26)
            if(a[i][j])cnt++;
        pp.PB(MP(cnt,i+'a'));
    }
    sort(ALL(pp));
    reverse(ALL(pp));
    REP(i,SZ(pp))printf("%c",pp[i].S);
    puts("");
    return 0;
}