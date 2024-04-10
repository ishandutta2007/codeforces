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
#define cindy(i,n) for(int i=0;i<(n);i++)
#define cindy1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
int main(){
	int n,a,b,b1=0,t,ans=0;
	scanf("%d%d%d",&n,&a,&b);
	cindy(k,n){
		scanf("%d",&t);
		if(t==1){
			if(a>0)a--;
			else if(b>0)b--,b1++;
			else if(b1>0)b1--;
			else ans++;
		}else{
			if(b>0)b--;
			else ans+=2;
		}
	}
	printf("%d",ans);
	return 0;
}