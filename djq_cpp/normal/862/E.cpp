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
ll aa,bs[2],b[100005];
set<ll> ba;
ll getans(ll a){
	ll ans=1LL<<60;
	set<ll>::iterator it=ba.lower_bound(a);
	if(it!=ba.end())ans=min(ans,(*it)-a);
	if(it!=ba.begin())ans=min(ans,a-(*(--it)));
	return ans;
}
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	rep(k,n){
		scanf("%I64d",&b[k]);
		aa+=(k&1)?-b[k]:b[k];
	}
	rep(k,m){
		scanf("%I64d",&b[k]);
		bs[n&1]+=b[k];
		if(k>=n-1){
			ba.insert(bs[1]-bs[0]);
			bs[1]-=b[k-n+1]; 
		}
		swap(bs[0],bs[1]);
	}
	printf("%I64d\n",getans(aa));
	rep(k,q){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if(!((r-l)&1))aa+=(r&1)?x:-x;
		printf("%I64d\n",getans(aa));
	}
	return 0;
}