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
int pos[55],cur[55];
int main(){
	int n,L;
	scanf("%d%d",&n,&L);
	rep(k,n)scanf("%d",&pos[k]);
	int fp=0;
	pos[n]=L;
	rep(k,n)scanf("%d",&cur[k]);
	rep(k,L){
		while(pos[fp]<k)fp++;
		bool have=true;
		rep(j,n)if((pos[(fp+j)%n]+L-k)%L!=cur[j]){
			have=false;
			break;
		}
		if(have){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}