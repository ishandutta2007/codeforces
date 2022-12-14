#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define cl(x,a) memset(x,a,sizeof(x))
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

vector<int> v[10000];
int n,m;
map<int,int>ha;

int print(int x,int y){
	if(x<0||x>=10000) return 0;
	if(ha[x*10000+y]) return 0;
	ha[x*10000+y]=1;
	printf("%08d\n",x*10000+y);
	return 1;
}

void dfs(int u){
	if(v[u].size()) return;
	v[u].pb(u);
	for(int b=10;b<u;b*=10){
		int x=u%b,y=u/b;
		dfs(x);
		dfs(y);
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				v[u].pb(v[x][i]+v[y][j]);
				v[u].pb(-v[x][i]+v[y][j]);
				v[u].pb(v[x][i]-v[y][j]);
				v[u].pb(v[x][i]*v[y][j]);
			}
		}
	}
	sort(v[u].begin(),v[u].end());
	vector<int> ::iterator it=unique(v[u].begin(),v[u].end());
	v[u].resize(distance(v[u].begin(),it));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int x=1;x<10000;x++){
		dfs(x);
		for(int i=0;i<v[x].size();i++){
			m-=print(n-v[x][i],x);
			if(!m) return 0;
			m-=v[x][i]&&print(n+v[x][i],x);
			if(!m) return 0;
		}
	}
	return 0;
}