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
char mp[12][12][12];
int a,b,c;
int dx[6]={-1,1,0,0,0,0},dy[6]={0,0,-1,1,0,0},dz[6]={0,0,0,0,-1,1};
bool ok(int x,int y,int z){
	return x>=0&&y>=0&&z>=0&&x<a&&y<b&&z<c;
}
void dfs(int x,int y,int z){
	mp[x][y][z]='w';
	rep(k,6){
		int nx=x+dx[k],ny=y+dy[k],nz=z+dz[k];
		if(ok(nx,ny,nz)&&mp[nx][ny][nz]=='.')dfs(nx,ny,nz);
	}
}
int main(){
	scanf("%d%d%d",&a,&b,&c);
	rep(i,a){
		getchar();
		rep(j,b)scanf("%s",mp[i][j]);
	}
	int x,y,ans=0;
	scanf("%d%d",&x,&y);
	dfs(0,x-1,y-1);
	rep(i,a)rep(j,b)rep(k,c)
	if(mp[i][j][k]=='w')ans++;
	printf("%d",ans);
	return 0;
}