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
ll num[505][505];
ll r[505],c[505];
set<ll> ss;
int n,ei=-1,ej=-1;
ll es=-1ll;
ll getsum(){
	ll s=0;
	rep(i,n){
		ll sum=0;bool nowe=false;
		rep(j,n){
			if(num[i][j]==0ll){
				ei=i;ej=j;nowe=true;
			}
			sum+=num[i][j];
		}
		if(nowe)es=sum;
		else s=sum;
	}
	return s;
}
bool check(ll s){
	num[ei][ej]=s-es;
	if(num[ei][ej]<=0ll)return false;
	rep(i,n)rep(j,n){
		r[i]+=num[i][j];
		c[i]+=num[j][i];
	}
	ll sa=0ll,sb=0ll;
	rep(i,n){
		ss.insert(r[i]);
		ss.insert(c[i]);
		sa+=num[i][i];
		sb+=num[i][n-i-1];
	}
	ss.insert(sa);ss.insert(sb);
	return ss.size()==1;
}
int main(){
	scanf("%d",&n);
	if(n==1)printf("1");
	else{
		rep(i,n)rep(j,n)scanf("%I64d",&num[i][j]);
		if(check(getsum()))printf("%I64d",num[ei][ej]);
		else printf("-1");
	}
	return 0;
}