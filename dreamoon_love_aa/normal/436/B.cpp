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
const int SIZE = 2020;
char s[SIZE][SIZE];
int an[SIZE],n,m,k;
bool Out(int x){
    return x<0||x>=m;
}
int main(){
    RIII(n,m,k);
    REP(i,n){
        RS(s[i]);
        REP(j,m){
            if(s[i][j]=='U'){
                if(i%2==0)an[j]++;
            }
            else if(s[i][j]=='R'){
                if(!Out(j+i))an[j+i]++;
            }
            else if(s[i][j]=='L'){
                if(!Out(j-i))an[j-i]++;
            }
        }
    }
    REP(i,m){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}