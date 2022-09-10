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
const int MID = 5000;
const double EPS=1e-15;
const int SIZE = 1e6+10;
// template end here
vector<int>e[SIZE];
struct data{
    int x,y;
    double v;
    data(int _x=0,int _y=0,double _v=0):x(_x),y(_y),v(_v){}
    bool operator<(const data& b)const{return x<b.x||(x==b.x&&y>b.y);}
    bool in(const data& b){return x<=b.x&&b.y<=y;}
}d[SIZE];
int a[SIZE],stk[SIZE],sn;
double dp[5001][10001];
bool used[5001];
set<int>H;
int ma;
void clr(int x){
    int L=d[x].x,R=d[x].y;
    double p=d[x].v;
    set<int>::iterator st=H.lower_bound(L);
    set<int>::iterator ed;
    int me=0;
    for(ed=st;ed!=H.end()&&*ed<=R;ed++){
        me=max(me,a[*ed]);
    }
    H.erase(st,ed);
    me-=ma;
    me+=5000;
    for(int i=10000;i>=0;i--){
        double v=dp[x][i];
        dp[x][i]=0;
        if(v>EPS){
            dp[x][max(i,me)+1]+=v*p;
            dp[x][max(i,me)]+=v*(1-p);
        }
    }
}
void add(int x,int y){
    double p1=0,p2=0;
    REP(i,10001){
        double tmp=1-p1*p2;
        p1+=dp[x][i];
        p2+=dp[y][i];
        dp[x][i]=tmp;
        if(i)dp[x][i-1]-=tmp;
    }
}
void dfs(int x){
    REP(i,SZ(e[x])){
        int y=e[x][i];
        dfs(y);
        add(x,y);
    }
    clr(x);
}
int main(){
    DRII(n,q);
    REP(i,n)H.insert(i);
    REP(i,n){
        RI(a[i]);
        ma=max(ma,a[i]);
    }
    REP(i,q){
        int x,y;
        double v;
        scanf("%d%d%lf",&x,&y,&v);
        d[i]=data(x-1,y-1,v);
    }
    d[q++]=data(0,n-1,0);
    REP(i,q)dp[i][0]=1;
    sort(d,d+q);
    REP(i,q){
        while(sn&&d[stk[sn-1]].y<d[i].x)
            sn--;
        if(i)e[stk[sn-1]].PB(i);
        stk[sn++]=i;
    }
    dfs(stk[0]);
    double an=0;
    REPP(i,MID,MID*2+1){
        an+=(ma+i-MID)*dp[stk[0]][i];
    }
    printf("%.15f\n",an);
    return 0;
}