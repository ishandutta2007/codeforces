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
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
int n,len[10000005];
int getnum(int &ans){
	char c;
	while((c=getchar())==' '||c=='\n');
	while(c>='0'&&c<='9'){
		ans*=10;
		ans+=c-'0';
		c=getchar();
	}
	return ans;
}
int findn(int num){
	int l=0,r=0;
	while(r<n){
		if(len[r]-len[l]==num)return l;
		if(len[r]-len[l]<num)r++;
		else l++;
	}
	return -1;
}
int revfind(int num){
	int r=n-1,l=n-1;
	while(l>=0){
		if(len[r]-len[l]==num)return r;
		if(len[r]-len[l]<num)l--;
		else r--;
	}
	return -1;
}
int main(){
	int l=0,x=0,y=0;
	bool fx=false,fy=false;
	int fadd=-1,fsubs=-1,fsubl=-1;
	getnum(n);getnum(l);getnum(x);getnum(y);
	rep(k,n)getnum(len[k]);
	if(findn(x)!=-1)fx=true;
	if(findn(y)!=-1)fy=true;
	fadd=findn(x+y);
	fsubs=findn(y-x);
	fsubl=revfind(y-x);
	if(fx&&fy)putchar('0');
	else if(fx)printf("1\n%d",y);
	else if(fy)printf("1\n%d",x);
	else if(fadd!=-1)printf("1\n%d",len[fadd]+x);
	else if(fsubs!=-1&&len[fsubs]+y<l)printf("1\n%d",len[fsubs]+y);
	else if(fsubl!=-1&&len[fsubl]-y>0)printf("1\n%d",len[fsubl]-y);
	else printf("2\n%d %d",x,y);
	return 0;
}