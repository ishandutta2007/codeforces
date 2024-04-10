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
int a[SIZE],BIT[SIZE];
void ins(int x,int v){
    for(;x<SIZE;x+=x&-x)BIT[x]+=v;
}
int qq(int x){
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
int p[SIZE];
VI d[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i+1]);
        d[a[i+1]].PB(i+1);
        ins(i+1,1);
    }
    int lt=0;
    LL an=0;
    int r=n;
    REPP(i,1,SIZE){
        if(!SZ(d[i]))continue;
        int it=lower_bound(ALL(d[i]),lt)-d[i].begin();
        if(it==SZ(d[i]))it=0;
        REP(j,SZ(d[i])){
            int now=d[i][(it+j)%SZ(d[i])];
            if(lt<now){
                an+=qq(now);
                an-=qq(lt);
            }
            else{
                an+=r+qq(now)-qq(lt);
            }
            ins(now,-1);
            r--;
            lt=now;
        }
    }
    cout<<an;
    return 0;
}