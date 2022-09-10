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
void print_array(vector<int>&arr){
    REP(i,SZ(arr)){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
int an[SIZE];
int main(){
    DRI(n);
    VPII pp;
    REP(i,n){
        DRI(x);
        pp.PB(MP(x,i+1));
    }
    vector<int>res;
    sort(ALL(pp));
    reverse(ALL(pp));
    int now=1;
    REP(i,SZ(pp)){
        int j;
        for(j=0;i+j<SZ(pp)&&pp[i+j].F==pp[i].F;j++){
            an[pp[i+j].S]=now;
        }
        now+=j;
        i+=j-1;
    }
    REPP(i,1,n+1)res.PB(an[i]);
    print_array(res);
    return 0;
}