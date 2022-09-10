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
int a[26];
int main(){
    DRI(n);
    int odd=0,odd_v=0,sum=0,only=0;
    REP(i,n){
        RI(a[i]);
        if(a[i]&1)
            odd++;
        sum+=a[i];
    }
    if(n==1){
        printf("%d\n",sum);
        REP(i,sum)printf("a");
        puts("");
        return 0;
    }
    else if(odd>1){
        puts("0");
        REP(i,26){
            REP(j,a[i])printf("%c",i+'a');
        }
        puts("");
        return 0;
    }
    else if(odd==1){
        int gg=0;
        REP(i,26){
            if(a[i]){
                if(!gg)gg=a[i];
                else gg=__gcd(gg,a[i]);
            }
        }
        printf("%d\n",gg);
        REP(k,gg){
            REP(i,26){
                if(a[i]&1){
                    REP(j,a[i]/gg)printf("%c",i+'a');
                }
            }
            REP(i,26){
                if(a[i]%2==0){
                    REP(j,a[i]/(gg*2))printf("%c",i+'a');
                }
            }
            for(int i=25;i>=0;i--){
                if(a[i]%2==0){
                    REP(j,a[i]/(gg*2))printf("%c",i+'a');
                }
            }
        }
        puts("");
        return 0;
    }
    else{
        int gg=0;
        REP(i,26){
            if(a[i]){
                if(!gg)gg=a[i];
                else gg=__gcd(gg,a[i]);
            }
        }
        if(gg%2==1){
            puts("0");
            REP(i,26){
                REP(j,a[i])printf("%c",i+'a');
            }
            puts("");
        }
        else{
            printf("%d\n",gg);
            REP(i,gg){
                if(i%2==0){
                    REP(i,26)
                        REP(j,a[i]/gg)printf("%c",i+'a');
                }
                else{
                    for(int i=25;i>=0;i--)
                        REP(j,a[i]/gg)printf("%c",i+'a');
                }
            }
            puts("");
        }
    }
    return 0;
}