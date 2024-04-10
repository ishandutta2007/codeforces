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
ll a[1000233];
ll power(ll ba,int t,ll md){
	ll ans=1ll;
	while(t){
		if(t&1)ans=ans*ba%md;
		ba=ba*ba%md;
		t>>=1;
	}
	return ans;
}
int main(){
	int n,m,Q,cnt=0; 
	scanf("%d%d%I64d%d",&n,&m,&a[1],&Q);
	a[0]=1LL;
	for(cnt=2;cnt<=1000123;cnt++){
		a[cnt]=a[cnt-1]*a[1]%Q;
		if(a[cnt]==1LL)break;
	}
	vector<ll> ans;
	ll cur=1LL,sum=0LL;
	rep(k,n){
		sum=(sum+cur)%cnt;
		ans.push_back(a[sum]);
		cur=cur*(m-k)%cnt*power(k+1,cnt-2,cnt)%cnt;
	}
	reverse(ans.begin(),ans.end());
	rep(k,ans.size())printf("%I64d ",ans[k]);
	return 0;
}