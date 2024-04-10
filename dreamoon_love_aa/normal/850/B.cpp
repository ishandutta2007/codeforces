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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 1000001;
LL an;
int n,X,Y,D;
int cnt[SIZE];
int p[SIZE];
LL sum[SIZE];
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
int get(int L,int R){
    R=min(R,SIZE-1);
    if(R<L)return 0;
    if(L)L--;
    return cnt[R]-cnt[L];
}
LL get2(int L,int R){
    R=min(R,SIZE-1);
    if(R<L)return 0;
    if(L)L--;
    return sum[R]-sum[L];
}
void test(int gg){
    LL v=0;
    for(int i=gg;;i+=gg){
        int ll=max(i-gg+1,i-D);
        int n1=0,n2=0;
        LL sv=0;
        if(ll>i-gg+1){
            n1=get(i-gg+1,ll-1);
        }
        sv=get2(ll,i);
        n2=get(ll,i);
        v+=n1*(LL)X+(i*(LL)n2-sv)*Y;
        if(i>=SIZE-1)break;
    }
    an=min(an,v);
}
int main(){
    an=1e18;
    prime_init();
    RIII(n,X,Y);
    D=X/Y;
    REP(i,n){
        DRI(x);
        cnt[x]++;
        sum[x]+=x;
    }
    REPP(i,1,SIZE){
        cnt[i]+=cnt[i-1];
        sum[i]+=sum[i-1];
    }
    REPP(i,2,SIZE){
        if(is_prime(i))
            test(i);
    }
    cout<<an<<endl;
    return 0;
}