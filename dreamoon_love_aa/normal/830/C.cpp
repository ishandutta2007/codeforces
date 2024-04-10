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
int a[111],n;
LL K;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int main(){
    RI(n);
    cin>>K;
    int ma=0;
    LL sum=0;
    REP(i,n){
        RI(a[i]);
        ma=max(ma,a[i]);
    }
    REP(i,n)sum+=ma-a[i];
    if(sum<=K){
        cout<<ma+(K-sum)/n;
        return 0;
    }
    LL an=0,now=1;
    while(now<ma){
        LL nxt=1e18;
        LL ret=0;
        LL seg=0;
        LL need=0;
        REP(i,n){
            LL v=((a[i]-1)/now+1);
            seg+=v;
            need+=v*now-a[i];
            if(v!=1){
                nxt=min(nxt,(a[i]+v-2)/(v-1));
            }
            if(ret>K)break;
        }
        if(need<=K){
            an=now+(K-need)/seg;
        }
        now=nxt;
    }
    cout<<an<<endl;
    return 0;
}