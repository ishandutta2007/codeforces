#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
#define mp make_pair
#define fs first
#define se second
using namespace std;
int n,m,k,zero;
char c[501][501];
int gs;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool ok;
bool use[501][501];
inline void dfs(int x,int y){
	if(x<0||y<0||x==n||y==m) return;
	if(use[x][y]) return;
	if(c[x][y]=='#') return;
	int i,x2,y2;
	gs++;
	use[x][y]=1;
	c[x][y]='a';
	if(gs==zero){
		ok=1;
		return;
	}
	for(i=0;i<4;i++){
		x2=x+dx[i];
		y2=y+dy[i];
		dfs(x2,y2);
		if(ok) return;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	int i,j,x,y;
	for(i=0;i<n;i++) for(j=0;j<m;j++){
		cin>>c[i][j];
		if(c[i][j]=='.'){
			x=i;
			y=j;
			zero++;
		}
	}
//	cout<<x<<" "<<y<<endl;
	zero-=k;
	dfs(x,y);
//	for(i=0;i<n;i++){
//		for(j=0;j<m;j++){
//			cout<<c[i][j];
//	    }
//	    cout<<endl;
//	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		    if(c[i][j]=='a') cout<<'.';
		    else if(c[i][j]=='.') cout<<'X';
		    else cout<<'#';
	    }
	    cout<<endl;
	}
	return 0;
}