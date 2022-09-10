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
char s[100]="qwertyuiopasdfghjkl;zxcvbnm,./";
int main(){
    char LR[12],ss[1111];
    RS(LR);
    RS(ss);
    int n=LEN(ss);
    if(LR[0]=='L'){
        REP(i,n){
            for(int j=0;;j++){
                if(ss[i]==s[j]){
                    ss[i]=s[j+1];
                    break;
                }
            }
        }
    }
    else{
        REP(i,n){
            for(int j=0;;j++){
                if(ss[i]==s[j]){
                    ss[i]=s[j-1];
                    break;
                }
            }
        }
    }
    puts(ss);
    return 0;
}