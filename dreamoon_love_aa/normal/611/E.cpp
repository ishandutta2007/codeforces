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
int a[3];
bool used[SIZE];
int d[SIZE];
int main(){
    DRI(n);
    REP(i,3)RI(a[i]);
    sort(a,a+3);
    REP(i,n){
        RI(d[i]);
        if(d[i]>a[0]+a[1]+a[2])return 0*puts("-1");
    }
    sort(d,d+n);
    int an=0;
    int it=n-1;
    {
        int it0=n-1,it1=n-1,it2=n-1;
        for(;it>=0&&d[it]>a[2];it--){
            if(used[it])continue;
            int now=d[it];
            used[it]=1;
            an++;
            if(now<=a[1]+a[2]){
                if(now<=a[0]+a[1]){
                    while(it2>=0&&(used[it2]||d[it2]>a[2]))it2--;
                    if(it2>=0)used[it2]=1;
                }
                else if(now<=a[0]+a[2]){
                    while(it1>=0&&(used[it1]||d[it1]>a[1]))it1--;
                    if(it1>=0)used[it1]=1;
                }
                else{
                    while(it0>=0&&(used[it0]||d[it0]>a[0]))it0--;
                    if(it0>=0)used[it0]=1;
                }
            }
        }
    }
    {
        int it0=it,it1=it,it2=it;
        for(;it>=0;it--){
            if(used[it])continue;
            used[it]=1;
            an++;
            while(it1>=0&&(used[it1]||d[it1]>a[1]))it1--;
            while(it0>=0&&(used[it0]||d[it0]>a[0]||it0>=it1))it0--;
            if(it0<0){
                while(it2>=0&&(used[it2]||d[it2]>a[0]+a[1]))it2--;
                if(it2>=0)used[it2]=1;
                continue;
            }
            used[it1]=used[it0]=1;
        }
    }
    printf("%d\n",an);
    return 0;
}