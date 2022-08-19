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
typedef pair<ll,ll> pll;
const int MOD=1e6+3;
ll pow_mod(ll x,ll k,ll m=MOD){
	x%=m;
	ll a=1ll;
	while(k>0ll){
		if(k&1)a=(a*x)%m;
		x=(x*x)%m;
		k>>=1;
	}
	return a;
}
ll mod_inv(ll a,ll m=MOD){
	return pow_mod(a,m-2);
}
ll mod_div(ll a,ll b,ll m=MOD){
	return (a*mod_inv(b,m))%m;
}
bool larger(ll k,ll n){
	int more=0,c=0;
	while(k!=1ll){
		if(k&1)more=1;
		c++;
		k>>=1;
	}
	return ll(c+more)>n;
}
int main(){
	ll A,B,n,k,gcd;
	cin>>n>>k;
	if(larger(k,n)){
		printf("1 1");
		return 0;
	}
	n=pow_mod(2,n);
	B=pow_mod(n,k);
	gcd=n;ll nowi=2ll;
	while(nowi<k){
		gcd=(gcd*pow_mod(2ll,(k-1ll)/nowi))%MOD;
		nowi<<=1;
	}
	if(k>=MOD){
		A=0;
		B=mod_div(B,gcd);
	}else{
		A=1ll;
		if(n<k)n+=MOD;
		for(ll i=n;i>n-k;i--)A=(A*i)%MOD;
		A=mod_div(A,gcd);
		B=mod_div(B,gcd);
	}
	cout<<(B-A+MOD)%MOD<<' '<<B;
	return 0;
}