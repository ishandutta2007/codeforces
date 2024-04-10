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
const int MAXN=1000000; //O(n)
int n,Z[MAXN+5],cnt[MAXN+5];
char seq[MAXN+5];
void getZ(){
	int F=-1,R=-1;
	Z[0]=n;
	for(int k=1;k<n;k++){
		if(R<=k){
			for(Z[k]=0;k+Z[k]<n&&seq[Z[k]]==seq[k+Z[k]];Z[k]++);
			if(k+Z[k]>=R){
				R=k+Z[k];
				F=k;
			}
		}else{
			Z[k]=min(Z[k-F],R-k);
			if(k+Z[k]>=R){
				R=k+Z[k];
				F=k;
				for(;k+Z[k]<n&&seq[Z[k]]==seq[k+Z[k]];Z[k]++);
			}
		}
	}
}
int main(){
	scanf("%s",seq);
	n=strlen(seq);
	getZ();
	rep(k,n)cnt[Z[k]]++;
	for(int k=n-1;k>=0;k--)cnt[k]+=cnt[k+1];
	rep(i,n)
	if(i+Z[i]==n&&cnt[Z[i]]>=3){
		rep(j,Z[i])putchar(seq[j]);
		return 0;
	}
	printf("Just a legend");
	return 0;
}