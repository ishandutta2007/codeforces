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
int minr[3],maxr[3];
int main(){
	rep1(k,2){
		minr[k]=INF;
		maxr[k]=-INF;
	}
	int n,r,d,cur=0;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d%d",&r,&d);
		minr[d]=min(minr[d],cur);
		maxr[d]=max(maxr[d],cur);
		cur+=r;
	}
	if(minr[1]==INF)printf("%d",1899-maxr[2]+cur);
	else if(minr[2]==INF)printf("Infinity");
	else{
		if(minr[1]<=maxr[2])printf("Impossible");
		else printf("%d",1899-maxr[2]+cur);
	}
	return 0;
}