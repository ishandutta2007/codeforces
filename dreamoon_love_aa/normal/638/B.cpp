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
int to[128][129];
bool used[128];
int v[128];
int main(){
    DRI(n);
    REP(i,n){
        char s[30];
        RS(s);
        int m=LEN(s);
        REP(i,m){
            used[s[i]]=1;
            if(i){
                to[s[i-1]][s[i]]=1;
                v[s[i]]++;
            }
        }
    }
        char c=0;
        REPP(i,'a','z'+1){
            if(used[i]&&!v[i]){
                c=i;
                printf("%c",c);
                while(1){
                    char nxt_c=0;
                    REPP(j,'a','z'+1){
                        if(to[c][j]){
                            nxt_c=j;
                            break;
                        }
                    }
                    if(nxt_c){
                        c=nxt_c;
                        printf("%c",c);
                    }
                    else break;
                }
            }
        }
    return 0;
}