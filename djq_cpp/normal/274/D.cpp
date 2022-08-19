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
vector<int> adj[200005];
int N,n,m,deg[200005];
pii mat[100005];
vector<vector<int> > SameN;
vector<int> ans;
bool Tsort(){
	queue<int> que;
	rep(i,N)rep(j,adj[i].size())
	deg[adj[i][j]]++;
	rep(i,m)if(deg[i]==0)que.push(i);
	while(!que.empty()){
		int out=que.front();que.pop();N--;
		if(out<m)ans.push_back(out);
		rep(i,adj[out].size()){
			int v=adj[out][i];
			deg[v]--;
			if(deg[v]==0)que.push(v);
		}
	}
	return N==0;
}
int main(){
	scanf("%d%d",&n,&m);
	N=m;
	rep(i,n){
		rep(j,m){
			scanf("%d",&mat[j].first);
			mat[j].second=j;
		}
		sort(mat,mat+m);
		int fpos=0;
		while(fpos<m&&mat[fpos].first==-1)fpos++;
		if(fpos==m)continue;
		vector<int> vec;
		vec.push_back(mat[fpos].second);SameN.clear();
		for(int j=fpos+1;j<m;j++)
		if(mat[j].first==mat[j-1].first)vec.push_back(mat[j].second);
		else{
			SameN.push_back(vec);
			vec.clear();
			vec.push_back(mat[j].second);
		}
		SameN.push_back(vec);
		for(int j=SameN.size()-2;j>=0;j--){
			vector<int> &vec1=SameN[j];
			vector<int> &vec2=SameN[j+1];
			rep(k,vec1.size())adj[vec1[k]].push_back(N);
			rep(k,vec2.size())adj[N].push_back(vec2[k]);
			N++;
		}
	}
	if(Tsort()){
		rep(k,ans.size())
		printf("%d ",ans[k]+1);
	}else printf("-1");
	return 0;
}