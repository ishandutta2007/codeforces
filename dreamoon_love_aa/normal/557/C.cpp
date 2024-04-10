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
PII pp[SIZE];
multiset<int>H;
int main(){
    DRI(n);
    LL sum=0,ma=0;
    REP(i,n){
        RI(pp[i].F);
    }
    REP(i,n){
        RI(pp[i].S);
        sum+=pp[i].S;
    }
    sort(pp,pp+n);
    for(int i=0,j;i<n;i=j){
        for(j=i;j<n&&pp[i].F==pp[j].F;j++);
        REPP(k,i,j)
            swap(pp[k].F,pp[k].S);
        sort(pp+i,pp+j);
        reverse(pp+i,pp+j);
        LL now=0;
        multiset<int>::reverse_iterator it=H.rbegin();
        REPP(k,i,j){
            now+=pp[k].F;
            ma=max(ma,now);
            if(it!=H.rend()){
                now+=*it;
                it++;
            }
        }
        REPP(k,i,j)H.insert(pp[k].F);
    }
    cout<<sum-ma<<endl;
    return 0;
}