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
#include <conio.h>
#include <memory.h>
#include <windows.h>
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
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
int main(){
	char c;
	bool spc=false,beg=true,fld=false;
	string s;
	while((c=getchar())!='\n'){
		if(c==','){
			if(spc&&fld)s.push_back(' ');
			s=s+',';
			spc=true;
			fld=true;
		}else if(c=='.'){
			getchar();
			getchar();
			if(!beg)s.push_back(' ');
			s=s+"...";
			spc=false;
			fld=true;
		}else if(c==' '){
			if(beg)continue;
			else if(!fld)spc=true;
		}else{
			if(spc)s.push_back(' ');
			s.push_back(c);
			spc=false;
			fld=false;
		}
		beg=false;
	}
	rep(k,s.length())
	putchar(s[k]);
	return 0;
}