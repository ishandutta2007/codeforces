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
bool G[15][15];
long long dp[1024][1024];
int main(){
	int n,m,u,v,t;
	scanf("%d%d%d",&n,&m,&t);
	rep(k,m){
		scanf("%d%d",&u,&v);u--;v--;
		G[u][v]=G[v][u]=true;
	}
	for(int k=1;k<n;k++)if(G[0][k])dp[1+(1<<k)][1+(1<<k)]=1LL;
	rep(i,1<<n)rep(j,1<<n){
		if((i&j)!=j)continue;
		rep(k,n){
			if(!(i>>k&1))continue;
			int nj=j&(~(1<<k));
			rep(l,n){
				if(!G[k][l]||(1<<l)<nj||(i>>l)&1)continue;
				dp[i|1<<l][nj|1<<l]+=dp[i][j];
			} 
		}
	}
	long long ans=0LL;
	rep(i,1<<n){
		int cnt=0;
		rep(k,n)if(i>>k&1)cnt++;
		if(cnt==t)ans+=dp[(1<<n)-1][i];
	}
	printf("%I64d\n",ans);
	return 0;
}