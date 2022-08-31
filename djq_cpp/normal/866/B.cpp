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
vector<pii> st[2];
int r[2];
int main(){
	int n,s;
	ll ans=0LL;
	scanf("%d%d",&n,&s);
	rep(k,n){
		int ss,a,b;
		scanf("%d%d%d",&ss,&a,&b);
		if(a>=b){
			st[0].push_back(MP(a-b,ss));
			r[0]=(r[0]+ss)%s;
			ans+=ll(a)*ss;
		}else{
			st[1].push_back(MP(b-a,ss));
			r[1]=(r[1]+ss)%s;
			ans+=ll(b)*ss;
		}
	}
	if(r[0]+r[1]>s)printf("%I64d\n",ans);
	else{
		ll ret=0LL;
		rep(i,2){
			ll cur=ans;
			sort(st[i].begin(),st[i].end());
			rep(j,st[i].size())
			if(st[i][j].second>=r[i]){
				cur-=ll(st[i][j].first)*r[i];
				break; 
			}else{
				cur-=ll(st[i][j].first)*st[i][j].second;
				r[i]-=st[i][j].second;
			}
			ret=max(ret,cur);
		}
		printf("%I64d\n",ret);
	}
	return 0;
 
}