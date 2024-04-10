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
struct item{
	int t,d,p,id;
	bool operator <(const item& oth)const{
		return d<oth.d;
	}
}it[105];
int dp[105][2005];
pii prev[105][2005];
void add(deque<pii>& dq,pii v){
	while(!dq.empty()&&dq.front()<v)dq.pop_front();
	dq.push_front(v);
}
void remove(deque<pii>& dq,int v){
	if(dq.back().second==v)dq.pop_back();
}
int main(){
	int n;
	scanf("%d",&n);
	rep1(k,n){
		scanf("%d%d%d",&it[k].t,&it[k].d,&it[k].p);
		it[k].id=k;
	}
	sort(it+1,it+1+n);
	it[0].d=it[n].d;
	rep1(i,n){
		rep(j,it[i-1].d){
			dp[i][j]=dp[i-1][j];
			prev[i][j]=MP(i-1,j);
		}
		rep(j,it[i-1].d){
			if(j+it[i].t>=it[i].d)break;
			if(dp[i-1][j]+it[i].p>dp[i][j+it[i].t]){
				dp[i][j+it[i].t]=dp[i-1][j]+it[i].p;
				prev[i][j+it[i].t]=MP(i-1,j);
			}
		}
		for(int j=1;j<it[i].d;j++)
		if(dp[i][j]<dp[i][j-1]){
			dp[i][j]=dp[i][j-1];
			prev[i][j]=prev[i][j-1];
		}
	}
	printf("%d\n",dp[n][it[n].d-1]);
	pii cur=MP(n,it[n].d-1);
	vector<int> ans;
	for(int k=n;k>0;k--){
		pii newc=prev[cur.first][cur.second];
		if(cur.second-newc.second>=it[k].t)ans.push_back(it[k].id);
		cur=newc;
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	rep(k,ans.size())printf("%d ",ans[k]);
	return 0;
}