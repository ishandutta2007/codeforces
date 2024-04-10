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
int y,m,d,b[3];
int days[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
bool ok(){
	if(b[1]<1||b[1]>12)return false;
	if(b[2]>days[b[1]]+((b[1]==2&&b[0]%4==0)?1:0))return false;
	return true;
}
int main(){
	pair<int,pii> c,p;
	scanf("%d.%d.%d",&c.second.second,&c.second.first,&c.first);
	scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
	sort(b,b+3);
	do{
		p.first=b[0]+18;
		p.second=MP(b[1],b[2]);
		if(ok()&&p<=c){
			printf("YES");
			return 0;
		}
	}while(next_permutation(b,b+3));
	printf("NO");
	return 0;
}