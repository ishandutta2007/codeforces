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
vector<pii> id[3][200005];
int res[100005],tp[100005],p[100005];
int main(){
	int n,w,h,wt;
	scanf("%d%d%d",&n,&w,&h);
	rep1(k,n){
		scanf("%d%d%d",&tp[k],&p[k],&wt);
		id[tp[k]][p[k]-wt+100000].push_back(MP(p[k],k));
	}
	rep1(t,2)rep1(k,200000)sort(id[t][k].begin(),id[t][k].end());
	rep1(k,200000){
		if(id[1][k].empty()&&id[2][k].empty())continue;
		vector<pii> &lg=(id[1][k].size()>id[2][k].size()?id[1][k]:id[2][k]);
		vector<pii> &sl=(id[1][k].size()>id[2][k].size()?id[2][k]:id[1][k]);
		vector<int> cur;
		rep(k,lg.size())cur.push_back(lg[k].second);
		rep(k,sl.size())cur.push_back(sl[k].second);
		reverse(cur.begin(),cur.end());
		reverse(cur.begin()+sl.size()*2,cur.end());
		wt=0;
		rep(k,sl.size())res[cur[wt++]]=lg[k].second;
		rep(k,sl.size())res[cur[wt++]]=sl[k].second;
		rep(k,lg.size()-sl.size())res[cur[wt++]]=lg[k+sl.size()].second;
	}
	rep1(k,n){
		if(tp[res[k]]==1)printf("%d %d\n",p[res[k]],h);
		else printf("%d %d\n",w,p[res[k]]);
	}
	return 0;
}