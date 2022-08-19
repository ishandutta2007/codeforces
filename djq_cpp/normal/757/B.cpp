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
int n,num[100005],cnt[100005];
vector<int> divs[100005];
int main(){
	int ans=1;
	scanf("%d",&n);
	rep(k,n)scanf("%d",&num[k]);
	for(int k=2;k<=100000;k++){
		if(divs[k].empty()){
			for(int j=k;j<=100000;j+=k)
			divs[j].push_back(k);
		}
	}
	rep(k,n){
		rep(j,divs[num[k]].size())
		cnt[divs[num[k]][j]]++;
	}
	for(int k=2;k<=100000;k++)
	if(divs[k].size()==1)ans=max(ans,cnt[k]);
	printf("%d",ans);
	return 0;
}