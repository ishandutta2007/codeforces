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

const int mod = 1000000007;
#define NEED 4004
ll nt[NEED+1][NEED+1];

void initnewton () {
	FOR(n,NEED+1) nt[n][0] = 1;
	FORI(k,NEED) nt[0][k] = 0;
	FORI(n,NEED) FORI(k,NEED) nt[n][k] = (nt[n-1][k-1] + nt[n-1][k]) % mod;
}

ll dp[NEED], dow[NEED];

int main () {
    initnewton();
    wez(N);
    dp[0] = 0;
    dow[0] = 1;
    REP(n,1,N) {
        dp[n] = dow[n-1];
        dow[n] = dow[n-1];
        REP(k,1,n) {
            dp[n] += dp[n-k] * nt[n-1][k-1] % mod;
            dow[n] += dow[n-k] * nt[n-1][k-1] % mod;
        }
        dp[n] %= mod;
        dow[n] %= mod;
    }
    int res = dp[N] % mod;
    if (res < 0) res += mod;
    pisz(res);
}