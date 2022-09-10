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
const LL MAX = 1LL<<31;
const int SIZE = 1e6+10;
map<LL,int>BIT;
void ins(LL x,int v){
    x+=MOD;
    for(;x<MAX;x+=x&-x)BIT[x]+=v;
}
int qq(LL x){
    int res=0;
    x+=MOD;
    for(;x;x-=x&-x)
        if(BIT.count(x))res+=BIT[x];
    return res;
}
struct data{
    int x,v1,v2;
    data(int _x=0,int _v1=0,int _v2=0):x(_x),v1(_v1),v2(_v2){}
    bool operator<(const data& b)const{
        return x<b.x||(x==b.x&&v1<b.v1);
    }
}d[SIZE];
LL fix(vector<data> &V){
    LL ret=0;
    sort(ALL(V));
    int it=0;
    REP(i,SZ(V)){
        int ma=V[i].v2;
        int j;
        for(j=i+1;j<SZ(V)&&V[j].x==V[i].x&&V[j].v1<=ma+1;j++)
            ma=max(ma,V[j].v2);
        V[it]=data(V[i].x,V[i].v1,ma);
        ret+=ma-V[i].v1+1;
        it++;
        i=j-1;
    }
    V.resize(it);
    return ret;
}
int main(){
    DRI(n);
    vector<data>V,H;
    REP(i,n){
        DRII(x1,y1);
        DRII(x2,y2);
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        if(x1==x2){
            V.PB(data(x1,y1,y2));
        }
        else{
            H.PB(data(y1,x1,x2));
        }
    }
    LL an=0;
    an+=fix(V);
    an+=fix(H);
    int dn=0;
    REP(i,SZ(V)){
        d[dn++]=data(V[i].v1,1,V[i].x);
        d[dn++]=data(V[i].v2+1,2,V[i].x);
    }
    REP(i,SZ(H)){
        d[dn++]=data(H[i].x,3,H[i].v2);
        d[dn++]=data(H[i].x,4,H[i].v1-1);
    }
    sort(d,d+dn);
    REP(i,dn){
        if(d[i].v1==1)ins(d[i].v2,1);
        else if(d[i].v1==2)ins(d[i].v2,-1);
        else if(d[i].v1==3)an-=qq(d[i].v2);
        else if(d[i].v1==4)an+=qq(d[i].v2);
    }
    cout<<an<<endl;
    return 0;
}