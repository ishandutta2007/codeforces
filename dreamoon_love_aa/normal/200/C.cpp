/*{{{*/
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int pt[4],score[4],miss[4];
int player2;
string names[4];
bool cmp(int x,int y){
    if(pt[x]!=pt[y])return pt[x]<pt[y];
    if(score[x]-miss[x]!=score[y]-miss[y])return score[x]-miss[x]<score[y]-miss[y];
    if(score[x]!=score[y])return score[x]<score[y];
    return names[x]>names[y];
}
bool test(int x,int y){
    score[player2]+=y;
    miss[player2]+=x;
    miss[0]+=y;
    score[0]+=x;
    int d[4]={0,1,2,3};
    sort(d,d+4,cmp);
    score[player2]-=y;
    score[0]-=x;
    miss[player2]-=x;
    miss[0]-=y;
    return d[2]==0||d[3]==0;
}
map<string,int>name;
int _id;
int get(string s){
    if(name.count(s))return name[s];
    names[_id+1]=s;
    return name[s]=++_id;
}
int main(){
    names[0]="BERLAND";
    name["BERLAND"]=0;
    int cnt[4]={};
    REP(i,5){
        char s[24],t[24];
        RS(s);
        RS(t);
        int id[2]={get(s),get(t)};
        int x,y;
        scanf("%d:%d",&x,&y);
        cnt[id[0]]++;
        cnt[id[1]]++;
        if(x>y){
            pt[id[0]]+=3;
        }
        else if(x==y){
            pt[id[0]]++;
            pt[id[1]]++;
        }
        else{
            pt[id[1]]+=3;
        }
        score[id[0]]+=x;
        miss[id[0]]+=y;
        score[id[1]]+=y;
        miss[id[1]]+=x;
    }
    REPP(i,1,4){
        if(cnt[i]==2)player2=i;
    }
    pt[0]+=3;
    FOR(i,1,50){
        FOR(j,0,50){
            if(test(i+j,j)){
                printf("%d:%d\n",i+j,j);
                return 0;
            }
        }
    }
    W("IMPOSSIBLE");
    return 0;
}