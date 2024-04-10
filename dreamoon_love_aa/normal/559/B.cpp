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
char s[SIZE];
int d[SIZE];
int id[SIZE];
int ww;
bool compare(int x,int y){
    return strncmp(s+x*ww,s+y*ww,ww)<0;
}
map<PII,int>H;
int now;
int get(int L,int R){
    if(L==R)return id[L];
    int mm=(L+R)>>1;
    PII me=MP(get(L,mm),get(mm+1,R));
    if(me.F>me.S)swap(me.F,me.S);
    if(H.count(me))return H[me];
    return H[me]=++now;
}
int main(){
    RS(s);
    int n=LEN(s);
    RS(s+n);
    int two=1;
    while(n%(two*2)==0)two<<=1;
    ww=n/two;
    REP(i,two*2)d[i]=i;
    sort(d,d+two*2,compare);
    now=0;
    REP(i,two*2){
        if(!i||strncmp(s+ww*d[i],s+ww*d[i-1],ww))id[d[i]]=++now;
        else id[d[i]]=now;
    }
    puts(get(0,two-1)==get(two,two*2-1)?"YES":"NO");
    return 0;
}