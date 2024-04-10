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
typedef long double LD;
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL r[SIZE],w[SIZE];
int a[SIZE];
int get_type(int x){
    if(r[x]==0){
        return w[x]>0?2:6;
    }
    if(w[x]==0){
        return r[x]>0?0:4;
    }
    if(r[x]>0){
        return w[x]>0?1:7;
    }
    else{
        return w[x]>0?3:5;
    }
}
bool compare(int x,int y){
    int xt=get_type(x);
    int yt=get_type(y);
    if(xt!=yt)return xt<yt;
    if(xt%2==0){
        return abs(r[x]+w[x])<abs(r[y]+w[y]);
    }
    if(r[x]*w[y]==r[y]*w[x])return abs(r[x])<abs(r[y]);
    return r[x]*w[y]>w[x]*r[y];
}
bool adv(int x,int y){
    if(r[x]*w[y]==w[x]*r[y]){
        if(get_type(x)==get_type(y)){
            return abs(r[x])+abs(w[x])>abs(r[y])+abs(w[y]);
        }
        return 0;
    }
    return r[x]*w[y]<w[x]*r[y];
}
bool adv2(int x,int y){
    if(r[x]*w[y]==w[x]*r[y]){
        if(get_type(x)==get_type(y)){
            return abs(r[x])+abs(w[x])>abs(r[y])+abs(w[y]);
        }
        return 1;
    }
    return r[x]*w[y]<w[x]*r[y];
}
int main(){
    DRIII(n,c,d);
    LL an=n*(n-1LL)*(n-2)/6;
    REP(i,n){
        cin>>r[i]>>w[i];
        r[i]-=c;
        w[i]-=d;
        a[i]=i;
    }
    sort(a,a+n,compare);
    bool fail=1;
    REPP(i,1,n){
        if(r[a[i]]*w[a[i-1]]!=r[a[i-1]]*w[a[i]])fail=0;
    }
    if(fail){
        puts("0");
        return 0;
    }
    REP(i,n)a[i+n]=a[i];
    int ll=0,ll2=0;
    REP(i,2*n){
        while(adv(a[ll],a[i])||i-ll>=n)ll++;
        while(adv2(a[ll2],a[i])||i-ll2>=n)ll2++;
        if(i>=n){
            //printf("(%I64d,%I64d):%d,%d\n",r[a[i]],w[a[i]],i-ll,i-ll2);
            LL me=i-ll;
            an-=me*(me-1LL)/2;
            LL you=ll2-ll;
            an+=you*(you-1LL)/2;
        }
    }
    cout<<an;
    return 0;
}