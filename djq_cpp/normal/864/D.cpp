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
int a[200005],b[200005],cnt[200005],pos[200005];
set<int> rest;
bool got[200005];
int main(){
	int n;
	scanf("%d",&n);
	rep1(k,n){
		scanf("%d",&a[k]);
		cnt[a[k]]++;
		pos[a[k]]=k;
	}
	rep1(k,n)if(cnt[k]==0)rest.insert(k);
	int cpos=1,ans=0;
	rep1(k,n){
		if(!got[a[k]]&&(cnt[a[k]]==1||!rest.empty()&&a[k]<*rest.begin())){
			b[k]=a[k];
			got[a[k]]=true;
		}else{
			b[k]=*rest.begin();
			rest.erase(rest.begin());
		}
		cnt[a[k]]--;
	}
	rep1(k,n)if(a[k]!=b[k])ans++;
	printf("%d\n",ans);
	rep1(k,n)printf("%d ",b[k]);
	return 0;
}