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
int pw2[100005];
int mo[100005],cnt[100005];
int main(){
	int n,x,ans=0;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d",&x);
		cnt[x]++;
	}
	pw2[0]=0;rep1(k,100000)pw2[k]=(pw2[k-1]*2+1)%INF;
	mo[1]=1;rep1(i,100000)for(int j=i+i;j<=100000;j+=i)mo[j]-=mo[i];
	rep1(i,100000){
		x=0;
		for(int j=i;j<=100000;j+=i)x+=cnt[j];
		ans=(ans+mo[i]*pw2[x])%INF;
		if(ans<0)ans+=INF;
	}
	printf("%d\n",ans);
	return 0;
}