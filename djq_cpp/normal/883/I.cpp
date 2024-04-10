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
bool tree[1048576];
bool query(int id){
	id+=524288;
	while(id>0){
		if(tree[id])return true;
		id>>=1;
	}
	return false;
}
void modify(int l,int r){
	l+=524288;r+=524288;
	while(l<r){
		if(l&1)tree[l]=true;
		if(!(r&1))tree[r]=true;
		l=(l+1)>>1;
		r=(r-1)>>1;
	}
	if(l==r)tree[l]=true;
}
int n,t,num[300005];
bool check(int d){
	memset(tree,false,sizeof(tree));
	modify(0,0);
	int r=1;
	rep(k,n){
		if(!query(k))continue;
		while(r<=n&&num[r]-num[k+1]<=d)r++;
		modify(k+t,r-1);
	}
	return query(n);
}
int main(){
	scanf("%d%d",&n,&t);
	rep1(k,n)scanf("%d",&num[k]);
	sort(num+1,num+1+n);
	int l=0,r=INF;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}