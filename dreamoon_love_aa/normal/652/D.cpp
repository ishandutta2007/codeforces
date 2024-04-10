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
int d[SIZE],dn,a[SIZE],x[SIZE],y[SIZE],an[SIZE];
struct data{
    int x,y,id;
    data(int _x=0,int _y=0,int _z=0):x(_x),y(_y),id(_z){}
    bool operator<(data b)const{return y<b.y;}
};
vector<data>ker;
int BIT[SIZE];
void ins(int x){
    for(;x<SIZE;x+=x&-x)BIT[x]++;
}
int qq(int x){
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
int main(){
    DRI(n);
    REP(i,n){
        RII(x[i],y[i]);
        d[dn++]=x[i];
        d[dn++]=y[i];
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    REP(i,n){
        ker.PB(data(lower_bound(d,d+dn,x[i])-d+1,lower_bound(d,d+dn,y[i])-d+1,i));
    }
    sort(ALL(ker));
    REP(i,n){
        an[ker[i].id]=qq(SIZE-ker[i].x);
        ins(SIZE-ker[i].x);
    }
    REP(i,n)printf("%d\n",an[i]);
    return 0;
}