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
struct Point{
    LL x,y,z;
    Point(LL _x=0,LL _y=0,LL _z=0){x=_x;y=_y;z=_z;}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y,z-b.z);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y,z+b.z);}
    Point operator*(const LL v){return Point(x*v,y*v,z*v);}
    Point operator/(const LL v){return Point(x/v,y/v,z/v);}
    LL dis(){return x*x+y*y+z*z;}
}p[8];
int d[8][3];
vector<Point>a[8];
void check(){
    VI v;
    Point mm(0,0,0);
    map<LL,int>H;
    REP(i,8){
        mm=mm+p[i];
        REP(j,i){
            H[(p[i]-p[j]).dis()]++;
            if(SZ(H)>3)return;
        }
    }
    if(SZ(H)<3)return;
    mm=mm/8;
    LL l=(p[0]-mm).dis();
    REPP(i,1,8){
        if((p[i]-mm).dis()!=l)return;
    }
    map<LL,int>::iterator it=H.begin();
    pair<LL,int>p1=*it;
    it++;
    pair<LL,int>p2=*it;
    it++;
    pair<LL,int>p3=*it;
    if(l*4!=p3.F)return;
    if(p1.S!=12)return;
    if(p2!=MP(p1.F*2,12))return;
    if(p3!=MP(p1.F*3,4))return;
    puts("YES");
    REP(i,8)printf("%I64d %I64d %I64d\n",p[i].x/2,p[i].y/2,p[i].z/2);
    exit(0);
}
void dfs(int x){
    if(x==8){
        check();
        return;
    }
    REP(i,SZ(a[x])){
        p[x]=a[x][i];
        dfs(x+1);
    }
}
int main(){
    REP(i,8)REP(j,3)RI(d[i][j]);
    REP(i,8){
        sort(d[i],d[i]+3);
        REP(j,3)d[i][j]*=2;
        do{
            a[i].PB(Point(d[i][0],d[i][1],d[i][2]));
        }while(next_permutation(d[i],d[i]+3));
    }
    dfs(0);
    puts("NO");
    return 0;
}