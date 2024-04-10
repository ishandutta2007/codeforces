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
const string vs="aeiou";
const string format[4]={"aaaa","aabb","abab","abba"};
const int fol[4][4]={{0,0,0,0},{0,0,2,2},{0,1,0,1},{0,1,1,0}};
string ln[4],endstr[4];
int fapp[4],sum;
void getstr(string &str){
	char c;
	str.clear();
	while(true){
		c=getchar();
		if(c!=' '&&c!='\n')break;
	}
	while(c!=' '&&c!='\n'){
		str.push_back(c);
		c=getchar();
	}
}
void putstr(string str){
	rep(k,str.length())
	putchar(str[k]);
}
string getnst(string str){
	int sv=0;
	for(int ptr=str.length()-1;ptr>=0;ptr--){
		int h=vs.find(str[ptr]);
		if(h!=-1)sv++;
		if(sv==sum)return str.substr(ptr,str.length()-ptr);
	}
	return "";
}
int check(){
	rep(k,4)if(endstr[k].empty())return -1;
	rep(i,4){
		bool isok=true;
		rep(j,4)
		if(endstr[j]!=endstr[fol[i][j]]){
			isok=false;
			break;
		}
		if(isok)return i;
	}
	return -1;
}
int getans(){
	rep(k,4)endstr[k]=getnst(ln[k]);
	return check();
}
int main(){
	int T,ans=0;
	scanf("%d%d",&T,&sum);
	while(T--){
		rep(k,4)getstr(ln[k]);
		int res=getans();
		if(res==-1||(res&&ans&&res!=ans)){
			putstr("NO");
			return 0;
		}
		if(ans==0)ans=res;
	}
	putstr(format[ans]);
	return 0;
}