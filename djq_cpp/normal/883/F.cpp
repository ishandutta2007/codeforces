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
set<string> S;
int main(){
	ios::sync_with_stdio(false);
	int n,ss;
	string c,cc;
	cin>>n;
	rep(k,n){
		cin>>c;
		ss=0;
		for(int k=c.length()-1;k>=0;k--)
		if(k!=0&&c[k]=='h'&&c[k-1]=='k'){
			c[k-1]='h';ss|=1<<k;continue;
		}
		cc.clear();
		rep(k,c.length())
		if(!(ss>>k&1))cc.push_back(c[k]);
		for(int k=0;k<cc.length();k++)
		if(cc[k]=='u'){
			cc=cc.substr(0,k)+"oo"+cc.substr(k+1);
			k++;
		}
		S.insert(cc);
	}
	cout<<S.size()<<'\n';
	return 0;
}