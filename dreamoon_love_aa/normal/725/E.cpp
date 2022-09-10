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
const int SIZE = 262144;
int c,a[SIZE];
LL BIT[262144];
void ins(int x,int v){
    for(;x<SIZE;x+=x&-x)BIT[x]+=v;
}
int qq(LL low_bd){
    LL me=0;
    int now=0;
    for(int it=17;it>=0;it--){
        if(me+BIT[now|(1<<it)]<low_bd){
            now|=1<<it;
            me+=BIT[now];
        }
    }
    return now+1;
}
LL qq2(int x){
    LL res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
bool solve(int n){
    int r=c;
    while(r){
        int it=upper_bound(a+1,a+1+n,r)-1-a;
        LL all=qq2(it);
        if(!it||all<r)return 0;
        if(all==r||a[it]==r)return 1;
        int ll=qq(all-r);
        r-=all-qq2(ll);
        n=ll;
    }
    return 1;
}
int main(){
    RI(c);
    DRI(n);
    REPP(i,1,n+1)RI(a[i]);
    sort(a+1,a+1+n);
    REPP(i,1,n+1)ins(i,a[i]);
    if(!solve(n))return 0*puts("Greed is good");
    n++;
    for(int i=n;i>1;i--)a[i]=a[i-1];
    a[1]=1;
    MS0(BIT);
    REPP(i,1,n+1)ins(i,a[i]);
    int it=1;
    REPP(i,1,c){
        if(!solve(n))return 0*printf("%d\n",i);
        ins(it,1);
        a[it]++;
        while(it<n&&a[it]>a[it+1]){
            ins(it,-1);
            ins(it+1,1);
            swap(a[it],a[it+1]);
            it++;
        }
    }
    return 0*puts("Greed is good");
}