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
vector<pii> have[1000005];
ll fact(ll num){
	ll ans=1ll;
	for(ll k=2ll;k<=num;k++){
		ans*=k;
		ans%=ll(INF);
	}
	return ans;
}
int main(){
	int n,m,g,x;
	scanf("%d%d",&n,&m);
	rep(i,n){
		map<int,int> cnt;
		scanf("%d",&g);
		rep(j,g){
			scanf("%d",&x);
			cnt[x-1]++;
		}
		for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++)
		have[it->first].push_back(MP(i,it->second));
	}
	sort(have,have+m);
	int T=1;
	ll ans=1;
	have[m].push_back(MP(-1,-1));
	rep1(k,m){
		if(have[k]==have[k-1])T++;
		else{
			ans*=fact(ll(T));
			ans%=ll(INF);
			T=1;
		}
	}
	printf("%d",ans);
	return 0;
}