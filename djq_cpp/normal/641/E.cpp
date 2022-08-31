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
vector<int> BIT[100005];
map<int,int> rid;
map<int,int> T[100005];
int ty[100005],ti[100005],x[100005];
int query(int i,int x){
	int ans=0;
	while(x>0){
		ans+=BIT[i][x];
		x-=x&(-x);
	}
	return ans;
}
void modify(int i,int id,int v){
	while(id<BIT[i].size()){
		BIT[i][id]+=v;
		id+=id&(-id);
	}
}
int main(){
	int n,cnt=0;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d%d%d",&ty[k],&ti[k],&x[k]);
		if(rid.find(x[k])==rid.end()){
			rid[x[k]]=cnt;
			x[k]=cnt;
			cnt++;
		}else x[k]=rid[x[k]];
		T[x[k]][ti[k]]=-1;
	}
	rep(i,cnt){
		int cur=0;
		for(map<int,int>::iterator it=T[i].begin();it!=T[i].end();it++){
			cur++;
			it->second=cur;
		}
		BIT[i].resize(cur+1);
	}
	rep(k,n){
		if(ty[k]==1)modify(x[k],T[x[k]][ti[k]],1);
		else if(ty[k]==2)modify(x[k],T[x[k]][ti[k]],-1);
		else printf("%d\n",query(x[k],T[x[k]][ti[k]]));
	}
	return 0;
}