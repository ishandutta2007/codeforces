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
ll cnt[1000005],sum[1000005],rcnt[1000005],rsum[1000005];
ll getsum(ll a[],int l,int r){
	return a[min(r,1000000)]-a[min(l-1,1000000)];
}
void init(ll ori[],ll to[]){
	rep1(k,1000000)to[k]=to[k-1]+ori[k];
}
int main(){
	int n,c1,c2,x;
	scanf("%d%d%d",&n,&c2,&c1);
	rep(k,n){
		scanf("%d",&x);
		cnt[x]++;
		sum[x]+=x;
	}
	init(cnt,rcnt);
	init(sum,rsum);
	ll ans=1LL<<60;
	for(int i=2;i<=1000000;i++){
		ll ca=0LL;
		for(int j=0;j<=1000000;j+=i){
			int pre=max(j+i-c2/c1,j+1);
			ca+=getsum(rcnt,j+1,pre-1)*c2+((j+i)*getsum(rcnt,pre,j+i)-getsum(rsum,pre,j+i))*c1;
		}
		ans=min(ans,ca);
	}
	printf("%I64d\n",ans);
	return 0;
}