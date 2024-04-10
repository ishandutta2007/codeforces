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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE][3];
struct data{
    int base,dy,dz,lose;
    data(int _base,int _dy,int _dz,int _lose):base(_base),dy(_dy),dz(_dz),lose(_lose){}
    bool operator<(const data& b)const{
        return dy<b.dy||(dy==b.dy&&dz<b.dz)||(dy==b.dy&&dz==b.dz&&base>b.base);
    }
};
string str[3]={"MW","LW","LM"};
int ST;
void get(vector<data>& q,int x,int n,int base,int dy,int dz,LL from){
    if(x==n){
        q.PB(data(base,dy,dz,from));
        return;
    }
    get(q,x+1,n,base+a[x][0],dy+a[x][1]-a[x][0],dz-a[x][0],from|(2LL<<(2*(x-ST))));
    get(q,x+1,n,base+a[x][0],dy-a[x][0],dz+a[x][2]-a[x][0],from|(1LL<<(2*(x-ST))));
    get(q,x+1,n,base,dy+a[x][1],dz+a[x][2],from);
}
int main(){
    DRI(n);
    REP(i,n){
        REP(j,3)RI(a[i][j]);
    }
    vector<data>q[2];
    ST=0;
    get(q[0],0,n/2,0,0,0,0);
    ST=n/2;
    get(q[1],n/2,n,0,0,0,0);
    REP(i,SZ(q[1])){
        q[1][i].dy=-q[1][i].dy;
        q[1][i].dz=-q[1][i].dz;
    }
    REP(i,2)sort(ALL(q[i]));
    int it=0;
    PLL good;
    int ma=-INF;
    REP(i,SZ(q[0])){
        while(it<SZ(q[1])&&MP(q[1][it].dy,q[1][it].dz)<MP(q[0][i].dy,q[0][i].dz))it++;
        if(it<SZ(q[1])&&MP(q[1][it].dy,q[1][it].dz)==MP(q[0][i].dy,q[0][i].dz)){
            if(q[0][i].base+q[1][it].base>ma){
                ma=q[0][i].base+q[1][it].base;
                good=MP(q[0][i].lose,q[1][it].lose);
            }
        }
    }
    if(ma==-INF)puts("Impossible");
    else{
        int res[3]={};
        REP(i,n/2){
            int me=(good.F>>(i*2))&3;
            cout<<str[me]<<endl;
            REP(j,3){
                if(me==j)continue;
                res[j]+=a[i][j];
            }

        }
        REPP(i,n/2,n){
            int me=(good.S>>((i-n/2)*2))&3;
            cout<<str[me]<<endl;
            REP(j,3){
                if(me==j)continue;
                res[j]+=a[i][j];
            }
        }
    }
    return 0;
}