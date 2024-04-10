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
struct Union_Find{
    int d[SIZE],num[SIZE],en[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,en[i]=0;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        en[y]++;
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        en[y]+=en[x];
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
int a[SIZE],b[SIZE],d[SIZE],dn,dn2;
LL two[SIZE];
int main(){
    two[0]=1;
    REPP(i,1,SIZE){
        two[i]=two[i-1]*2%MOD;
    }
    DRI(N);
    REP(i,N){
        RII(a[i],b[i]);
        d[i]=a[i];
    }
    sort(d,d+N);
    dn=unique(d,d+N)-d;
    REP(i,N)a[i]=lower_bound(d,d+dn,a[i])-d;
    REP(i,N){
        d[i]=b[i];
    }
    sort(d,d+N);
    dn2=unique(d,d+N)-d;
    REP(i,N)b[i]=lower_bound(d,d+dn2,b[i])-d+dn;
    U.init(dn+dn2);
    REP(i,N){
        //printf("(%d,%d)\n",a[i],b[i]);
        U.uu(a[i],b[i]);
    }
    LL an=1;
    REP(i,dn+dn2){
        if(U.find(i)==i){
            if(U.en[i]>=U.num[i])an=an*two[U.num[i]]%MOD;
            else{
                an=an*(two[U.num[i]]-1)%MOD;
            }
        }
    }
    an%=MOD;
    if(an<0)an+=MOD;
    cout<<an<<endl;
    return 0;
}