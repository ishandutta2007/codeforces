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
vector<int> adj[100005];
vector<pii> edges;
int deg[100005],n;
int num[100005];
bool tpsort(){
	int nown=0;
	rep(k,n)rep(j,adj[k].size())
	deg[adj[k][j]]++;
	queue<int>dz;
	rep(k,n)
	if(deg[k]==0)dz.push(k);
	while(!dz.empty()){
		if(dz.size()>1)return false;
		int out=dz.front();
		num[out]=(nown++);
		dz.pop();
		rep(k,adj[out].size()){
			int newe=adj[out][k];
			if(deg[newe]){
				deg[newe]--;
				if(deg[newe]==0)dz.push(newe);
			}
		}
	}
	return true;
}
int main(){
	int m,x,y;
	scanf("%d%d",&n,&m);
	rep(k,m){
		scanf("%d%d",&x,&y);
		x--;y--;
		adj[x].push_back(y);
		edges.push_back(MP(x,y));
	}
	if(!tpsort()){
		printf("-1");
		return 0;
	}
	int last=0;
	rep(k,m){
		x=edges[k].first;
		y=edges[k].second;
		if(num[x]+1==num[y])last=k;
	}
	printf("%d",last+1);
	return 0;
}