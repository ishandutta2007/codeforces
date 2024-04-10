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
const string imp="djq_cpp is so terrible at competitive programming that he cannot even solve a single Div.2 A by himself!";
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ok[128];
char grid[55][55];
int vis[55][55],prev[55][55],pri[55][55],cnt;
int n,m,sx,sy,fx,fy;
string ans=imp;
string solve_g(){
	rep(i,n)rep(j,m){
		vis[i][j]=-1;
		prev[i][j]=-1;
		pri[i][j]=INF;
	}
	queue<pii> Q;
	Q.push(MP(sx,sy));
	vis[sx][sy]=0;
	while(!Q.empty()){
		vector<int> cx,cy;
		cx.push_back(Q.front().first);
		cy.push_back(Q.front().second);
		Q.pop();
		while(!Q.empty()){
			int ccx=Q.front().first,ccy=Q.front().second;
			if(pri[cx[0]][cy[0]]!=pri[ccx][ccy])break;
			Q.pop();
			cx.push_back(ccx);cy.push_back(ccy);
		}
		vector<pair<pii,int> > to[5];
		rep(i,cx.size()){
			int ccx=cx[i],ccy=cy[i];
			rep(k,4){
				int nx=ccx+dx[k],ny=ccy+dy[k];
				if(nx<0||ny<0||nx>=n||ny>=m||ok[grid[nx][ny]]==-1||vis[nx][ny]!=-1)continue;
				to[ok[grid[nx][ny]]].push_back(MP(MP(nx,ny),k));
			}
		}
		rep(i,5){
			rep(j,to[i].size()){
				int nx=to[i][j].first.first,ny=to[i][j].first.second;
				if(vis[nx][ny]!=-1)continue;
				Q.push(MP(nx,ny));
				vis[nx][ny]=vis[cx[0]][cy[0]]+1;
				prev[nx][ny]=to[i][j].second;
				pri[nx][ny]=cnt;
			}
			cnt++;
		}
	}
	if(vis[fx][fy]==-1)return imp;
	string ret;
	pii cur=MP(fx,fy);
	for(int k=1;k<vis[fx][fy];k++){
		int dir=prev[cur.first][cur.second];
		cur=MP(cur.first-dx[dir],cur.second-dy[dir]);
		ret.push_back(grid[cur.first][cur.second]);
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
void dfs(char cur,int rs){
	if(rs<0)return;
	if(cur<'a'){
		if(rs==0){
			string seq=solve_g();
			if(ans.length()>seq.length()||ans.length()==seq.length()&&ans>seq)ans=seq;
		}
		return;
	}
	ok[cur]=-1;
	dfs(cur-1,rs);
	ok[cur]=rs;
	dfs(cur-1,rs-1);
}
int main(){
	int r;
	scanf("%d%d%d",&n,&m,&r);
	rep(i,n){
		scanf("%s",grid[i]);
		rep(j,m)if(grid[i][j]=='S'){
			sx=i;sy=j;
		}else if(grid[i][j]=='T'){
			fx=i;fy=j;
		}
	}
	dfs('z',r);
	if(ans==imp)printf("-1\n");
	else printf("%s\n",ans.c_str());
	return 0;
}