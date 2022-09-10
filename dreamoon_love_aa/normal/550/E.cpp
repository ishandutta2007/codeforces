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
// template end here
int a[SIZE];
int cnt[2];
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i]);
        cnt[a[i]]++;
    }
    if(a[n-1]==1||(cnt[0]==2&&a[n-2]==0&&a[n-1]==0))puts("NO");
    else{
        puts("YES");
        if(n==1||a[n-2]==1){
            REP(i,n){
                if(i)printf("->");
                printf("%d",a[i]);
            }
        }
        else{
            vector<int>zero;
            REP(i,n-1)
                if(a[i]==0)zero.PB(i);
            REP(i,SZ(zero)){
                int lt;
                if(i){
                    lt=zero[i-1]+1;
                    printf("->");
                }
                else lt=0;
                if(i==SZ(zero)-2)putchar('(');
                putchar('(');
                REPP(j,lt,zero[i]+1){
                    if(j!=lt)printf("->");
                    printf("%d",a[j]);
                }
                putchar(')');
            }
            printf(")->0");
        }
        puts("");
    }
    return 0;
}