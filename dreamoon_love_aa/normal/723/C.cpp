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
int a[SIZE],cnt[SIZE];
int main(){
    DRII(n,m);
    int v=n/m;
    REP(i,n){
        RI(a[i]);
        if(a[i]<=m)cnt[a[i]]++;
    }
    int an2=0;
    REPP(i,1,m+1){
        REP(j,n){
            if(cnt[i]>=v)continue;
            if(a[j]>m||cnt[a[j]]>v){
                an2++;
                if(a[j]>m){
                    a[j]=i;
                }
                else{
                    cnt[a[j]]--;
                    a[j]=i;
                }
                cnt[i]++;
            }
        }
    }
    printf("%d %d\n",v,an2);
    REP(i,n)printf("%d ",a[i]);
    return 0;
}