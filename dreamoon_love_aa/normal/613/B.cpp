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
PII a[SIZE];
int an[SIZE];
void print_array(int arr[],int n){
    REP(i,n){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
int main(){
    DRII(n,A);
    DRII(c_f,c_m);
    LL m;
    cin>>m;
    REP(i,n){
        RI(a[i].F);
        a[i].S=i;
    }
    sort(a,a+n);
    a[n]=MP(MOD,n);
    int fulll=0;
    LL used=0;
    while(fulll<n){
        if(used+(A-a[n-1-fulll].F)<=m){
            used+=(A-a[n-1-fulll].F);
            fulll++;
        }
        else break;
    }
    if(fulll==n){
        cout<<c_f*(LL)n+c_m*(LL)A<<endl;
        REP(i,n)an[i]=A;
        print_array(an,n);
        return 0;
    }
    int now=1,eve=-1;
    LL sum=a[0].F;
    int ret=-1;
    LL ma=-1;
    for(;fulll>=0;fulll--){
        while(now+fulll<n&&a[now].F*(LL)now-sum+used<=m){
            sum+=a[now].F;
            now++;
        }
        LL me=fulll*(LL)c_f+(sum+(m-used))/now*c_m;
        if(me>ma){
            eve=(sum+(m-used))/now;
            ma=me;
            ret=fulll;
        }
        used-=A-a[n-fulll].F;
        if(fulll<0)break;
    }
    REP(i,n-ret){
        an[a[i].S]=max(a[i].F,eve);
    }
    REP(i,ret){
        an[a[n-1-i].S]=A;
    }
    cout<<ma<<endl;
    print_array(an,n);
    return 0;
}