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
int grid[55][55],n,m;
vector<pii> sz;
void dfs2(int i,int j,int id){
	if(i<0||j<0||i>=n||j>=m)return;
	if(grid[i][j]!=id)return;
	grid[i][j]=10000;
	sz[sz.size()-1].first++;
	dfs2(i-1,j,id);
	dfs2(i,j-1,id);
	dfs2(i+1,j,id);
	dfs2(i,j+1,id);
}
bool dfs(int i,int j,int id){
	if(i<0||j<0||i>=n||j>=m)return false;
	if(grid[i][j])return grid[i][j]!=10000;
	grid[i][j]=id;
	sz[sz.size()-1].first++;
	bool ans=true;
	ans&=dfs(i-1,j,id);
	ans&=dfs(i,j-1,id);
	ans&=dfs(i+1,j,id);
	ans&=dfs(i,j+1,id);
	if(!ans)dfs2(i,j,id);
	return ans;
}
int main(){
	int t,ans=0;
	scanf("%d%d%d",&n,&m,&t);
	rep(i,n){
		getchar();
		rep(j,m){
			char in=getchar();
			if(in=='*')grid[i][j]=-1;
		}
	}
	rep(i,n)rep(j,m)if(!grid[i][j]){
		int id=sz.size()+1;
		sz.push_back(MP(0,id));
		if(!dfs(i,j,id))sz.erase(sz.end()-1);
	}
	sort(sz.begin(),sz.end());
	set<int> a;
	a.insert(-1);
	rep(k,sz.size()-t){
		a.insert(sz[k].second);
		ans+=sz[k].first;
	}
	rep(i,n)rep(j,m)
	if(a.find(grid[i][j])==a.end())grid[i][j]='.';
	else grid[i][j]='*';
	printf("%d\n",ans);
	rep(i,n){
		rep(j,m)putchar(grid[i][j]);
		putchar('\n');
	}
	return 0;
}