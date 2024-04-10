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
const int SIZE = 1e6+10;
// template end here
LL d[SIZE][2];
struct data{
    LL x,y;
    int id;
    data(LL _x=0,LL _y=0,int _id=0):x(_x),y(_y),id(_id){}
    bool operator<(const data& b)const{return x<b.x||(x==b.x&&y<b.y);}
}gg[SIZE];
int gn;
int an[SIZE];
void print_array(int arr[],int n){
    REP(i,n){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
int main(){
    DRII(n,m);
    REP(i,n)
        REP(j,2)cin>>d[i][j];
    REPP(i,1,n){
        gg[gn++]=data(d[i][0]-d[i-1][1],d[i][1]-d[i-1][0],i-1);
    }
    REP(i,m){
        LL x;
        cin>>x;
        gg[gn++]=data(x,3e18,i+1);
    }
    sort(gg,gg+gn);
    priority_queue<pair<LL,int> >qq;
    REP(i,gn){
        if(gg[i].y!=3e18){
            qq.push(MP(-gg[i].y,gg[i].id));
        }
        else{
            if(!qq.empty()){
                pair<LL,int>now=qq.top();
                if(-now.F>=gg[i].x){
                    an[now.S]=gg[i].id;
                    qq.pop();
                }
            }
        }
    }
    if(!qq.empty()){
        puts("No");
        return 0;
    }
    puts("Yes");
    print_array(an,n-1);
    return 0;
}