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
vector<pii> G[105];
int n,deg[105]; 
int dp[105][105][30];
int solve(int i,int j,int ch){
	if(dp[i][j][ch]!=-1)return dp[i][j][ch];
	int ans=0;
	rep(k,G[i].size())
	if(G[i][k].second>=ch&&solve(j,G[i][k].first,G[i][k].second)==0)ans=1;
	return dp[i][j][ch]=ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin>>n>>m;
	rep(k,m){
		int u,v;
		char ch;
		cin>>v>>u>>ch;
		G[v].push_back(MP(u,ch-'a'));
	}
	memset(dp,-1,sizeof(dp));
	rep1(i,n){
		rep1(j,n)cout<<(solve(i,j,0)?'A':'B');
		cout<<'\n';
	}
	return 0;
}