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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
map<string,int>H;
map<PII,int>road;
int id=0;
int add(string s){
    if(H.count(s))return H[s];
    return H[s]=id++;
}
int rid;
int get_road(int x,int y){
    if(road.count(MP(x,y)))return road[MP(x,y)];
    return road[MP(y,x)]=road[MP(x,y)]=rid++;
}
int score[SIZE];
int main(){
    DRIII(n,a,b);DRII(k,f);
    int lt=-1;
    int an=0;
    REP(i,n){
        string s1,s2;
        cin>>s1>>s2;
        int x=add(s1);
        int y=add(s2);
        int r=get_road(x,y);
        int v=0;
        if(lt==x)v=b;
        else v=a;
        score[r]+=v;
        an+=v;
        lt=y;
    }
    sort(score,score+rid,greater<int>());
    REP(i,min(k,rid))an-=max(0,score[i]-f);
    return 0*printf("%d\n",an);
}