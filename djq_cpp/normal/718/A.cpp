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
string sc;
int main(){
	ios::sync_with_stdio(false);
	int L,t;
	cin>>L>>t>>sc;
	int cpos=0;
	while(cpos<L&&sc[cpos]!='.')cpos++;
	do cpos++;
	while(cpos<L&&sc[cpos]<'5');
	if(cpos==L){
		cout<<sc<<'\n';
		return 0;
	}
	while(t&&sc[cpos]>='5'){
		L=cpos--;
		if(sc[cpos]=='.'){
			sc[--cpos]++;
			while(cpos>0&&sc[cpos]>'9'){
				sc[cpos]='0';
				sc[--cpos]++;
			}
			if(cpos==0&&sc[cpos]>'9'){
				sc="10"+sc.substr(1);
				L++;
			}
			break;
		}
		sc[cpos]++;
		t--;
	}
	if(sc[L-1]=='.')L--;
	cout<<sc.substr(0,L)<<'\n';
	return 0;
}