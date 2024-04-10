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
string S[500005];
int COMPARE(string &s1,string &s2){
	rep(k,min(s1.length(),s2.length())){
		if(s1[k]==s2[k])continue;
		if(s1[k]<s2[k])return -1;
		else return k;
	}
	if(s1.length()<=s2.length())return -1;
	else return s2.length();
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	rep(k,n)cin>>S[k];
	for(int k=n-2;k>=0;k--){
		int cur=COMPARE(S[k],S[k+1]);
		if(cur!=-1)S[k]=S[k].substr(0,cur);
	}
	rep(k,n)cout<<S[k]<<'\n';
	return 0;
}