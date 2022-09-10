/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
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
#define PB push_back
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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
struct PalindromicTree{
    int n;
    char str[SIZE];
    int nxt[SIZE][26];
    int len[SIZE];
    int par[SIZE];
    int slink[SIZE];
    int diff[SIZE];
    int top;
    int now;
    void build(char s[],int _n){
        n=_n;
        FOR(i,0,n)str[i]=s[i];
        par[0]=top=1;
        len[0]=now=0;
        len[1]=-1;
    }
    int create_node(int v){
        len[++top]=v;
        MS0(nxt[top]);
        return top;
    }
    void extend(int pos){
        char c=str[pos];
        while(str[pos-len[now]-1]!=c){
            now=par[now];
        }
        if(!nxt[now][c-'a']){
            int new_node_id=create_node(len[now]+2);
            int tmp=now;
            do tmp=par[tmp]; while (str[pos-len[tmp]-1]!=c);
            par[new_node_id]=nxt[tmp][c-'a'];
            nxt[now][c-'a']=new_node_id;
            diff[new_node_id]=len[new_node_id]-len[par[new_node_id]];
            slink[new_node_id]=(diff[new_node_id]==diff[par[new_node_id]])?slink[par[new_node_id]]:par[new_node_id];
        }
        now=nxt[now][c-'a'];
    }
    int mi[SIZE],_from[SIZE],from[SIZE];
    void solve(){
        mi[0]=0;
        FOR(i,1,n){
            mi[i]=1e9;
            extend(i);
            for(int me=now;me;me=slink[me]){
                _from[me]=i-(len[slink[me]]+diff[me]);
                if(diff[par[me]]==diff[me]&&mi[_from[me]]>mi[_from[par[me]]]){
                    _from[me]=_from[par[me]];
                }
                if(!(i&1)&&mi[i]>mi[_from[me]]+1){
                    mi[i]=mi[_from[me]]+1;
                    from[i]=_from[me];
                }
            }
            if(!(i&1)&&str[i]==str[i-1]&&mi[i]>mi[i-2]){
                mi[i]=mi[i-2];
                from[i]=i-2;
            }
        }
        if(mi[n]<1e9){
            printf("%d\n",mi[n]);
            for(int x=n;x;x=from[x]){
                if(x-2!=from[x])printf("%d %d\n",(from[x]+2)/2,x/2);
            }
        }
        else W("-1");
    }
}tree;
char s2[SIZE],s[SIZE];
int main(){
    RS(s2);
    int n=LEN(s2);
    RS(s2+n);
    {
        int it=1;
        REP(i,n){
            s[it++]=s2[i];
            s[it++]=s2[i+n];
        }
    }
    tree.build(s,2*n);
    tree.solve();
    return 0;
}