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
#define open_in(n) freopen(n,"r",stdin)
#define open_out(n) freopen(n,"w",stdout)
#define debug(x) cerr<<#x<<'='<<x<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define REPup(i,m,n) for(int i=(m);i<=(n);i++)
#define REPdn(i,m,n) for(int i=(m);i>=(n);i--)
#define FOR(i,m,n,t) for(int i=(m);((t)>0)?(i<=(n)):(i>=(n));i+=t)
#define for_all(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
#define ALL(n) n.begin,n.end
#define SIZE(n) (int)((n).size())
#define PB push_back
#define MP make_pair
#define IT iterator
#define ST first
#define ND second
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<string,int> strarr;
const int inf=1e9+7;
const long long linf=1e17+7;
const float eps=1e-5;
const double leps=1e-9;
const long double lleps=1e-17;
const float pi=3.1416;
double diagonal(double x,double y){return sqrt((x)*(x)+(y)*(y));}
void quit(){exit(0);}
int from_str(char *ch){
	if(strlen(ch)==0)return 0;
	int sum=0,f=(ch[0]=='-'?-1:1);
	rep(k,strlen(ch)){
		if(!isdigit(ch[k]))continue;
		sum=sum*10+(ch[k]-'0')*f;
	}
	return sum;
}
ll from_strL(char *ch){
	if(strlen(ch)==0)return 0;
	ll sum=0,f=(ch[0]=='-'?-1:1);
	rep(k,strlen(ch)){
		if(!isdigit(ch[k]))continue;
		sum=sum*10+(ch[k]-'0')*f;
	}
	return sum;
}
int from_str(string ch){
	if(ch.empty())return 0;
	int sum=0,f=(ch[0]=='-'?-1:1);
	rep(k,ch.length()){
		if(!isdigit(ch[k]))continue;
		sum=sum*10+(ch[k]-'0')*f;
	}
	return sum;
}
ll from_strL(string ch){
	if(ch.empty())return 0;
	ll sum=0,f=(ch[0]=='-'?-1:1);
	rep(k,ch.length()){
		if(!isdigit(ch[k]))continue;
		sum=sum*10+(ch[k]-'0')*f;
	}
	return sum;
}
char* from_intC(int n){
	char ch[11];
	int all=0;
	do{
		ch[all++]=n%10+'0';
		n/=10;
	}while(n);
	char *ans=new char[all];
	rep(k,all)ans[k]=ch[all-1-k];
	return ans;
}

char* from_llC(ll n){
	char ch[20];
	int all=0;
	do{
		ch[all++]=n%10+'0';
		n/=10;
	}while(n);
	char *ans=new char[all];
	rep(k,all)ans[k]=ch[all-1-k];
	return ans;
}
string from_int(int n){
	string ans;
	do{
		ans.push_back(n%10+'0');
		n/=10;
	}while(n);
	return ans;
}
string from_ll(ll n){
	string ans;
	do{
		ans.push_back(n%10+'0');
		n/=10;
	}while(n);
	return ans;
}
int cols[3];
char stoi[128];
int itos[3]={'R','G','B'};
int main(){
	stoi['R']=0;
	stoi['G']=1;
	stoi['B']=2;
	int n;
	scanf("%d",&n);
	getchar();
	rep(k,n){
		char in=getchar();
		cols[stoi[in]]++;
	}
	int sum=0;
	rep(k,3)sum+=(bool)(cols[k]);
	if(sum==3){
		puts("BGR");
		return 0;
	}
	if(sum==1){
		putchar(cols[0]?'R':(cols[1]?'G':'B'));
		return 0;
	}
	vector<int>m1;
	int melse;
	rep(k,3)
	if(cols[k]){
		if(cols[k]==1)m1.push_back(k);
	}else melse=k;
	if(m1.size()==2)putchar(itos[melse]);
	else if(m1.size()==0)puts("BGR");
	else{
		char x=itos[m1[0]],y=itos[melse];
		putchar(min(x,y));
		putchar(max(x,y));
	}
	return 0;
}