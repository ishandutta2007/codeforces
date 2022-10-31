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
using namespace std;
#define pb push_back
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 100006
int a[N], b[N], A[N], B[N], mozna[N],
ar[N], br[N], Ar[N], Br[N];

int main () {
	wez(n)
	FORI(i,n) scanf("%d",a+i);
	FORI(i,n) scanf("%d",b+i);
	
	A[0] = B[0] = 0;
	int mi = INF+6;
	FORI(i,n) {
		mozna[i] = 0;
		A[i] = A[i-1] + a[i];
		B[i] = B[i-1] + b[i];
		REMIN(mi, A[i] - B[i]);
	}

	FORI(i,n) {
		int prev = i-1;
		if (prev == 0) prev = n;
		if (A[prev] - B[prev] == mi) mozna[i] = 1;
	}
	
	// w druga strone
	FORI(i,n) ar[i] = a[n+1-i];
	FORI(i,n-1) br[i] = b[n-i];
	br[n] = b[n];

	Ar[0] = Br[0] = 0;
	int mir = INF+6;
	FORI(i,n) {
		Ar[i] = Ar[i-1] + ar[i];
		Br[i] = Br[i-1] + br[i];
		REMIN(mir, Ar[i] - Br[i]);
	}
	
	FORI(i,n) {
		int prev = i-1;
		if (prev == 0) prev = n;
		if (Ar[prev] - Br[prev] == mir) mozna[n+1-i] = 1;
	}	
	
	pisz(count(mozna+1,mozna+n+1,1));
	FORI(i,n) if (mozna[i]) printf("%d ",i);
}