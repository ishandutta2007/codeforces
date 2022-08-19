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
int n,MN,num[200005];
vector<int> tree[524288];
int getid(int x){
	return MN+x-1;
}
void UNION(vector<int>& res,vector<int>& x,vector<int> &y){
	int p1=0,p2=0;
	while(p1<x.size()&&p2<y.size()){
		if(x[p1]<y[p2])res.push_back(x[p1++]);
		else res.push_back(y[p2++]);
	}
	while(p1<x.size())res.push_back(x[p1++]);
	while(p2<y.size())res.push_back(y[p2++]);
}
void init(){
	MN=1;
	while(MN<n)MN*=2;
	rep(k,n)tree[MN+k].push_back(num[k+1]);
	for(int k=MN-1;k>0;k--)
	UNION(tree[k],tree[k<<1],tree[k<<1|1]);
}
int getcnt(vector<int>& v,int x,int tp){
	if(tp==-1)return lower_bound(v.begin(),v.end(),x)-v.begin();
	else return v.end()-lower_bound(v.begin(),v.end(),x+1);
}
int query(int l,int r,int c,int b){
	l=getid(l);r=getid(r);
	int a1=0,a2=0;
	while(l<r){
		if(l&1)a1+=getcnt(tree[l],c,b);
		if(!(r&1))a2+=getcnt(tree[r],c,b);
		l=(l+1)>>1;
		r=(r-1)>>1;
	}
	if(l==r)a1+=getcnt(tree[l],c,b);
	return a1+a2;
}
ll C2(int x){
	return ll(x)*(x-1)/2;
}
ll count_out(int l,int r,int d,int u){
	return C2(l-1)+C2(n-r)+C2(d-1)+C2(n-u)
			-C2(query(1,l-1,d,-1))-C2(query(1,l-1,u,1))-C2(query(r+1,n,d,-1))-C2(query(r+1,n,u,1));
}
int main(){
	int Q,l,r,d,u;
	scanf("%d%d",&n,&Q);
	rep1(k,n)scanf("%d",&num[k]);
	init();
	while(Q--){
		scanf("%d%d%d%d",&l,&d,&r,&u);
		printf("%I64d\n",C2(n)-count_out(l,r,d,u));
	}
	return 0;
}