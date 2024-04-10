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
const int MAX_V=10000*10000;
int qq(int x,int y){
    printf("0 %d %d\n",x,y);
    fflush(stdout);
    DRI(v);
    return v;
}
VI mid;
void go(int ll,int rr){
    if(ll+1>=rr)return;
    int mm=ll+(rr-ll)/2;
    int res=qq(mm,mm);
    int nxt=mm+res;
    if(nxt==rr)return;
    if(qq(nxt,nxt)==0){
        mid.PB(nxt);
        go(ll,nxt);
        go(nxt,rr);
        return;
    }
    nxt=mm-res;
    if(nxt!=ll){
        mid.PB(nxt);
        go(ll,nxt);
        go(nxt,rr);
    }
}
int main(){
    int ll=-MAX_V+qq(-MAX_V,-MAX_V);
    int rr=MAX_V-qq(MAX_V,MAX_V);
    mid.PB(ll);
    mid.PB(rr);
    go(ll,rr);
    sort(ALL(mid));
    mid.resize(unique(ALL(mid))-mid.begin());
    int emp=-MAX_V;
    while(binary_search(ALL(mid),emp))emp++;
    VI xx,yy;
    REP(i,SZ(mid)){
        if(qq(mid[i],emp)==0)xx.PB(mid[i]);
        if(qq(emp,mid[i])==0)yy.PB(mid[i]);
    }
    printf("1 %d %d\n",SZ(xx),SZ(yy));
    fflush(stdout);

    REP(i,SZ(xx)){
        if(i)printf(" ");
        printf("%d",xx[i]);
    }
    puts("");
    fflush(stdout);
    
    REP(i,SZ(yy)){
        if(i)printf(" ");
        printf("%d",yy[i]);
    }
    puts("");
    fflush(stdout);
    return 0;
}