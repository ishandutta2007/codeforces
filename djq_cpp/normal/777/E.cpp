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
#define rep(i,N) for(int i=0;i<(N);i++)
#define rep1(i,N) for(int i=1;i<=(N);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7,MAXN=524288;
#define a first.second
#define b first.first
#define h second
int N,MN;
long long G[MAXN],dp[MAXN],tree[MAXN];
pair<pii,int> ring[MAXN];
void init(){
	MN=1;
	while(MN<N)MN*=2;
}
int getid(int x){
	return MN+x-1;
}
void modify(int id,long long v){
	if(G[id]>=v)return;
	G[id]=v;
	id=getid(id);
	tree[id]=v;
	id>>=1;
	while(id>0){
		tree[id]=max(tree[id<<1],tree[(id<<1)+1]);
		id>>=1;
	}
}
long long query(int l,int r){
	l=getid(l);r=getid(r);
	long long a1=0LL,a2=0LL;
	while(l<r){
		if(l&1)a1=max(a1,tree[l]);
		if(!(r&1))a2=max(tree[r],a2);
		l=(l+1)>>1;
		r=(r-1)>>1;
	}
	if(l==r)a1=max(a1,tree[l]);
	return max(a1,a2);
}
int main(){
	int n;
	long long ans=0LL;
	map<int,int> to;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d%d%d",&ring[k].a,&ring[k].b,&ring[k].h);
		to[ring[k].a]=to[ring[k].b]=-1;
	}
	for(map<int,int>::iterator it=to.begin();it!=to.end();it++){
		N++;
		it->second=N;
	}
	init();
	rep(k,n){
		ring[k].a=to[ring[k].a];
		ring[k].b=to[ring[k].b];
	}
	sort(ring,ring+n);
	rep(k,n){
		dp[k]=query(ring[k].a+1,ring[k].b)+(ll)(ring[k].h);
		modify(ring[k].b,dp[k]);
		ans=max(ans,dp[k]);
	}
	printf("%I64d",ans);
	return 0;
}