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
const double EPS=1e-13;
double pre[100005],suf[100005];
pair<double,double> ans[100005];
pair<double,double> getsol(double xy,double rxy){
	double a=-1.0,b=xy+1.0-rxy,c=-xy;
	double d=sqrt(b*b-a*c*4.0+EPS);
	return MP((-b-d)/(a+a),(-b+d)/(a+a));
}
int main(){
	int n;
	scanf("%d",&n);
	rep(k,n)scanf("%lf",&pre[k]);
	for(int k=1;k<n;k++)pre[k]+=pre[k-1];
	rep(k,n)scanf("%lf",&suf[k]);
	for(int k=n-2;k>=0;k--)suf[k]+=suf[k+1];
	rep(k,n-1)ans[k]=getsol(pre[k],suf[k+1]);
	ans[n-1].first=1.0;
	ans[n-1].second=1.0;
	for(int k=n-2;k>=0;k--){
		ans[k+1].first-=ans[k].first;
		ans[k+1].second-=ans[k].second;
	}
	rep(k,n)printf("%.7lf%c",ans[k].second,k==n-1?'\n':' ');
	rep(k,n)printf("%.7lf%c",ans[k].first,k==n-1?'\n':' ');
	return 0;
}