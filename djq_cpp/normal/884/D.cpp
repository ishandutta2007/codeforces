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
priority_queue<ll> Q;
ll ans=0LL; 
void getpp(int n){
	ll cc=0LL;
	rep(k,n){
		cc-=Q.top();
		Q.pop();
	}
	Q.push(-cc);
	ans+=cc;
}
int main(){
	int n,v;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d",&v);
		Q.push(-v);
	}
	if(!(n&1)){
		getpp(2);
		n--;
	}
	n--;
	for(int k=0;k<n;k+=2)getpp(3);
	printf("%I64d\n",ans);
	return 0;
}