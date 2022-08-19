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
set<int> h;
vector<int> nums;
int main(){
	int n,in;
	ll ans=0ll;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d",&in);
		h.insert(in);
		nums.push_back(in);
	}
	sort(nums.begin(),nums.end());
	for(set<int>::iterator it=h.begin();it!=h.end();it++){
		int cur=(*it),Lt=0,j=cur;
		ll res=0ll;
		for(;j<=200000;j+=cur){
			int T=lower_bound(nums.begin(),nums.end(),j)-nums.begin();
			res+=ll(T-Lt)*(j-cur);
			Lt=T;
		}
		res+=ll(n-Lt)*(j-cur);
		ans=max(ans,res);
	}
	printf("%I64d\n",ans);
	return 0;
}