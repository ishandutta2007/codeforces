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
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
typedef long long ll;
const ll linf=0x3fffffffffffffff;
using namespace std;
vector<pair<int,int> >adj[100005];
ll len[100005];
int prev[100005];
void dijkstra(){
	bool *del=new bool[100005];
	priority_queue<pair<ll,int> >que;
	rep1(k,100005)len[k]=linf;
	rep1(k,100005)prev[k]=-1;
	rep1(k,100005)del[k]=false;
	que.push(MP(0,1));
	len[1]=0;
	while(!que.empty()){
		int now=que.top().second,d=-que.top().first;que.pop();
		if(del[now])continue;
		rep(k,adj[now].size()){
			int edge=adj[now][k].first;
			ll new_w=len[now]+(ll)(adj[now][k].second);
			if(new_w<len[edge]){
				len[edge]=new_w;
				prev[edge]=now;
				que.push(MP(-new_w,edge));
			}
		}
		del[now]=true;
	}
}
void print(int p){
	if(prev[p]!=-1)print(prev[p]);
	printf("%d ",p);
}
int main(){
	int n,m,x,y,w;
	scanf("%d%d",&n,&m);
	rep(k,m){
		scanf("%d%d%d",&x,&y,&w);
		if(x==y)continue;
		adj[x].push_back(MP(y,w));
		adj[y].push_back(MP(x,w));
	}
	dijkstra();
	if(prev[n]==-1)printf("-1");
	else print(n);
	return 0;
}