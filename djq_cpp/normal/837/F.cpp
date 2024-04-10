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
int n,ln0;
ll t,a[200005];
ll gcd(ll x,ll y){
	return y==0LL?x:gcd(y,x%y);
}
bool check(ll pt){
	ll cur=1ll,sum=0ll;
	for(int k=1;k<=ln0;k++){
		if((t-1)/cur<a[k])return true;
		sum+=cur*a[k];
		if(sum>=t)return true;
		ll x=ll(k)/gcd(k,pt-1),y=ll(k+pt-1)/gcd(k,pt-1);
		cur/=x;
		if((t-1)/y<cur&&k!=ln0)return true;
		cur*=y;
	}
	return false;
}
int main(){
	scanf("%d%I64d",&n,&t);
	rep1(k,n)scanf("%I64d",&a[k]);
	reverse(a+1,a+1+n);
	rep1(k,n)if(a[k]>=t){
		printf("0\n");
		return 0;
	}
	for(ln0=n;ln0>=0;ln0--)if(a[ln0]!=0LL)break;
	ll l=1,r=1ll<<62;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%I64d",r);
	return 0;
}