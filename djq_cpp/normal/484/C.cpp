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
struct cycle{
	vector<int> cur;
	cycle(int n=0){
		cur.resize(n,0);
		rep(k,cur.size())cur[k]=k;
	}
	cycle(const vector<int>& v){
		cur=v;
	}
	cycle(const cycle& c){
		cur=c.cur;
	}
	cycle operator *(const cycle& oth){
		cycle ans(cur.size());
		rep(k,cur.size())ans.cur[k]=cur[oth.cur[k]];
		return ans;
	}
	cycle power(int T) const{
		cycle v=*this,ans(cur.size());
		while(T){
			if(T&1)ans=ans*v;
			v=v*v;
			T>>=1;
		}
		return ans;
	}
};
cycle D_sort(int n,int d,int L){
	cycle ans;
	rep(i,d)for(int j=i;j<L;j+=d)
	ans.cur.push_back(j);
	for(int k=L;k<n;k++)ans.cur.push_back(k);
	return ans;
}
cycle hd_to_bk(int n,int l){
	cycle ans;
	rep(k,n-l)ans.cur.push_back(l+k);
	rep(k,l)ans.cur.push_back(k);
	return ans;
}
char S[1000005],S2[1000005];
int main(){
	int n,m,c,d;
	gets(S);
	n=strlen(S);
	scanf("%d",&m);
	rep(k,m){
		scanf("%d%d",&c,&d);
		cycle C=(D_sort(n,d,c)*hd_to_bk(n,1)).power(n+1-c)*hd_to_bk(n,c-1);
		rep(k,n)S2[k]=S[C.cur[k]];
		rep(k,n)S[k]=S2[k];
		puts(S);
	}
	return 0;
}