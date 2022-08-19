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
int n,m,C,date1[1000005],date2[1000005];
pii temp[1000005];
vector<int> v;
void UNION(int p2){
	int p1=0;
	while(p1<n&&p2<m){
		if(date1[p1]<date2[p2])v.push_back(date1[p1++]);
		else v.push_back(date2[p2++]);
	}
	while(p1<n)v.push_back(date1[p1++]);
	while(p2<m)v.push_back(date2[p2++]);
}
bool check(int L){
	v.clear();
	UNION(m-L);
	int cur=0,day=0;
	for(int T=0;T<v.size();T+=C){
		if(v[T]<day)return false;
		day++;
	}
	return true;
}
int getans(){
	int L=0,R=m+1;
	while(L<R){
		int mid=(L+R)/2;
		if(check(mid))L=mid+1;
		else R=mid;
	}
	return R-1;
}
int main(){
	scanf("%d%d%d",&n,&m,&C);
	rep(k,n)scanf("%d",&date1[k]);
	rep(k,m)scanf("%d",&temp[k].first);
	rep(k,m)temp[k].second=k+1;
	sort(date1,date1+n);
	sort(temp,temp+m);
	rep(k,m)date2[k]=temp[k].first;
	if(!check(0)){
		printf("-1");
		return 0;
	}
	int ans=getans();
	printf("%d\n",ans);
	for(int k=m-ans;k<m;k++)printf("%d ",temp[k].second);
	return 0;
}