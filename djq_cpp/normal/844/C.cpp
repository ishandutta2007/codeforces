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
int nxt[100005];
vector<int> A;
vector<vector<int> >G;
map<int,int> mp;
void dfs(int cur){
	if(vis[cur])return;
	vis[cur]=true;
	A.push_back(cur);
	dfs(nxt[cur]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,cnt=0;
	cin>>n;
	rep1(k,n)cin>>nxt[k];
	rep1(k,n)mp[nxt[k]]=-1;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	it->second=++cnt;
	rep1(k,n)nxt[k]=mp[nxt[k]];
	rep1(k,n){
		if(!vis[k]){
			A.clear();
			dfs(k);
			sort(A.begin(),A.end());
			G.push_back(A);
		}
	}
	cout<<G.size()<<endl;
	rep(i,G.size()){
		cout<<G[i].size();
		rep(j,G[i].size())cout<<' '<<G[i][j];
		cout<<endl;
	}
	return 0;
}