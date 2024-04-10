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
    if(x<SIZE)return p[x]==x;
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0)return 0;
    return 1;
}
int main(){
    prime_init();
    DRI(n);
    if(is_prime(n)){
        printf("1\n%d\n",n);
    }
    else if(is_prime(n-2)){
        printf("2\n%d %d\n",2,n-2);
    }
    else if(is_prime(n-4)){
        printf("3\n%d %d %d\n",2,2,n-4);
    }
    else{
        int m=n-6;
        while(!is_prime(m)){
            m-=2;
        }
        printf("3\n%d",m);
        REPP(i,3,SIZE){
            if(is_prime(i)&&is_prime(n-m-i)){
                printf(" %d %d\n",i,n-m-i);
                break;
            }
            i++;
        }
    }
    return 0;
}