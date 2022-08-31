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
int comp[16384],lp[16384],cur[16384],num[16384];
int dsu[32768];
int root(int x){
	return dsu[x]==x?x:dsu[x]=root(dsu[x]);
}
int UNION(int u,int v){
	u=root(u);v=root(v);
	if(u==v)return 0;
	dsu[u]=v;
	return 1;
}
char ch[16384];
int hv[32768];
int main(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	rep1(i,n){
		scanf("%s",ch);
		rep(k,m>>2)num[k]=ch[k]<'A'?ch[k]-'0':ch[k]-'A'+10;
		rep(k,m)cur[k]=num[k>>2]>>((k&3)^3)&1;
		rep(k,m)ans+=cur[k];
		for(int k=16384;k<32768;k++)dsu[k]=k;
		rep(k,m)if(lp[k]&&cur[k])if(cur[k])ans-=UNION(k,k+16384);
		for(int k=1;k<m;k++)if(cur[k-1]&&cur[k])ans-=UNION(k+16383,k+16384);
		rep(k,m)dsu[k]=root(k+16384)-16384;
		rep(k,m)lp[k]=cur[k];
	}
	printf("%d\n",ans);
	return 0;
}