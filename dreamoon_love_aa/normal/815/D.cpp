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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int row[SIZE],col[SIZE];
int main(){
    DRI(n);
    DRIII(p,q,r);
    VPII d;
    REP(i,n){
        DRIII(a,b,c);
        maa(row[a],b);
        maa(col[b],a);
        d.PB(MP(c,a));
        d.PB(MP(c,-b));
    }
    sort(ALL(d),greater<PII>());
    LL base=0;
    for(int i=p;i>0;i--){
        base+=row[i];
        maa(row[i-1],row[i]);
    }
    for(int i=q;i>0;i--){
        maa(col[i-1],col[i]);
    }
    int low_r=1,low_c=1;
    int it=0;
    LL an=0;
    LL now=base;
    for(int i=r;i>0;i--){
        while(it<SZ(d)&&d[it].F==i){
            int id=d[it].S;
            if(id<0){
                id=-id;
                while(low_c<=id)now+=p-max(low_r-1,col[low_c++]);
            }
            else{
                while(low_r<=id)now+=q-max(low_c-1,row[low_r++]);
            }
            it++;
        }
        an+=now;
    }
    cout<<(LL)p*q*r-an<<endl;
    return 0;
}