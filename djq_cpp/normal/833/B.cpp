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

template<int LEN>
class seg_tree{
	private:
		vector<int> tag;
		vector<int> sum;
		int rsz;
		inline int size(int ver){
			return rsz>>(31-__builtin_clz(ver));
		}
		inline int left(int ver){
			return ver<<1;
		}
		inline int right(int ver){
			return (ver<<1)|1;
		}
		void add(int cur,int cl,int cr,int l,int r,const int& v){
			if(r<l)return;
			if(l==cl&&r==cr){
				tag[cur]+=v;
				sum[cur]+=v;
			}else{
				int mid=(cl+cr)>>1;
				if(l<=mid)add(left(cur),cl,mid,l,min(mid,r),v);
				if(r>mid)add(right(cur),mid+1,cr,max(mid+1,l),r,v);
				sum[cur]=max(sum[left(cur)],sum[right(cur)])+tag[cur];
			}
		}
		int query(int cur,int cl,int cr,int l,int r,int lazy){
			if(r<l)return 0;
			if(l==cl&&r==cr)return sum[cur]+lazy;
			else{
				lazy+=tag[cur];
				int mid=(cl+cr)>>1;
				int ans=0;
				if(l<=mid)ans=max(ans,query(left(cur),cl,mid,l,min(r,mid),lazy));
				if(r>mid)ans=max(ans,query(right(cur),mid+1,cr,max(mid+1,l),r,lazy));
				return ans;
			}
		}
	public:
		void clear(){
			rsz=1<<(33-__builtin_clz(LEN-1));
			tag.resize(rsz,0);
			sum.resize(rsz,0);
			rsz>>=1;
		}
		seg_tree(){
			clear();
		}
		void add(int l,int r,const int& v){
			add(1,0,rsz-1,l,r,v);
		}
		int query(int l,int r){
			return query(1,0,rsz-1,l,r,0);
		}
};
seg_tree<35000> tree[55];//dp+C
int lpos[35005],dp[55][35005];
map<int,int> pos;
int main(){
	int n,T,x;
	scanf("%d%d",&n,&T);
	rep1(k,n){
		scanf("%d",&x);
		if(pos.find(x)==pos.end())lpos[k]=0;
		else lpos[k]=pos[x];
		pos[x]=k;
	}
	rep1(i,n){
		rep(j,T)tree[j].add(lpos[i],i-1,1);
		rep1(j,T)dp[j][i]=tree[j-1].query(0,i);
		rep1(j,T-1)tree[j].add(i,i,dp[j][i]);
	}
	printf("%d\n",dp[T][n]);
	return 0;
}