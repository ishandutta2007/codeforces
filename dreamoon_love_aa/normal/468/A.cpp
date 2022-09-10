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
int main(){
    DRI(n);
    if(n<4)puts("NO");
    else{
        puts("YES");
        int st;
        if(n%4==0){
            puts("1 * 2 = 2");
            puts("2 * 3 = 6");
            puts("6 * 4 = 24");
            st=5;
        }
        else if(n%4==1){
            puts("5 * 4 = 20");
            puts("20 + 3 = 23");
            puts("23 + 2 = 25");
            puts("25 - 1 = 24");
            st=6;
        }
        else if(n%4==2){
            puts("6 * 4 = 24");
            puts("2 * 3 = 6");
            puts("24 + 6 = 30");
            puts("30 - 1 = 29");
            puts("29 - 5 = 24");
            st=7;
        }
        else if(n%4==3){
            puts("6 * 4 = 24");
            puts("24 + 7 = 31");
            puts("31 - 5 = 26");
            puts("26 + 2 = 28");
            puts("28 - 1 = 27");
            puts("27 - 3 = 24");
            st=8;
        }
        for(int i=st;i<=n;i+=4){
            printf("%d - %d = 1\n",st+1,st);
            printf("%d - %d = 1\n",st+3,st+2);
            printf("1 - 1 = 0\n");
            printf("%d + 0 = %d\n",24,24);
            st+=4;
        }
    }
    return 0;
}