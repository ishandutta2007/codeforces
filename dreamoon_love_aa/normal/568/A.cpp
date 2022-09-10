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
const int SIZE = 1e7+10;
// template end here
int p[SIZE];
void prime_init(){
    for(int i=2;i<SIZE;i++){
        if(!p[i]){
            for(int j=i;j<SIZE;j+=i){
                if(!p[j])p[j]=i;
            }
        }
    }
}
bool is_prime(int x){
    return p[x]==x;
}
bool is_pal(int x){
    int xx=x;
    int y=0;
    while(xx){
        y=y*10+xx%10;
        xx/=10;
    }
    return x==y;
}
int main(){
    DRII(p,q);
    prime_init();
    int pn=0,pn2=0,an=0;
    REPP(i,1,SIZE){
        if(is_prime(i))pn++;
        if(is_pal(i))pn2++;
        if((LL)q*pn<=(LL)p*pn2)an=i;
    }
    printf("%d\n",an);
    return 0;
}