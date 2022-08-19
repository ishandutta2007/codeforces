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
int h,n,a[100005],bpos[100005],p1[200005],p2[200005];
int main(){
	scanf("%d",&h);
	rep(k,h+1){
		scanf("%d",&a[k]);
		bpos[k]=n;
		n+=a[k];
	}
	rep(k,h)if(a[k]>1&&a[k+1]>1){
		p1[0]=p2[0]=-1;
		rep1(i,h)rep(j,a[i])p1[j+bpos[i]]=p2[j+bpos[i]]=bpos[i-1];
		rep(j,a[k+1])p2[j+bpos[k+1]]=j==0?bpos[k]:bpos[k]+1;
		printf("ambiguous\n");
		rep(k,n)printf("%d ",p1[k]+1);putchar('\n');
		rep(k,n)printf("%d ",p2[k]+1);putchar('\n');
		return 0;
	}
	printf("perfect\n");
	return 0;
}