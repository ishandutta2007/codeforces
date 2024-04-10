#include<iostream>
#include<sstream>
#include<fstream>
#include<set>
#include<iomanip>
#include<map>
#include<queue>
#include<functional>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdio>
#include<ctime>
#include<ios>
#include<utility>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define rep(i,j,k) for(int (i)=(j);(i)<=k;(i)++)
using namespace std;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef long long ll;
typedef vector<ll>vll;
typedef pair<int,int>pii;
typedef vector<pii>vpii;
typedef map<int,int>mii;
typedef double db;
typedef float fo;
const int N=200005;
int n, c[N], cnt[N];
vector<int> g[N];
void fan(int &x) {
	if (x==1) x=-1; else x=1;
}
void go(int x, int p) {
	if (x!=0&&c[x]==-1) cnt[x]=1;
	for (int i=0; i<g[x].size(); i++) {
		if (g[x][i]!=p) {
			go(g[x][i], x);
			cnt[x]+=cnt[g[x][i]];
			if (c[g[x][i]]==-1) cnt[g[x][i]]--;
		}
	}
}
void dfs(int x, int p) {
	fan(c[x]);
	printf("%d ", x+1);
	if (cnt[x]>0) {
		for (int i=0; i<g[x].size(); i++) {
			if (g[x][i]!=p) {
				if (c[g[x][i]]==1&&cnt[g[x][i]]==0) continue;
				dfs(g[x][i], x);
				printf("%d ", x+1);
				fan(c[x]);
			}
		}
	}
	if (c[x]==-1) {
		if (p==-1){
			printf("%d %d %d ", g[x][0]+1, x+1, g[x][0]+1);
			exit(0);
		}
		printf("%d %d ", p+1, x+1);
		fan(c[x]);
		fan(c[p]);
	}
}
int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i=0; i<n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	go(0, -1);
	fan(c[0]);
	dfs(0, -1);
	puts("");
	return 0;
}