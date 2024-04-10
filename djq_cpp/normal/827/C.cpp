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
struct SEG_TREE{
	int MN;
	vector<int> tree;
	void init(int n){
		MN=1;
		while(MN<n)MN<<=1;
		tree.resize(MN+MN,0);
	}
	int getid(int x){
		return MN+x;
	}
	void modify(int id,int v){
		id=getid(id);
		tree[id]=v;
		id>>=1;
		while(id>0){
			tree[id]=tree[id<<1]+tree[(id<<1)+1];
			id>>=1;
		}
	}
	int query(int l,int r){
		l=getid(l);r=getid(r);
		int a1=0,a2=0;
		while(l<r){
			if(l&1)a1=a1+tree[l];
			if(!(r&1))a2=tree[r]+a2;
			l=(l+1)>>1;
			r=(r-1)>>1;
		}
		if(l==r)a1=a1+tree[l];
		return a1+a2;
	}
};
SEG_TREE tre[4][11][10]; 
string S;
int to[128];
int main(){
	ios::sync_with_stdio(false);
	to['A']=0;to['C']=1;to['G']=2;to['T']=3;
	cin>>S;
	rep(k,4)rep1(i,10)rep(j,10)tre[k][i][j].init(S.length());
	rep(i,S.length())rep1(j,10)
	tre[to[S[i]]][j][i%j].modify(i,1);
	int q;cin>>q;
	while(q--){
		int t,p1,p2;
		cin>>t;
		if(t==1){
			char ch;
			cin>>p1>>ch;p1--;
			rep1(k,10){
				tre[to[S[p1]]][k][p1%k].modify(p1,0);
				tre[to[ch]][k][p1%k].modify(p1,1);
			}
			S[p1]=ch;
		}else{
			string cur;
			cin>>p1>>p2>>cur;p1--;p2--;
			int ans=0;
			rep(k,cur.length())
			ans+=tre[to[cur[k]]][cur.length()][(p1+k)%cur.length()].query(p1,p2);
			cout<<ans<<'\n';
		}
	}
	return 0;
}