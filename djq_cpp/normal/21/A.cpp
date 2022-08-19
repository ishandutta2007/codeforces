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
#define rep1(i,n) for(int i=0;i<(n);i++)
#define MP make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
struct nam{
	char nm[105];
	int len;
	nam(){
		len=0;
	}
	int getnm(int maxl,string end){
		char c;
		int h;
		len=0;
		while(len<=maxl){
			c=getchar();
			h=end.find(c);
			if(h!=-1)return len==0?-1:h;
			nm[len++]=c;
		}
		len=maxl;
		return -1;
	}
	bool check(string s){
		rep(k,len)
		if(s.find(nm[k])==-1)return false;
		return true;
	}
};
void error(){
	printf("NO");
	exit(0);
}
const string all_ucase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string all_lcase="abcdefghijklmnopqrstuvwxyz";
const string all_dig="1234567890";
const string all_let=all_ucase+all_lcase+all_dig+"_";
nam user,rsour,host;
int main(){
	if(user.getnm(16,"@\n")!=0)error();
	int t=host.getnm(32,"/\n");
	if(t==-1)error();
	if(t==0){
		if(rsour.getnm(16,"\n")==-1)error();
		if(!rsour.check(all_let))error();
	}
	if(!user.check(all_let)||!host.check(all_let+'.'))error();
	vector<int>v;
	v.push_back(-1);
	rep(k,host.len)
	if(host.nm[k]=='.')v.push_back(k);
	v.push_back(host.len);
	if(v.size()==2){
		printf("YES");
		return 0;
	}
	for(int k=1;k<v.size();k++)
	if(v[k]-v[k-1]<2||v[k]-v[k-1]>17)error();
	printf("YES");
	return 0;
}