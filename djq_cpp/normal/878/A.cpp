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
int hv[10],cnt[4];
int main(){
	ios::sync_with_stdio(false);
	int n,x;char oper;
	cin>>n;
	rep(k,10)hv[k]=2;
	rep(i,n){
		cin>>oper>>x;
		if(oper=='&'){
			rep(j,10)if(!(x>>j&1))hv[j]=0;
		}else if(oper=='|'){
			rep(j,10)if(x>>j&1)hv[j]=3;
		}else if(oper=='^'){
			rep(j,10)if(x>>j&1)hv[j]^=3;
		}
	}
	rep(k,10)cnt[hv[k]]+=1<<k;
	cout<<"3\n^ "<<cnt[1]<<"\n& "<<(cnt[0]^1023)<<"\n| "<<cnt[3];
	return 0;
}