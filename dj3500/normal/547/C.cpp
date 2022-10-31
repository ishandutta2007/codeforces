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

const int N = 500500;
vi pd[N];//, divs[N];
vi realdivs[N];
int equiv[N];
int w[N], a[N];
bool active[N];

int main () {
    IOS
    for (int x = 2; x <= 500000; ++x) {
        if (pd[x].empty()) {
            for (int y = x; y <= 500000; y += x) {
                pd[y].pb(x);
            }
        }
        /*for (int y = x; y <= 500000; y += x) {
            divs[y].pb(x);
        }*/
    }
    for (int x = 1; x <= 500000; ++x) {
        equiv[x] = 1;
        FOREACH(p,pd[x]) equiv[x] *= *p;
        if (equiv[x] == x) {
            for (int y = x; y <= 500000; y += x) realdivs[y].pb(x);
        }
    }
    /*REP(x,1,40) if (x == equiv[x]) {
        DBG(x)
        DBG(realdivs[x])
        DBG(pd[x])
    }*/
    int n, q;
    cin >> n >> q;
    FORI(i,n) cin >> a[i];
    ll ans = 0;
    while (q--) {
        int i;
        cin >> i;
        bool ac = active[i];
        int x = equiv[a[i]];

        if (ac) {
            // usuwam
            active[i] = 0;
            FOREACH(it,realdivs[x]) w[*it]--;
        }

        ll delta = 0;
        FOREACH(it,realdivs[x]) delta += w[*it] * ((SZ(pd[*it]) % 2 == 0) ? 1 : -1);

        if (!ac) {
            // dodaje
            active[i] = 1;
            FOREACH(it,realdivs[x]) w[*it]++;
            ans += delta;
        } else {
            ans -= delta;
        }

        cout << ans << "\n";
    }
}