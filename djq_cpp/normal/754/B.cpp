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
int sign[10][10];
const int CAN='x'+'x'+'.';
bool check(){
	rep(i,4)rep(j,2){
		if(sign[i][j]+sign[i][j+1]+sign[i][j+2]==CAN)return true;
	}
	rep(i,4)rep(j,2){
		if(sign[j][i]+sign[j+1][i]+sign[j+2][i]==CAN)return true;
	}
	rep(i,2)rep(j,2)
	if(sign[i][j]+sign[i+1][j+1]+sign[i+2][j+2]==CAN)return true;
	rep(i,2)rep(j,2)
	if(sign[i+2][j]+sign[i+1][j+1]+sign[i][j+2]==CAN)return true;
	return false;
}
int main(){
	rep(k,4){
		rep(j,4){
			sign[k][j]=getchar();
			if(sign[k][j]=='o')sign[k][j]=1e6;
		}
		getchar();
	}
	printf(check()?"YES":"NO");
}