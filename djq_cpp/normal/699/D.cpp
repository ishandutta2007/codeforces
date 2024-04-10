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
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
int p[200005],fst[200005];
bool vis[200005],root[200005],leaf[200005],cyc[200005];
vector<int> prev;
void dfs(int now){
	set<int> in;
	while(!vis[now]){
		vis[now]=true;
		in.insert(now);
		now=p[now];
		if(root[now]){
			vis[now]=true;
			prev.push_back(now);
			return;
		}
	}
	if(in.find(now)==in.end())return;
	p[now]=now;
	cyc[now]=true;
	prev.push_back(now);
}
int main(){
	int n,ans=0,pos=0;
	scanf("%d",&n);
	rep1(k,n)leaf[k]=true;
	rep1(k,n){
		scanf("%d",&p[k]);
		fst[k]=p[k];
		if(p[k]==k)root[k]=true;
		else leaf[p[k]]=false;
	}
	rep1(k,n)if(leaf[k]&&!vis[k])dfs(k);
	rep1(k,n)if(!vis[k])dfs(k);
	rep(k,prev.size())
	if(!cyc[prev[k]]){
		pos=k;
		break;
	}
	for(int k=0;k<prev.size();k++)p[prev[k]]=prev[pos];
	rep1(k,n)if(p[k]!=fst[k])ans++;
	printf("%d\n",ans);
	rep1(k,n)printf("%d ",p[k]);
	return 0;
}