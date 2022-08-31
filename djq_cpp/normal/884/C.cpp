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
bool vis[100005];
int cnt,to[100005];
vector<int> C;
void dfs(int v){
	if(vis[v])return;
	cnt++;
	vis[v]=true;
	dfs(to[v]);
}
int main(){
	int n;
	scanf("%d",&n);
	rep1(k,n)scanf("%d",&to[k]);
	rep1(k,n)if(!vis[k]){
		cnt=0;
		dfs(k);
		C.push_back(cnt);
	}
	sort(C.begin(),C.end());
	if(C.size()>=2){
		C[C.size()-2]+=C[C.size()-1];
		C.resize(C.size()-1);
	}
	ll ans=0LL;
	rep(k,C.size())ans+=ll(C[k])*C[k];
	printf("%I64d\n",ans);
	return 0;
}