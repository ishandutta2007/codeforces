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
int n,m,w;
ll h[100005],wt[100005];
bool check(ll ch){
	ll cw=0LL,ret=0LL;
	rep(k,n){
		if(k>=w)cw-=wt[k-w];
		wt[k]=ch-(h[k]+cw);
		if(wt[k]>0)cw+=wt[k];
		else wt[k]=0LL;
		ret+=wt[k];
		if(ret>m)return false;
	}
	return true;
}
int main(){
	scanf("%d%d%d",&n,&m,&w);
	rep(k,n)scanf("%I64d",&h[k]);
	ll lb=0LL,rb=1LL<<40;
	while(lb<rb){
		ll mid=(lb+rb)>>1;
		if(check(mid))lb=mid+1;
		else rb=mid;
	}
	printf("%I64d",rb-1);
	return 0;
}