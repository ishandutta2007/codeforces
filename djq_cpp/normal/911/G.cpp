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
struct BITSET{
	int dat[6333];
	void clear(){
		memset(dat,0,sizeof(dat));
	}
	BITSET(){
		clear();
	}
	void addnew(int l,int r){
		int bl=l>>5,br=r>>5;
		if(bl==br){
			for(int k=l;k<=r;k++)dat[bl]|=1<<k-(bl<<5);
			return;
		}
		for(int k=l;k<(bl+1<<5);k++)dat[bl]|=1<<k-(bl<<5);
		for(int k=br<<5;k<=r;k++)dat[br]|=1<<k-(br<<5);
		for(int k=bl+1;k<br;k++)dat[k]=-1;
	}
	void operator ^=(const BITSET& oth){
		rep(k,6250)dat[k]^=oth.dat[k];
	}
	void operator &=(const BITSET& oth){
		rep(k,6250)dat[k]&=oth.dat[k];
	}
	void operator |=(const BITSET& oth){
		rep(k,6250)dat[k]|=oth.dat[k];
	}
	bool operator [](const int& pos){
		return dat[pos>>5]>>(pos&31)&1;
	}
}cnt[105],cur;
int main(){
	int n,q,l,r,x,y;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d",&x);
		cnt[x].addnew(k,k);
	}
	scanf("%d",&q);
	rep(k,q){
		scanf("%d%d%d%d",&l,&r,&x,&y);
		cur.clear();
		cur.addnew(l-1,r-1);
		cur&=cnt[x];
		cnt[x]^=cur;
		cnt[y]|=cur;
	}
	rep(i,n)rep1(j,100)
	if(cnt[j][i])printf("%d ",j);
	return 0;
}