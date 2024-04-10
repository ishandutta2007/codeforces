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
bool chk(int n){
	int B=0,c;
	string dir;
	rep(k,n){
		cin>>c>>dir;
		if(B==0&&dir!="South")return false;
		if(B==20000&&dir!="North")return false;
		if(dir=="South"){
			B+=c;
			if(B>20000)return false;
		}
		if(dir=="North"){
			B-=c;
			if(B<0)return false;
		}
	}
	return B==0;
}
int main(){
	int n;
	cin>>n;
	if(chk(n))cout<<"YES";
	else cout<<"NO";
	return 0;
}