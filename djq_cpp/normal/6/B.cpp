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
char ofc[105][105];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int n,m;
set<char> cls;
bool isok(int x,int y){
	return x>=0&&y>=0&&x<n&&y<m;
}
int main(){
	char c;
	cin>>n>>m>>c;
	rep(k,n)cin>>ofc[k];
	rep(i,n)rep(j,m)
	if(ofc[i][j]==c)
	rep(k,4){
		int nx=i+dx[k],ny=j+dy[k];
		if(isok(nx,ny)&&ofc[nx][ny]!=c&&ofc[nx][ny]!='.')
		cls.insert(ofc[nx][ny]);
	}
	cout<<cls.size();
	return 0;
}