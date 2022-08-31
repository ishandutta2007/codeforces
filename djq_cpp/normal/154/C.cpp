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
ll power(ll ori,int p){
	if(p==0)return 1LL;
	ll res=power(ori,p>>1);
	return (p&1)?(res*res*ori):(res*res);
}
int n,m,x[1000005],y[1000005];
ll H[1000005];
map<ll,int> Hsz;
ll solve(ll HASH){
	rep(k,n)H[k]=0LL;
	rep(k,m){
		H[x[k]]+=power(HASH,y[k]);
		H[y[k]]+=power(HASH,x[k]);
	}
	Hsz.clear();
	rep(k,n)Hsz[H[k]]++;
	ll ans=0LL;
	for(map<ll,int>::iterator it=Hsz.begin();it!=Hsz.end();it++){
		int cur=it->second;
		ans+=((ll(cur)*ll(cur-1))>>1);
	}
	rep(k,m)
	if(H[x[k]]-power(HASH,y[k])==H[y[k]]-power(HASH,x[k]))
	ans++;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(k,m){
		scanf("%d%d",&x[k],&y[k]);
		x[k]--;y[k]--;
	}
	printf("%I64d",solve(1723333LL));
	return 0;
}