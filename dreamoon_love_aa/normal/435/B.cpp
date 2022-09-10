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
using namespace std;
char s[20];
char an[20],now[20];
int main(){
    RS(s);
    DRI(K);
    int len=LEN(s);
    REP(i,len){
        for(char c='9';c>='0';c--){
            int need=0;
            an[i]=c;
            strcpy(now,s);
            REP(j,i+1){
                int k;
                for(k=j;k<len&&now[k]!=an[j];k++);
                if(k==len){
                    need=1000000;
                    break;
                }
                for(;k>j;k--){
                    swap(now[k],now[k-1]);
                    need++;
                }
            }
            if(need<=K)break;
        }
    }
    puts(an);
    return 0;
}