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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll MOD=1e9+7;
int nxt[200005],vis[200005];
vector<int> cyc;
ll pow_mod(int k){
	ll a=1ll,x=2ll;
	while(k){
		if(k&1)a=(a*x)%MOD;
		x=(x*x)%MOD;
		k>>=1;
	}
	return a;
}
void dfs(int id,int &poi){
	if(vis[id]==-1)cyc.push_back(id);
	if(vis[id]!=0)return;
	poi++;
	vis[id]=-1;
	dfs(nxt[id],poi);
	vis[id]=1;
}
int main(){
	int n,p=0,u;
	ll ans=1ll;
	scanf("%d",&n);u=n;
	rep(k,n){
		scanf("%d",&nxt[k]);
		nxt[k]--;
	}
	rep(k,n)if(vis[k]==0)dfs(k,p);
	rep(k,n)vis[k]=0;
	for(int k=cyc.size()-1;k>=0;k--){
		p=0;dfs(cyc[k],p);u-=p;
		ll cur=(pow_mod(p)+MOD-2ll)%MOD;
		ans=(ans*cur)%MOD;
	}
	ans=(ans*pow_mod(u))%MOD;
	printf("%I64d",ans);
	return 0;
}