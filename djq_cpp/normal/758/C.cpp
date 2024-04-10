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
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
int n,m,x,y;
ll vis[105][105];
ll T,rnd;
int main(){
	scanf("%d%d%I64d%d%d",&n,&m,&T,&x,&y);
	if(n==1)rnd=ll(m);
	else rnd=ll(n-1)*2ll*ll(m);
	ll rs=T/rnd;
	T%=rnd;
	for(int i=1;i<=n;i++)rep1(j,m)vis[i][j]+=rs;
	for(int i=n-1;i>1;i--)rep1(j,m)vis[i][j]+=rs;
	for(int i=1;i<=n;i++){
		if(T==0ll)break;
		rep1(j,m){
			if(T==0ll)break;
			T--;
			vis[i][j]++;
		}
	}
	for(int i=n-1;i>1;i--){
		if(T==0ll)break;
		rep1(j,m){
			if(T==0ll)break;
			T--;
			vis[i][j]++;
		}
	}
	ll MAX=0,MIN=1000000000000000007ll;
	rep1(i,n)rep1(j,m){
		MAX=max(MAX,vis[i][j]);
		MIN=min(MIN,vis[i][j]);
	}
	printf("%I64d %I64d %I64d",MAX,MIN,vis[x][y]);
	return 0;
}