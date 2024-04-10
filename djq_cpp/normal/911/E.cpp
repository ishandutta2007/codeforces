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
struct BIT{
	int n,tree[262144];
	void modify(int id,int v){
		while(id<=n){
			tree[id]+=v;
			id+=id&(-id);
		}
	}
	int query(int x){
		int ans=0;
		while(x>0){
			ans+=tree[x];
			x-=x&(-x);
		}
		return ans;
	}
	int last1(int x){
		int len=18,pos=0,cc=0;
		int qq=query(x);
		while(len>=0){
			if(pos+(1<<len)<=x&&cc+tree[pos+(1<<len)]<qq){
				pos+=1<<len;
				cc+=tree[pos];
			}
			len--;
		}
		return pos+1;
	}
}tre,tre2,tre3;
int dat[200005];
int forb;
int main(){
	int n,b;
	scanf("%d%d",&n,&b);
	tre.n=tre2.n=tre3.n=n;
	rep1(k,n)tre2.modify(k,1);
	rep1(k,n)tre3.modify(k,1);
	rep(k,b){
		scanf("%d",&dat[k]);
		if(dat[k]<forb){
			printf("-1\n");
			return 0;
		}
		forb=max(forb,tre.last1(dat[k]));
		tre.modify(dat[k],1);
		tre2.modify(n+1-dat[k],-1);
		tre3.modify(dat[k],-1);
	}
	for(int k=b;k<n;k++){
		int l=forb,r=n+1;
		while(l<r){
			int mid=(l+r)>>1;
			int dm=tre3.last1(mid);
			tre2.modify(n+1-dm,-1);
			if(tre.last1(dm-1)+tre2.last1(n)<=n+1)l=mid+1;
			else r=mid;
			tre2.modify(n+1-dm,1);
		}
		r--;
		dat[k]=tre3.last1(r);
		if(dat[k]<forb){
			printf("-1\n");
			return 0;
		}
		forb=max(forb,tre.last1(dat[k]));
		tre.modify(dat[k],1);
		tre2.modify(n+1-dat[k],-1);
		tre3.modify(dat[k],-1);
	}
	rep(k,n)printf("%d ",dat[k]);
	return 0; 
}