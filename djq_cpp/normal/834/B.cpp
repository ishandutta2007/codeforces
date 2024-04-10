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
int beg[26],end[26],cnt[1000005];
string S;
int main(){
	memset(beg,-1,sizeof(beg));
	ios::sync_with_stdio(false);
	int n,g;
	cin>>n>>g>>S;
	rep(k,n){
		if(beg[S[k]-'A']==-1)beg[S[k]-'A']=k;
		end[S[k]-'A']=k;
	}
	rep(k,26){
		if(beg[k]==-1)continue;
		cnt[beg[k]]++;
		cnt[end[k]+1]--;
	}
	int cur=0;
	rep(k,n){
		cur+=cnt[k];
		if(cur>g){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}