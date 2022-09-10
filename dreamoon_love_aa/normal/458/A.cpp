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
const int SIZE = 1e6;
int d[2][SIZE];
char s[SIZE];
void go(int a[]){
    RS(s);
    int n=LEN(s);
    REP(i,n){
        if(s[n-1-i]=='1')a[i]++;
    }
    int now=n-1;
    while(now>0){
        if(a[now]==1&&a[now-1]==1){
            a[now]--;
            a[now-1]--;
            a[now+1]++;
            now+=3;
        }
        else now--;
    }
}
int main(){
    go(d[0]);
    go(d[1]);
    for(int i=SIZE-1;i>=0;i--){
        if(d[0][i]>d[1][i]){
            puts(">");
            return 0;
        }
        else if(d[0][i]<d[1][i]){
            puts("<");
            return 0;
        }
    }
    puts("=");
    return 0;
}