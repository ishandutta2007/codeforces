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
bool UPPER(char c){
	return c>='A'&&c<='Z';
}
bool DIGIT(char c){
	return c>='0'&&c<='9';
}
bool checkrc(string s){
	int plc=s.find('C');
	if(plc<1||plc>s.length()-2)return false;
	return DIGIT(s[plc-1])&&DIGIT(s[plc+1]);
}
string ntos(int n){
	string ans;
	while(n){
		n--;
		ans=(char)(n%26+'A')+ans;
		n/=26;
	}
	return ans;
}
string rctoth(string s){
	int plc=s.find('C'),c=0;
	string r;
	for(int k=1;k<plc;k++)r.push_back(s[k]);
	for(int k=plc+1;k<s.length();k++)c=c*10+s[k]-'0';
	return ntos(c)+r;
}
int ston(string s){
	int sum=0;
	rep(k,s.length()){
		sum*=26;
		sum+=s[k]-64;
	}
	return sum;
}
string thtorc(string s){
	string s1,s2;
	int k,c;
	for(k=0;k<s.length();k++){
		if(!UPPER(s[k]))break;
		s1.push_back(s[k]);
	}
	s2=s.substr(k);
	c=ston(s1);
	s1.clear();
	while(c){
		s1=(char)(c%10+'0')+s1;
		c/=10;
	}
	return "R"+s2+"C"+s1;
}
void getstr(string &str){
	char c;
	str.clear();
	while(1){
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
	putchar('\n');
}
int main(){
	int T;
	string str;
	scanf("%d",&T);
	while(T--){
		getstr(str);
		if(checkrc(str))str=rctoth(str);
		else str=thtorc(str);
		putstr(str);
	}
	return 0;
}