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
const int MAXN=1000000;
int n,tree[MAXN+5];
int query(int x){
	int ans=0;
	while(x>0){
		ans+=tree[x];
		x-=x&(-x);
	}
	return ans;
}
int query(int x,int y){
	return query(y)-query(x-1);
}
void modify(int id,int C){
	while(id<=n){
		tree[id]+=C;
		id+=id&(-id);
	}
}
int main(){
	int m,cur=1;
	ll S=1ll;
	scanf("%d%d",&n,&m);
	m=min(m,n-m);
	rep1(k,n){
		int nc=cur+m;
		if(nc>n){
			nc-=n;
			S+=ll(query(cur+1,n)+query(nc-1));
		}else S+=ll(query(cur+1,nc-1));
		modify(cur,1);
		modify(nc,1);
		cur=nc;
		printf("%I64d ",S+ll(k));
	}
	return 0;
}