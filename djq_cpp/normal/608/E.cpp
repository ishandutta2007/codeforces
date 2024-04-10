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
const int MAXN=1000000,MODS=5;
char s1[MAXN+5],s2[MAXN+5];
int n,TO[128];
long long H1[10],H2[10],t[10]={1LL,1LL,1LL,1LL,1LL},
		  MOD[10]={1000003LL,1000000007LL,23333LL,23333333333LL,23333333333333333LL};
int main(){
	TO['N']=0;TO['S']=1;TO['E']=2;TO['W']=3;
	scanf("%d%s%s",&n,s1,s2);n--;
	for(int k=n-1;k>=0;k--){
		rep(i,MODS){
			H1[i]=(H1[i]+t[i]*ll(TO[s1[k]]))%MOD[i];
			H2[i]=(H2[i]*4LL+ll(TO[s2[k]]^1))%MOD[i];
			t[i]=(t[i]*4LL)%MOD[i];
		}
		int cnt=0;
		rep(i,MODS)if(H1[i]==H2[i])cnt++;
		if(cnt==MODS){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}