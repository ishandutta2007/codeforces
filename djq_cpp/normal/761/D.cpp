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
pair<pii,int> inp[100005];
int rn[100005],ans[100005];
int main(){
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	rep(k,n)inp[k].first.second=k;
	rep(k,n)scanf("%d",&inp[k].second);
	rep(k,n)scanf("%d",&inp[k].first.first);
	sort(inp,inp+n);
	rn[0]=l;
	int diff=rn[0]-inp[0].second;
	for(int k=1;k<n;k++){
		int c1=inp[k].second;
		int &c2=rn[k];
		c2=max(c1+diff+1,l);
		diff=c2-c1;
		if(c2>r){
			printf("-1");
			return 0;
		}
	}
	rep(k,n)ans[inp[k].first.second]=rn[k];
	rep(k,n)printf("%d ",ans[k]);
	return 0;
}