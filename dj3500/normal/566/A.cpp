// tested by Hightail: https://github.com/dj3500/hightail
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 1001007;
char buf[N];
string a[N], b[N];
vector<pii> res;

int lcp (const string &s, const string &t) {
    int i;
    for (i = 0; i < SZ(s) && i < SZ(t) && s[i] == t[i]; ++i);
    return i;
}

pair<vi,vi> go (const vi &va, const vi &vb, int k) {
    vi ta, tb;
    //vi kubela[26], kubelb[26];
    FOREACH(it,va) {
        if (k < SZ(a[*it])) {
            //kubela[a[*it][k] - 'a'].pb(*it);
        } else {
            ta.pb(*it);
        }
    }
    FOREACH(it,vb) {
        if (k < SZ(b[*it])) {
            //kubelb[b[*it][k] - 'a'].pb(*it);
        } else {
            tb.pb(*it);
        }
    }
    FOR(c,26) {
        //if ((!kubela[c].empty()) || (!kubelb[c].empty())) {
        vi kubelac, kubelbc;
        FOREACH(it,va) if (k < SZ(a[*it]) && a[*it][k] == 'a'+c) kubelac.pb(*it);
        FOREACH(it,vb) if (k < SZ(b[*it]) && b[*it][k] == 'a'+c) kubelbc.pb(*it);
        if (kubelac.empty() && kubelbc.empty()) continue;
        pair<vi,vi> p = go(kubelac, kubelbc, k+1);
        ta.insert(ta.begin(), ALL(p.fi));
        tb.insert(tb.begin(), ALL(p.se));
    }
    while (!ta.empty() && !tb.empty()) {
        res.pb(mp(ta.back(), tb.back()));
        ta.pop_back();
        tb.pop_back();
    }
    return mp(ta,tb);
}

int main () {
   wez(n)
   FORI(i,n) {
       scanf("%s", buf);
       a[i] = buf;
   }
   FORI(i,n) {
       scanf("%s", buf);
       b[i] = buf;
   }
   vi v;
   FORI(i,n) v.pb(i);
   go(v, v, 0);
   int ans = 0;
   FOREACH(it,res) ans += lcp(a[it->fi], b[it->se]);
   pisz(ans);
   FOREACH(it,res) printf("%d %d\n", it->fi, it->se);
}