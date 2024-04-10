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
int num[SIZE],lt[SIZE],d[SIZE],l[SIZE];
void copy(int n){
    memcpy(d,num,sizeof(int)*n);
    memcpy(l,lt,sizeof(int)*n);
}
bool cmp(int x,int y){
    if(d[x]!=d[y])return d[x]>d[y];
    return l[x]<l[y];
}
int main(){
    DRII(n,k);DRII(m,a);
    if(n==1)return 0*puts("1");
    REP(i,a){
        DRI(x);x--;
        num[x]++;
        lt[x]=i;
    }
    VI id;
    REP(i,n)id.PB(i);
    REP(i,n){
        copy(n);
        REPP(j2,a,m){
            int nxt=-1;
            PII ma=MP(-1,-1);
            REP(j,n){
                if(d[j]<d[i]||(d[j]==d[i]&&l[j]>l[i])){
                    if(ma<MP(d[j],l[j])){
                        ma=MP(d[j],l[j]);
                        nxt=j;
                    }
                }
            }
            //printf("(%d)",nxt);
            if(ma.F!=-1){
                d[nxt]++;
                l[nxt]=j2;
            }
        }
        sort(ALL(id),cmp);
        bool suc=0;
        REP(j,k){
            if(id[j]==i&&d[i])suc=1;
        }
        if(suc){
            printf("%d ",1);
            continue;
        }
        copy(n);
        REPP(j,a,m){
            d[i]++;
            l[i]=j;
        }
        sort(ALL(id),cmp);
        REP(j,k){
            if(id[j]==i&&d[i])suc=1;
        }
        if(suc){
            printf("2 ");
        }
        else printf("3 ");
    }
    return 0;
}