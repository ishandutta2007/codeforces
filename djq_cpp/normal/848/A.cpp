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
int max_ps(int n){
	int l=0,r=500;
	while(l<r){
		int mid=(l+r)/2;
		if(mid*(mid+1)/2<=n)l=mid+1;
		else r=mid;
	}
	return r-1;
}
int main(){
	int n,ch='a';
	scanf("%d",&n);
	if(n==0)putchar('a');
	while(n>0){
		int c=max_ps(n);
		n-=c*(c+1)/2;
		c++;
		while(c--)putchar(ch);
		ch++;
	}
}