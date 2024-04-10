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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<17;
VI e[SIZE];
VI lv[SIZE];
int ma_lv;
VI ww[SIZE];
VI gg[SIZE];
int g_sz[SIZE];
int g_id;
int d[SIZE];
int p[SIZE];
int n,X;
bitset<50001>dp[10000];
bitset<50001>from[10000];
void dfs(int x){
    lv[d[x]].PB(x);
    ma_lv=max(ma_lv,d[x]);
    for(int y:e[x]){
        d[y]=d[x]+1;
        dfs(y);
    }
}
char an[SIZE];
void solve() {
    dfs(1);
    FOR(i,0,n){
        if(SZ(lv[i])){
            ww[SZ(lv[i])].PB(i);
        }
        else break;
    }
    FOR(i,1,n){
        int num=SZ(ww[i]);
        int it=0;
        int now=1;
        while(num>0){
            int me=min(now,num);
            num-=me;
            g_sz[g_id]=me*i;
            REP(j,me){
                gg[g_id].PB(ww[i][it++]);
            }
            g_id++;
            now*=2;
        }
    }
    int need=min(X,n-X);
    dp[0][0]=1;
    int rr=0;
    REP(i,g_id){
        FOR(j,0,rr){
            if(dp[i][j]){
                dp[i+1][j]=1;
                from[i+1][j]=0;
                if(j+g_sz[i]<=need){
                    dp[i+1][j+g_sz[i]]=1;
                    from[i+1][j+g_sz[i]]=1;
                }
            }
        }
        rr=min(rr+g_sz[i],need);
    }
    if(dp[g_id][need]){
        W(ma_lv+1);
        char my_c='a',your_c='b';
        if(X!=need){
            swap(my_c,your_c);
        }
        REP(i,n)an[i]=your_c;
        int x=g_id;
        int y=need;
        while(x){
            if(from[x][y]){
                for(int lv_id: gg[x-1]){
                    for(int node_id: lv[lv_id]){
                        an[node_id-1]=my_c;
                    }
                }
                y-=g_sz[x-1];
            }
            x--;
        }
    }else{
        W(ma_lv+2);
        int lv_id=0;
        int Y=n-X;
        int r_num[2]={X,Y};
        while(SZ(lv[lv_id])){
            char my_c=0;
            char more_c;
            if(SZ(lv[lv_id])<=r_num[0]){
                my_c='a';
            }else if(r_num[1]>=SZ(lv[lv_id])){
                my_c='b';
            } else {
                if(r_num[0] < r_num[1]) {
                    more_c = 'b';
                } else{
                    more_c = 'a';
                }
            }
            for(int node_id: lv[lv_id]){
                if(my_c){
                    an[node_id-1]=my_c;
                }else{
                    if(SZ(e[node_id])>0){
                        if(r_num[more_c-'a']>0){
                            an[node_id-1]=more_c;
                        }else{
                            an[node_id-1]=more_c^'a'^'b';
                        }
                    }else{
                        if(r_num[1-(more_c-'a')]>0){
                            an[node_id-1]=more_c^'a'^'b';
                        }else{
                            an[node_id-1]=more_c;
                        }
                    }
                }
                r_num[an[node_id-1]-'a']--;
            }
            lv_id++;
        }
    }
    puts(an);
}
void input() {
    R(n,X);
    FOR(i,2,n){
        R(p[i]);
        e[p[i]].PB(i);
    }
}
int main(){
    input();
    solve();
    return 0;
}