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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
// template end here
int a[SIZE];
int an;
int n,l,r,x;
void dfs(int id,int mi,int ma,int sum,int num){
    if(id==n){
        if(l<=sum&&sum<=r&&ma-mi>=x&&num>=2)an++;
        return;
    }
    dfs(id+1,mi,ma,sum,num);
    dfs(id+1,min(mi,a[id]),max(ma,a[id]),sum+a[id],num+1);
}
int main(){
    RII(n,l);
    RII(r,x);
    REP(i,n)RI(a[i]);
    dfs(0,INF,-INF,0,0);
    cout<<an<<endl;
    return 0;
}