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
set<pii> can;
int dx[128],dy[128];
int main(){
	dx['U']=0;dy['U']=1;
	dx['D']=0;dy['D']=-1;
	dx['R']=1;dy['R']=0;
	dx['L']=-1;dy['L']=0;
	int a,b;
	string S;
	cin>>a>>b>>S;
	int x=0,y=0,cx=0,cy=0;
	rep(k,S.length()){
		x+=dx[S[k]];y+=dy[S[k]];
	}
	rep(k,S.length()){
		if(x==0&&cx==a&&(y==0&&cy==b||y!=0&&(b-cy)%y==0&&(b-cy)/y>=0)||
			x!=0&&(a-cx)%x==0&&(a-cx)/x>=0&&(y==0&&cy==b||y!=0&&(b-cy)%y==0&&(a-cx)/x==(b-cy)/y)){
			printf("Yes\n");
			return 0;
		}
		cx+=dx[S[k]];cy+=dy[S[k]];
	}
	printf("No\n");
	return 0;
}