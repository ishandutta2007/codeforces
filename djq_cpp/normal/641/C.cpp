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
int a[1000005],b[1000005];
struct cycle{
	vector<int> cur;
	cycle(int n=0){
		cur.resize(n,0);
		rep(k,cur.size())cur[k]=k;
	}
	cycle(const vector<int>& v){
		cur=v;
	}
	cycle operator *(const cycle& oth){
		cycle ans(cur.size());
		rep(k,cur.size())ans.cur[k]=cur[oth.cur[k]];
		return ans;
	}
	cycle power(int T){
		cycle v=*this,ans(cur.size());
		while(T){
			if(T&1)ans=ans*v;
			v=v*v;
			T>>=1;
		}
		return ans;
	}
};
cycle shr(int n,int st){
	cycle res(n);
	for(int k=st;k<n;k++)res.cur[k]=k-st;
	rep(k,st)res.cur[k]=k+n-st;
	return res;
}
cycle gett(int n,int x){
	cycle res(n);
	if(x==0)rep(k,n>>1)swap(res.cur[k<<1],res.cur[(k<<1)|1]);
	else{
		for(int k=2;k<n;k+=2)swap(res.cur[k-1],res.cur[k]);
		swap(res.cur[0],res.cur[n-1]);
	}
	return res;
}
int main(){
	int n,q,p=0,cp,t;
	vector<int> v;
	scanf("%d%d",&n,&q);
	rep(k,q){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&cp);
			p+=cp;
			if(p<0)p+=n;
			p%=n;
		}else{
			if(!v.empty()&&*(v.end()-1)==(p&1))v.pop_back();
			else v.push_back(p&1);
		}
	}
	cycle ans(n);
	if(v.size()>=2){
		cycle cur=gett(n,v[0])*gett(n,v[1]);
		ans=ans*cur.power(v.size()>>1);
	}
	if(v.size()&1)ans=ans*gett(n,v[0]);
	ans=ans*shr(n,p);
	rep(k,n)printf("%d ",ans.cur[k]+1);
	return 0;
}