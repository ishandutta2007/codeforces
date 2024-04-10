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
LL INF = 2e18;
int n,m;
vector<int>d[100000][2];
// a*x+b*y=z
struct gcd_t {long long x,y,z;}gg;
LL inv[2],sz[2];
gcd_t gcd(long long a,long long b) {
    if(b==0)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}
void fresh(LL &x,LL v){
    x=min(x,v);
}
void mii(map<int,LL>&mi,LL x,LL v){
    if(mi.count(x))fresh(mi[x],v);
    else mi[x]=v;
}
void proccess(LL& now,map<int,LL>& mi,int round){
    map<int,LL>::iterator it=mi.begin();
    while(it!=mi.end()){
        fresh(it->S,now);
        fresh(now,it->S);
        int me=it->F;
        it++;
        int you;
        if(it!=mi.end())you=it->F;
        else you=mi.begin()->F+sz[round];
        now+=(you-me)*sz[round^1]*gg.z;
    }
}
LL f(vector<int>v[]){
    LL res=-1;
    int n=SZ(v[0])+SZ(v[1]);
    n<<=1;
    REP(round,2){
        set<int>H;
        map<int,LL>mi;
        REP(k,2){
            REP(i,SZ(v[k])){
                int me=v[k][i]*inv[round]%sz[round];
                if(k==round)H.insert(me);
                mii(mi,(me+sz[round]-1)%sz[round],INF);
                mii(mi,me,v[k][i]*gg.z);
            }
        }

        LL now=INF;
        proccess(now,mi,round);
        proccess(now,mi,round);
        set<int>::iterator it1=H.begin();
        map<int,LL>::iterator it2=mi.begin();
        while(it2!=mi.end()){
            while(it1!=H.end()&&*it1<it2->F)it1++;
            if(it1==H.end()||*it1!=it2->F)res=max(res,it2->S);
            it2++;
        }
    }
    if(res==-1)return -INF;
    return res;
}
int main(){
    RII(n,m);
    gg=gcd(n,m);
    if(gg.z>100000){
        puts("-1");
        return 0;
    }
    sz[0]=n/gg.z;
    sz[1]=m/gg.z;
    inv[1]=(gg.x%sz[1]+sz[1])%sz[1];
    inv[0]=(gg.y%sz[0]+sz[0])%sz[0];
    REP(k,2){
        DRI(m);
        REP(i,m){
            DRI(x);
            d[x%gg.z][k].PB(x/gg.z);
        }
    }
    REP(i,gg.z){
        if(SZ(d[i][0])+SZ(d[i][1])==0){
            puts("-1");
            return 0;
        }
    }
    LL an=0;
    REP(i,gg.z){
        an=max(an,f(d[i])+i);
    }
    cout<<an<<endl;
    return 0;
}