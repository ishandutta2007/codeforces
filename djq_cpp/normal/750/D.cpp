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
bool vis[505][505],ex[35][505][505][10];
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int turn[8][2]={{1,3},{0,2},{1,4},{0,5},{2,7},{3,6},{5,7},{4,6}};
const int BX=250,BY=250,BD=1;
int step[40],D;
void REM_DFS(int x,int y,int dir,int dep){
	if(dep==D)return;
	rep(k,step[dep]){
		x+=dx[dir];y+=dy[dir];
		vis[x][y]=true;
	}
	if(ex[dep][x][y][dir])return;
	ex[dep][x][y][dir]=true;
	rep(k,2){
		int newd=turn[dir][k];
		REM_DFS(x,y,newd,dep+1);
	}
}
int main(){
	scanf("%d",&D);
	rep(k,D)scanf("%d",&step[k]);
	REM_DFS(BX,BY,BD,0);
	int ans=0;
	rep(i,500)rep(j,500)
	if(vis[i][j])ans++;
	printf("%d",ans);
	return 0;
}