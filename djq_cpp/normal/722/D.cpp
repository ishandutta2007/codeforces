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
int n,x[50005],y[50005];
vector<int> ans;
bool c(int lim){
	map<int,int> used;
	rep(k,n){
		x[k]=y[k];
		while(x[k]>lim)x[k]>>=1;
		used[-x[k]]++;
	}
	for(map<int,int>::iterator it=used.begin();it!=used.end();it++)
	if((it->second)>1)used[-((-(it->first))>>1)]+=(it->second)-1;
	if(used[0])return false;
	ans.clear();
	for(map<int,int>::iterator it=used.begin();it!=used.end();it++)
	if(it->second)ans.push_back(-(it->first));
}
int main(){
	scanf("%d",&n);
	rep(k,n)scanf("%d",&y[k]);
	int l=0,r=1e9;
	while(l<r){
		int mid=((l+r)>>1);
		if(c(mid))r=mid;
		else l=mid+1;
	}
	c(r);
	rep(k,ans.size())
	printf("%d ",ans[k]);
	return 0;
}