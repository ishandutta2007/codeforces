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
ll num[200005],x;
bool flip[200005];
int main(){
	bool bel0=false;
	int n,T;
	set<pair<ll,int> > nums;
	scanf("%d%d%I64d",&n,&T,&x);
	rep(k,n){
		scanf("%I64d",&num[k]);
		if(num[k]<0ll){
			bel0=!bel0;
			num[k]*=-1ll;
			flip[k]=true;
		}
		nums.insert(MP(num[k],k));
	}
	ll ms=nums.begin()->first;
	int mid=nums.begin()->second;
	if(!bel0&&ms-x*T<0ll){
		while(ms>=0ll){
			ms-=x;
			T--;
		}
		pair<ll,int> newa=MP(-ms,mid);
		nums.erase(nums.begin());
		nums.insert(newa);
		bel0=true;
	}else mid=-1;
	while(T--){
		ll out=nums.begin()->first;
		int id=nums.begin()->second;
		nums.erase(nums.find(MP(out,id)));
		if(bel0)nums.insert(MP(out+x,id));
		else nums.insert(MP(out-x,id));
	}
	for(set<pair<ll,int> >::iterator it=nums.begin();it!=nums.end();it++)num[it->second]=it->first;
	if(mid!=-1)num[mid]*=-1ll;
	rep(k,n)printf("%I64d ",flip[k]?(-num[k]):num[k]);
	return 0;
}