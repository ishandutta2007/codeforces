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
char s[SIZE];
int main(){
    gets(s);
    int add=1,neg=0;
    int it=0;
    for(;s[it]!='=';it++){
        if(s[it]=='+')add++;
        else if(s[it]=='-')neg++;
    }
    it++;
    while(s[it]==' ')it++;
    int n=atoi(s+it);
    if(n<=add*n-neg&&n>=add-neg*n){
        puts("Possible");
        int lt=1;
        int now=add*n-neg;
        for(int i=0;s[i];i++){
            if(s[i]=='?'){
                if(lt==1){
                    int sub=min(n-1,now-n);
                    now-=sub;
                    printf("%d",n-sub);
                }
                else{
                    int sub=min(n-1,now-n);
                    now-=sub;
                    printf("%d",1+sub);
                }
            }
            else{
                if(s[i]=='+')lt=1;
                else if(s[i]=='-')lt=-1;
                printf("%c",s[i]);
            }
        }
        puts("");
    }
    else puts("Impossible");
    return 0;
}