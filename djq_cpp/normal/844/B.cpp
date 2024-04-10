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
int ch[55][55];
int main(){
	long long ans=0LL;
	int n,m;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,n)rep(j,m)cin>>ch[i][j];
	rep(i,n){
		int b=0,w=0;
		rep(j,m)if(ch[i][j]==0)b++;
		else w++;
		ans+=(1LL<<b)+(1LL<<w)-2;
	}
	rep(i,m){
		int b=0,w=0;
		rep(j,n)if(ch[j][i]==0)b++;
		else w++;
		ans+=(1LL<<b)+(1LL<<w)-2;
	}
	cout<<ans-n*m;
	return 0;
}