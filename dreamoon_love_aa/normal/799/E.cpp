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
const LL INF = 1e18;
const int SIZE = 1e6+12;
int ty[SIZE],c[SIZE];
VPII d[4],all;
int BIT[SIZE];
LL BIT_V[SIZE];
LL an;
int in_num;
int get_id(PII x){
    return lower_bound(ALL(all),x)-all.begin();
}
void ins(int x,int ng){
    int id=x;
    in_num+=ng;
    LL v=all[id].F;
    for(;x<SIZE;x+=x&-x){
        BIT[x]+=ng;
        BIT_V[x]+=ng*v;
    }
}
int qq(int x){
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
void ins0(PII me,int ng){
    int it=get_id(me);
    ins(it,ng);
}
LL qq0(int num){
    if(num>in_num)return INF;
    if(!num)return 0;
    int ll=1,rr=SIZE-1;
    while(ll<rr){
        int mm=(ll+rr)/2;
        if(qq(mm)>=num)rr=mm;
        else ll=mm+1;
    }
    LL ret=0;
    for(;ll;ll-=ll&-ll)ret+=BIT_V[ll];
    return ret;
}
int main(){
    an=INF;
    DRIII(n,m,K);
    REP(i,n)RI(c[i]);
    DRI(nn);
    REP(i,nn){
        DRI(x);x--;
        ty[x]|=1;
    }
    RI(nn);
    REP(i,nn){
        DRI(x);x--;
        ty[x]|=2;
    }
    all.PB(MP(-1,-1));
    REP(i,n){
        d[ty[i]].PB(MP(c[i],i));
        all.PB(MP(c[i],i));
    }
    REP(i,4)sort(ALL(d[i]));
    sort(ALL(all));
    int st=min(min(K,m),SZ(d[3]));
    REPP(i,st,SZ(d[3])){
        ins0(d[3][i],1);
    }
    REP(i,SZ(d[0]))ins0(d[0][i],1);
    REPP(j,1,3)
        REPP(i,max(0,K-st),SZ(d[j]))ins0(d[j][i],1);
    LL now=0;
    REP(i,st)now+=d[3][i].F;
    if(K-st>min(SZ(d[1]),SZ(d[2])))return 0*puts("-1");
    REP(i,K-st)now+=d[1][i].F+d[2][i].F;
    for(int i=st;i>=0;i--){
        if(i+(K-i)*2>m)break;
        if(min(SZ(d[1]),SZ(d[2]))+i<K)break;
        an=min(an,now+qq0(m-i-(K-i)*2));
        if(i){
            now-=d[3][i-1].F;
            ins0(d[3][i-1],1);
            if(K-i<SZ(d[1])){
                now+=d[1][K-i].F;
                ins0(d[1][K-i],-1);
            }
            if(K-i<SZ(d[2])){
                now+=d[2][K-i].F;
                ins0(d[2][K-i],-1);
            }
        }
    }
    if(an==INF)an=-1;
    cout<<an<<endl;
    return 0;
}