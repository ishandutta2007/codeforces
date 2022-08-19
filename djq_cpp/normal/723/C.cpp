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
vector<int> S[2005];
int num[2005];
multiset<int> can;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(k,n){
		scanf("%d",&num[k]);
		if(num[k]>m)S[0].push_back(k);
		else S[num[k]].push_back(k);
	}
	int ans=n/m,ch=0;
	rep1(k,m)rep(j,ans-int(S[k].size()))can.insert(k);
	rep(k,int(S[0].size())){
		if(can.empty())break;
		int t=*can.begin();
		num[S[0][k]]=t;
		S[t].push_back(k);
		can.erase(can.begin());
		ch++;
	}
	rep1(k,m)rep(j,int(S[k].size())-ans){
		if(can.empty())break;
		num[S[k][j]]=*can.begin();
		can.erase(can.begin());
		ch++;
	}
	printf("%d %d\n",ans,ch);
	rep(k,n)printf("%d ",num[k]);
	return 0;
}