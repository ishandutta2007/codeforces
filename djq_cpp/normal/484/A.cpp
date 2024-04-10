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
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
int bit[2][100];
int maxl;
void to_bit(int t,ll a){
	int len=0;
	while(a){
		bit[t][len++]=a%2;
		a/=2LL;
	}
	maxl=max(maxl,len);
}
int main(){
	int T;
	ll l,r;
	scanf("%d",&T);
	while(T--){
		maxl=0;
		rep(i,2)rep(j,100)bit[i][j]=0;
		scanf("%I64d%I64d",&l,&r);
		r++;
		to_bit(0,l);
		to_bit(1,r);
		int id=maxl-1;
		ll num=0;
		while(bit[0][id]==bit[1][id]&&id>0){
			num=num*2LL+bit[1][id];
			id--;
		}
		num=(num*2LL+1LL)<<id;
		printf("%I64d\n",num-1);
	}
	return 0;
}