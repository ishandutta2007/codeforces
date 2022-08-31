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
// 
//DRAW
// 
int main(){
	int x1,x2,a,b,c=1;
	cin>>x1>>x2>>a>>b;
	if(x2<x1){
		swap(x1,x2);
		a=-a;b=-b;swap(a,b);c=-1;
	}
	if(a<=0||b<=0){
		if(x2-x1<=b&&x2-x1>=a)cout<<"FIRST\n"<<(c==1?x2:x1);
		else cout<<"DRAW\n";
	}else{
		if(a+b==0)cout<<"DRAW\n";
		else{
			int v1=x2-x1,v2=a+b;
			if(v1%v2==0)cout<<"SECOND\n";
			else if(v1%v2>=a&&v1%v2<=b)cout<<"FIRST\n"<<(c==1?x1:x2)+c*(v1%v2);
			else cout<<"DRAW\n";
		}
	}
	return 0;
}