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
int num[200005],in[200005];
int lbound(int l,int r,int nc){
	while(l<r){
		int mid=(l+r)/2;
		if(num[mid]<nc)l=mid+1;
		else r=mid;
	}
	return l-1;
}
int main(){
	int ins,n=1,ans=0;
	scanf("%d",&ins);
	rep(k,ins)scanf("%d",&in[k]);
	sort(in,in+ins);
	num[0]=in[0];
	for(int k=1;k<ins;k++)
	if(in[k]!=in[k-1])
	num[n++]=in[k];
	rep(k,n){
		int fn=num[k]*2,id=k;
		while(1){
			id=lbound(id+1,n,fn);
			ans=max(ans,num[id]%num[k]);
			if(fn>num[n-1])break;
			fn+=num[k];
		}
	}
	printf("%d",ans);
	return 0;
}