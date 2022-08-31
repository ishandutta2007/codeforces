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
#define open_in(n) freopen(n,"r",stdin)
#define open_out(n) freopen(n,"w",stdout)
#define debug(x) cerr<<#x<<'='<<x<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define REPup(i,m,n) for(int i=(m);i<=(n);i++)
#define REPdn(i,m,n) for(int i=(m);i>=(n);i--)
#define FOR(i,m,n,t) for(int i=(m);((t)>0)?(i<=(n)):(i>=(n));i+=t)
#define for_all(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
#define ALL(n) n.begin,n.end
#define SIZE(n) (int)((n).size())
#define PB push_back
#define MP make_pair
#define IT iterator
#define ST first
#define ND second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf=1e9+7;
const long long linf=1e17+7;
const double eps=1e-9;
int main(){
	string a,b;
	cin>>a>>b;
	int beg=0,ans=0;
	while(beg<a.length()){
		if(a.substr(beg,b.length())==b){
			ans++;
			beg+=b.length();
		}else beg++;
	}
	cout<<ans;
	return 0;
}