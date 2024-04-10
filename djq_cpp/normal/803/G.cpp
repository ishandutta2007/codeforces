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
struct SEG_TREE{
	vector<int> tree,asgn;
	//n is the power of 2
	void clear(int n=0){
		tree.resize(n+n,0);
		asgn.resize(n+n,-1);
	}
	SEG_TREE(int n=0){
		clear(n);
	}
	void assign(int l,int r,int val,int cur,int cl,int cr){
		if(l==cl&&r==cr){
			asgn[cur]=val;
			tree[cur]=val;
			return;
		}
		int mid=(cl+cr)>>1;
		if(asgn[cur]!=-1){
			asgn[cur<<1]=asgn[cur<<1|1]=asgn[cur];
			tree[cur<<1]=tree[cur<<1|1]=tree[cur];
		}
		asgn[cur]=-1;
		if(l<=mid)assign(l,min(mid,r),val,cur<<1,cl,mid);
		if(r>mid)assign(max(mid+1,l),r,val,cur<<1|1,mid+1,cr);
		tree[cur]=min(tree[cur<<1],tree[cur<<1|1]);
	}
	int query(int l,int r,int cur,int cl,int cr){
		if(asgn[cur]!=-1)return asgn[cur];
		if(l==cl&&r==cr)return tree[cur];
		int mid=(cl+cr)>>1,ans=INF;
		if(l<=mid)ans=min(ans,query(l,min(mid,r),cur<<1,cl,mid));
		if(r>mid)ans=min(ans,query(max(mid+1,l),r,cur<<1|1,mid+1,cr));
		return ans;
	}
}ori(131072),tre(524288);
int R_query(int N,int l,int r){
	if(l/N==r/N)return ori.query(l%N,r%N,1,0,131071);
	else if(r/N-l/N>1)return ori.query(0,N-1,1,0,131071);
	else return min(ori.query(l%N,N-1,1,0,131071),ori.query(0,r%N,1,0,131071));
}
map<int,int> id;
pair<pii,int> Q[100005];
int main(){
	int n,q,t,x,cnt,pre;
	scanf("%d%d",&n,&t);
	rep(k,n){
		scanf("%d",&x);
		ori.assign(k,k,x,1,0,131071);
	}
	scanf("%d",&q);
	rep(k,q){
		int tp,l,r,v;
		scanf("%d%d%d",&tp,&l,&r);
		l--;r--;
		if(tp==1){
			scanf("%d",&v);
			Q[k]=MP(MP(l,r),v);
		}else Q[k]=MP(MP(l,r),-1);
		id[l]=id[r]=-1;
	}
	cnt=0;
	pre=0;
	for(map<int,int>::iterator it=id.begin();it!=id.end();it++){
		if(pre<it->first){
			tre.assign(cnt,cnt,R_query(n,pre,it->first-1),1,0,524287);
			cnt++;
		}
		tre.assign(cnt,cnt,R_query(n,it->first,it->first),1,0,524287);
		it->second=cnt;
		cnt++;
		pre=it->first+1;
	}
	rep(k,q){
		int l=id[Q[k].first.first],r=id[Q[k].first.second];
		if(Q[k].second==-1)printf("%d\n",tre.query(l,r,1,0,524287));
		else tre.assign(l,r,Q[k].second,1,0,524287);
	}
	return 0;
}