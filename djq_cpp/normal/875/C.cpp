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
vector<int> v[100005];
vector<int> G1[100005],G2[100005];
int can[100005];
bool vis[100005];
void dfs(int v,vector<int> G[],int tp){
	vis[v]=true;
	can[v]|=tp;
	rep(k,G[v].size())
	if(!vis[G[v][k]])dfs(G[v][k],G,tp);
}
int main(){
	int n,m,l,x;
	scanf("%d%d",&n,&m);
	rep(k,n){
		scanf("%d",&l);
		rep(j,l){
			scanf("%d",&x);
			v[k].push_back(x);
		}
		if(k==0)continue;
		bool diff=false;
		rep(j,min(v[k].size(),v[k-1].size()))
		if(v[k][j]!=v[k-1][j]){
			if(v[k][j]>v[k-1][j]){
				G1[v[k][j]].push_back(v[k-1][j]);
				G2[v[k-1][j]].push_back(v[k][j]);
			}else{
				can[v[k-1][j]]|=1;
				can[v[k][j]]|=2;
			}
			diff=true;
			break;
		}
		if(!diff&&v[k].size()<v[k-1].size()){
			printf("No\n");
			return 0;
		}
	}
	memset(vis,false,sizeof(vis));
	rep1(k,m)if(can[k]==1)dfs(k,G1,1);
	memset(vis,false,sizeof(vis));
	rep1(k,m)if(can[k]==2)dfs(k,G2,2);
	vector<int> res;
	rep1(k,m)if(can[k]==3){
		printf("No\n");
		return 0;
	}else if(can[k]==1)res.push_back(k);
	printf("Yes\n%d\n",res.size());
	rep(k,res.size())printf("%d ",res[k]);
	return 0;
}