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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
char s[100010][10],tmp[10];
int main(){
    DRI(n);
    REP(i,n){
        RS(s[i]);
    }
    int lt=0;
    REP(i,n){
        strcpy(tmp,s[i]);
        int len=LEN(s[i]);
        REP(j,len)
            if(tmp[j]=='?')tmp[j]='9';
        REP(j,len){
            if(s[i][j]=='?'){
                bool suc=false;
                REP(k,10){
                    if(!j&&!k)continue;
                    tmp[j]=k+'0';
                    if(atoi(tmp)>lt){
                        suc=true;
                        break;
                    }
                }
                if(!suc){
                    puts("NO");
                    return 0;
                }
            }
        }
        if(atoi(tmp)<=lt){
            puts("NO");
            return 0;
        }
        lt=atoi(tmp);
        strcpy(s[i],tmp);
    }
    puts("YES");
    REP(i,n){
        puts(s[i]);
    }
    return 0;
}