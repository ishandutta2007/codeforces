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
#include <conio.h>
#include <memory.h>
#include <windows.h>
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
#define rep1(i,n) for(int i=0;i<(n);i++)
#define MP make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
int n,m;
const int inf=0x3fffffff;
bool mp[1005][1005],del[2016];
vector<int>adj[2016];
int len[2016];
int path(int beg,int end){
	rep(k,n+m)len[k]=inf;
	priority_queue<pii>que;
	que.push(MP(0,beg));
	len[beg]=0;
	while(!que.empty()){
		int now=que.top().second;
		que.pop();
		if(del[now])continue;
		rep(k,adj[now].size())
		if(len[now]+1<len[adj[now][k]]){
			len[adj[now][k]]=len[now]+1;
			que.push(MP(-len[adj[now][k]],adj[now][k]));
		}
		del[now]=true;
	}
	return len[end];
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		getchar();
		rep(j,m)
		mp[i][j]=(getchar()=='#');
	}
	rep(i,n)rep(j,m)
	if(mp[i][j]){
		adj[i].push_back(j+n);
		adj[j+n].push_back(i);
	}
	int ans=path(0,n-1);
	printf("%d",ans==inf?-1:ans);
	return 0;
}