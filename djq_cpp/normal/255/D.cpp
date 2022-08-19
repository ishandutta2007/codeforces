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
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
using namespace std;
int n,c,x,y;
ull sqr(int num){
	return (ull)num*num;
}
ull getsum(int len){
	ull ans=sqr(len+1)+sqr(len);
	int lx=1-(x-len),ly=1-(y-len),rx=x+len-n,ry=y+len-n,t;
	t=-x+ly;
	if(t>0)ans+=(ull)t*(t+1)/2;
	t=-x+ry;
	if(t>0)ans+=(ull)t*(t+1)/2;
	t=x+ly-1-n;
	if(t>0)ans+=(ull)t*(t+1)/2;
	t=x+ry-1-n;
	if(t>0)ans+=(ull)t*(t+1)/2;
	if(lx>0)ans-=sqr(lx);
	if(ly>0)ans-=sqr(ly);
	if(rx>0)ans-=sqr(rx);
	if(ry>0)ans-=sqr(ry);
	return ans;
}
int findans(){
	int l=0,r=n*2-1;
	while(l<r){
		int mid=(l+r)/2;
		if(getsum(mid)>=(ull)(c))r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	scanf("%d%d%d%d",&n,&x,&y,&c);
	printf("%d",findans());
	return 0;
}