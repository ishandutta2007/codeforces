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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+10;
LL a[SIZE];
struct UPG{
    LL x,y;
    int id;
    UPG(LL _x=0,LL _y=0,int _id=0):x(_x),y(_y),id(_id){}
    bool operator<(const UPG& b)const{
        return (long double)x/y>(long double)b.x/b.y;
    }
}d[SIZE];
int dn=0;
int ma[SIZE],ma_id[SIZE],res[SIZE];
VPII skill[SIZE];
int tt[SIZE];
bool compare(int x,int y){
    return tt[x]<tt[y];
}
int main(){
    DRIII(k,n,m);
    MS1(ma);
    REP(i,k){
        scanf("%I64d",&a[i+1]);
    }
    REPP(i,1,n+1){
        DRIII(ty,id,b);
        tt[i]=ty;
        if(ty==3){
            d[dn++]=UPG(b,1,i);
        }
        else if(ty==2){
            skill[id].PB(MP(b,i));
        }
        else{
            if(ma[id]<b){
                ma[id]=b;
                ma_id[id]=i;
            }
        }
    }
    REPP(i,1,k+1){
        if(ma[i]>a[i]){
            skill[i].PB(MP(ma[i]-a[i],ma_id[i]));
        }
    }
    REPP(i,1,k+1){
        sort(ALL(skill[i]));
        reverse(ALL(skill[i]));
        LL now=a[i];
        REP(j,SZ(skill[i])){
            d[dn++]=UPG(now+skill[i][j].F,now,skill[i][j].S);
            now+=skill[i][j].F;
        }
    }
    sort(d,d+dn);
    m=min(m,dn);
    printf("%d\n",m);
    REP(i,m)res[i]=d[i].id;
    sort(res,res+m,compare);
    REP(i,m){
        if(i)printf(" ");
        printf("%d",res[i]);
    }
    puts("");
    return 0;
}