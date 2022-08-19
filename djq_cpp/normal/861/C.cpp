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
string S;
int main(){
	ios::sync_with_stdio(false);
	cin>>S;
	char sam=' ';
	int cnt=0;
	rep(k,S.length()){
		if(S[k]=='a'||S[k]=='e'||S[k]=='i'||S[k]=='o'||S[k]=='u'){
			putchar(S[k]);
			sam=' ';
			cnt=0;
			continue;
		}
		if(sam==' ')sam=S[k];
		else if(sam!=S[k])sam='/';
		cnt++;
		if(cnt>=3&&sam=='/'){
			putchar(' ');
			sam=S[k];
			cnt=1;
		}
		putchar(S[k]);
	}
	return 0;
}