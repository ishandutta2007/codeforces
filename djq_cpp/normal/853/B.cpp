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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF=2e12;
vector<pii> dep[1000005],arr[1000005];
ll cd[1000005],ca[1000005],co[100005];
int main(){
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	rep(k,m){
		int t,b,e,c;
		scanf("%d%d%d%d",&t,&b,&e,&c);
		if(b==0)arr[t].push_back(MP(e,c));
		else dep[t].push_back(MP(b,c));
	}
	rep1(k,n)co[k]=INF;
	rep1(k,n)cd[1]+=co[k];
	for(int k=1;k<=1000000;k++){
		cd[k+1]=cd[k];
		rep(j,dep[k].size())
		if(co[dep[k][j].first]>dep[k][j].second){
			cd[k+1]-=co[dep[k][j].first]-dep[k][j].second;
			co[dep[k][j].first]=dep[k][j].second;
		}
	}
	rep1(k,n)co[k]=INF;
	rep1(k,n)ca[1000000]+=co[k];
	for(int k=1000000;k>=1;k--){
		ca[k-1]=ca[k];
		rep(j,arr[k].size())
		if(co[arr[k][j].first]>arr[k][j].second){
			ca[k-1]-=co[arr[k][j].first]-arr[k][j].second;
			co[arr[k][j].first]=arr[k][j].second;
		}
	}
	ll ans=INF;
	for(int k=1;k<=1000000-d;k++)
	ans=min(ans,cd[k]+ca[k+d-1]);
	if(ans==INF)printf("-1\n");
	else printf("%I64d\n",ans);
	return 0;
}