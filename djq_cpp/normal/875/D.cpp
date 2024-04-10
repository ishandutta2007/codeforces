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
//[l,r] series:[1,n]
struct maxi{
	int mv,mp;
	maxi(){
		mv=mp=0;
	}
	maxi operator +(const maxi& oth)const{
		maxi ans;
		if(oth.mv>mv){
			ans.mv=oth.mv;ans.mp=oth.mp;
		}else{
			ans.mv=mv;ans.mp=mp;
		}
		return ans;
	}
}tree[524288];
int num[262144];
int nxt[32][200005],pre[32][200005];
void modify(int id,int v){
	num[id]=v;
	id+=262144;
	tree[id].mv=v;
	tree[id].mp=id-262144;
	id>>=1;
	while(id>0){
		tree[id]=tree[id<<1]+tree[(id<<1)+1];
		id>>=1;
	}
}
maxi query(int l,int r){
	l+=262144;r+=262144;
	maxi a1,a2;
	while(l<r){
		if(l&1)a1=a1+tree[l];
		if(!(r&1))a2=tree[r]+a2;
		l=(l+1)>>1;
		r=(r-1)>>1;
	}
	if(l==r)a1=a1+tree[l];
	return a1+a2;
}
int n;
int get(int cur[],int pos){
	if(pos<0||pos>=n||cur[pos]==pos)return pos;
	return cur[pos]=get(cur,cur[pos]);
}
void erase_p(int id,int pp){
	nxt[id][pp]=get(nxt[id],pp+1);
	pre[id][pp]=get(pre[id],pp-1);
}
ll solve(int l,int r){
	if(l>r)return 0LL;
	int pos=query(l,r).mp;
	if(num[pos]==0)return 0LL;
	int lp=-INF,rp=INF;
	rep(k,31)if(num[pos]>>k&1)erase_p(k,pos);
	else{
		lp=max(lp,get(pre[k],pos));
		rp=min(rp,get(nxt[k],pos));
	}
	ll ans=max(0LL,ll(lp-l+1)*(r-pos+1))+max(0LL,ll(pos-l+1)*(r-rp+1)-max(0LL,ll(lp-l+1))*max(0LL,ll(r-rp+1)));
	modify(pos,0);
	if(l<pos)ans+=solve(l,pos-1);
	if(pos<r)ans+=solve(pos+1,r);
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,31)rep(j,n)nxt[i][j]=pre[i][j]=j;
	rep(k,n){
		int x;
		scanf("%d",&x);
		modify(k,x);
		rep(j,31)if(!(x>>j&1))erase_p(j,k);
	}
	printf("%I64d",solve(0,n-1));
	return 0;
}