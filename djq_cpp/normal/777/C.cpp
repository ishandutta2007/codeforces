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
set<pii> nd[100005];
vector<int> num[100005];
int to[100005];
int main(){
	int n,m,x,l,r;
	scanf("%d%d",&n,&m);
	rep(i,n)rep(j,m){
		scanf("%d",&x);
		num[i].push_back(x);
	}
	rep(j,m){
		int cur=0;
		for(int i=1;i<n;i++)
		if(num[i][j]<num[i-1][j]){
			to[cur]=max(to[cur],i-1);
			cur=i;
		}
		to[cur]=max(to[cur],n-1);
	}
	for(int k=1;k<n;k++)to[k]=max(to[k],to[k-1]);
	scanf("%d",&x);
	while(x--){
		scanf("%d%d",&l,&r);l--;r--;
		if(to[l]>=r)puts("Yes");
		else puts("No");
	}
	return 0;
}