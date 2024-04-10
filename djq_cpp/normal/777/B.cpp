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
int Ts[10],Tm[10],T1[10],T2[10];
int main(){
	int n,ans;
	scanf("%d",&n);
	getchar();rep(k,n)Ts[getchar()-'0']++;
	getchar();rep(k,n)Tm[getchar()-'0']++;
	ans=0;
	rep(k,10){
		T1[k]=Tm[k];
		T2[k]=Ts[k];
	}
	rep(i,10){
		for(int j=0;j<=i;j++)
		while(T1[i]>0&&T2[j]>0){
			T1[i]--;
			T2[j]--;
		}
		ans+=T1[i];
	}
	printf("%d\n",ans);
	ans=0;
	rep(k,10){
		T1[k]=Ts[k];
		T2[k]=Tm[k];
	}
	rep(i,10){
		for(int j=i+1;j<10;j++)
		while(T1[i]>0&&T2[j]>0){
			T1[i]--;
			T2[j]--;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}