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
int a[2500][2500];
struct EDGE{
    int x,y,v;
    EDGE(int _x=0,int _y=0,int _v=0):x(_x),y(_y),v(_v){}
    bool operator<(const EDGE& b)const{return v<b.v;}
}e[6250000];
int en;
struct Union_Find{
    int d[SIZE],num[SIZE],v[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,v[i]=0;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        v[x]++;
        if(x==y)return 0;
        if(num[x]<=num[y]){
            num[y]+=num[x];
            d[x]=y;
            v[y]+=v[x];
        }
        else{
            num[x]+=num[y];
            d[y]=x;
            v[x]+=v[y];
        }
        return 1;
    }
}U;
template<class T>
inline void read(T &x) {
	char c;int f = 1;x = 0;
	while(((c = getchar()) < '0' || c > '9') && c != '-');
	if(c == '-') f = -1;else x = c - '0';
	while((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
	x *= f;
}
int v[2500];
int id;
VPII d[2500];
map<int,int>H;
int n;
int add(int x){
    if(H.count(x))return H[x];
    if(id==n){
        puts("NOT MAGIC");
        exit(0);
    }
    v[id]=x;
    return H[x]=id++;
}
int main(){
    read(n);
    U.init(n);
    REP(i,n){
        REP(j,n){
            read(a[i][j]);
            if(i>j&&a[i][j]!=a[j][i])return 0*puts("NOT MAGIC");
            else if(i<j)d[add(a[i][j])].PB(MP(i,j));
        }
        if(a[i][i])return 0*puts("NOT MAGIC");
    }
    VPII pp;
    REP(i,id)pp.PB(MP(v[i],i));
    sort(ALL(pp));
    REP(i,id){
        int x=pp[i].S;
        REP(j,SZ(d[x])){
            U.uu(d[x][j].F,d[x][j].S);
        }
        REP(k,n){
            if(U.d[k]==k){
                if(U.num[k]*(U.num[k]-1)/2!=U.v[k])return 0*puts("NOT MAGIC");
            }
        }
    }
    return 0*puts("MAGIC");
}