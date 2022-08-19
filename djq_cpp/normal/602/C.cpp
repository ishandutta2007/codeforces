#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <conio.h>
#include <memory.h>
#include <windows.h>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define open_in(n) freopen(n,"r",stdin)
#define open_out(n) freopen(n,"w",stdout)
#define debug(x) cerr<<#x<<'='<<x<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define REPup(i,m,n) for(int i=(m);i<=(n);i++)
#define REPdn(i,m,n) for(int i=(m);i>=(n);i--)
#define FOR(i,m,n,t) for(int i=(m);((t)>0)?(i<=(n)):(i>=(n));i+=t)
#define for_all(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
#define ALL(n) n.begin,n.end
#define SIZE(n) (int)((n).size())
#define PB push_back
#define MP make_pair
#define IT iterator
#define ST first
#define ND second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf=1e9+7;
const long long linf=1e17+7;
const double eps=1e-9;
template<typename T>T max(T a,T b) {
	return a>b?a:b;
}
template<typename T>T min(T a,T b) {
	return a<b?a:b;
}
template<typename T>T abs(T n) {
	return n>(T)(0)?n:-n;
}
template<typename T>void swap(T &a,T &b) {
	T t=a;
	a=b;
	b=t;
}
double diagonal(double x,double y) {
	return sqrt((x)*(x)+(y)*(y));
}
bool adj[405][405],iftr;
bool vis[405];
int n;
int bfs(int beg) {
	queue<pii>que;
	vis[beg]=true;
	que.push(MP(beg,0));
	while(!que.empty()) {
		pii out=que.front();
		if(out.ST==n)return out.ND;
		que.pop();
		REPup(k,1,n)
		if(iftr==adj[out.ST][k]&&k!=out.ST&&!vis[k]) {
			vis[k]=true;
			que.push(MP(k,out.ND+1));
		}
	}
	return -1;
}
int main() {
	int m,x,y;
	scanf("%d%d",&n,&m);
	rep(k,m) {
		scanf("%d%d",&x,&y);
		adj[x][y]=adj[y][x]=true;
	}
	iftr=!adj[1][n];
	printf("%d",bfs(1));
	return 0;
}