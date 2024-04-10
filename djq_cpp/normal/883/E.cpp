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
int main(){
	int n,m,can=(1<<26)-1,cc=0;
	string w,cw;
	ios::sync_with_stdio(false);
	cin>>n>>cw>>m;
	rep(k,n)if(cw[k]!='*')cc|=1<<cw[k]-'a';
	rep(i,m){
		cin>>w;
		bool sui=true;
		rep(j,n)if(cw[j]!='*'&&cw[j]!=w[j]||cw[j]=='*'&&(cc>>(w[j]-'a')&1))sui=false;
		if(!sui)continue;
		int cur=0;
		rep(j,n)if(cw[j]=='*')cur|=1<<w[j]-'a';
		can&=cur;
	}
	int ans=0;
	rep(k,26)if(can>>k&1)ans++;
	cout<<ans<<'\n';
	return 0;
}