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
const int SIZE = 1e5+10;
int p[SIZE];
vector<int>pp;
void prime_init(){
    for(int i=2;i<SIZE;i++){
        if(!p[i]){
            pp.PB(i);
            for(int j=i;j<SIZE;j+=i){
                if(!p[j])p[j]=i;
            }
        }
    }
}
bool is_prime(int x){
    return p[x]==x;
}
int a[SIZE],pos[SIZE];
VPII an;
void move(int x,int y){
    if(x==y)return;
    int dd=x-y+1;
    int it=upper_bound(ALL(pp),dd)-pp.begin()-1;
    int ll=x+1-pp[it];
    an.PB(MP(ll,x));
    swap(a[ll],a[x]);
    pos[a[ll]]=ll;
    pos[a[x]]=x;
    move(ll,y);
}
int main(){
    prime_init();
    DRI(n);
    REP(i,n){
        RI(a[i+1]);
        pos[a[i+1]]=i+1;
    }
    REPP(i,1,n+1){
        move(pos[i],i);
    }
    printf("%d\n",SZ(an));
    REP(i,SZ(an))printf("%d %d\n",an[i].F,an[i].S);
    return 0;
}