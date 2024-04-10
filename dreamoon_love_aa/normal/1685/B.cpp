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
#include<iomanip>
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
#define CASET int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
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
template<class T,class U> void _R(pair<T,U> &x) {cin >> x.F >> x.S;}
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {_R(head); R(tail...);}
template<class T> void _W(const T &x) {cout << x;}
void _W(const double &x) {cout << fixed << setprecision(16) << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); cout << ' '; _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) cout << ' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {cout << "[DEBUG] "; W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int a,b,c,d,n;
string s;
void solve() {
    n=SZ(s);
    int cnt[2]={};
    REP(i,n){
        cnt[s[i]-'A']++;
    }
    if(cnt[0]!=a+c+d||cnt[1]!=b+c+d){
        W("NO");
        return;
    }
    int AA=0;
    VI sp[2];
    for(int i=0,j;i<n-1;i=j){
        if(s[i]==s[i+1]){
            j=i+1;
            continue;
        }
        for(j=i+1;j<n&&s[j]!=s[j-1];j++);
        int num=j-i;
        if(num&1){
            AA+=num/2;
        }else{
            if(s[i]=='A'){
                sp[0].PB(num/2);
            }else{
                sp[1].PB(num/2);
            }
        }
    }
    int tmp[2]={c,d};
    REP(i,2){
        sort(ALL(sp[i]),greater<int>());
        while(tmp[i]>0&&SZ(sp[i])){
            int mi=min(sp[i].back(),tmp[i]);
            tmp[i]-=mi;
            sp[i].back()-=mi;
            if(sp[i].back()==0)sp[i].pop_back();
        }
        int mi=min(tmp[i],AA);
        AA-=mi;
        tmp[i]-=mi;
    }
    REP(i,2){
        if(tmp[i]){
            for(auto &x: sp[i^1])x--;
            while(tmp[i]>0&&SZ(sp[i^1])){
                int mi=min(sp[i^1].back(),tmp[i]);
                tmp[i]-=mi;
                sp[i^1].back()-=mi;
                if(sp[i^1].back()==0)sp[i^1].pop_back();
            }
            if(tmp[i]>0){
                W("NO");
                return;
            }
        }
    }
    W("YES");
}
void input() {
    R(a,b,c,d);
    R(s);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    CASET {
        input();
        solve();
    }
    return 0;
}