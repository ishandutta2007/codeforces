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
vector<ll> tri[2097152],pres[2097152];
void merge(vector<ll>& ans,const vector<ll>& v1,int d1,const vector<ll>& v2,int d2){
	int p1=0,p2=0;
	while(p1<v1.size()&&p2<v2.size())
	if(v1[p1]+d1<v2[p2]+d2)ans.push_back(v1[p1++]+d1);
	else ans.push_back(v2[p2++]+d2);
	while(p1<v1.size())ans.push_back(v1[p1++]+d1);
	while(p2<v2.size())ans.push_back(v2[p2++]+d2);
}
void getpre(vector<ll>& vec,const vector<ll>& from){
	vec.push_back(0LL);
	rep(k,from.size()){
		ll nf=vec.back();
		vec.push_back(from[k]+nf);
	}
}
int n,MN,d[1000005];
void init_t(){
	MN=1;while(MN<=n)MN<<=1;MN>>=1;
	rep1(k,n)tri[k].push_back(0);
	for(int k=MN-1;k>=1;k--)
	merge(tri[k],tri[k<<1],d[k<<1],tri[k<<1|1],d[k<<1|1]);
	rep1(k,n)getpre(pres[k],tri[k]);
}
ll rquery(int v,ll h){
	int cnt=lower_bound(tri[v].begin(),tri[v].end(),h)-tri[v].begin();
	return h*cnt-pres[v][cnt];
}
ll query(int a,ll h){
	ll ans=rquery(a,h);
	while(a>1){
		h-=d[a];ans-=rquery(a,h-d[a]);
		a>>=1;
		ans+=rquery(a,h);
	}
	return ans;
}
int main(){
	int q,a,h;
	scanf("%d%d",&n,&q);
	for(int k=2;k<=n;k++)scanf("%d",&d[k]);
	init_t();
	rep(k,q){
		scanf("%d%d",&a,&h);
		printf("%I64d\n",query(a,h));
	}
	return 0;
}