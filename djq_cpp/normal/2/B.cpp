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
template<typename T>T abs(T n){return n>(T)(0)?n:-n;}
template<typename T>void swap(T &a,T &b){T t=a;a=b;b=t;}
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
string res;
pii mp[1005][1005];
int ans[2][1005][1005];
pii prev[2][1005][1005];
void print(pii plc,bool t){
	if(plc==MP(0,0))return;
	pii last=MP(prev[t][plc.ST][plc.ND].ST,prev[t][plc.ST][plc.ND].ND);
	print(last,t);
	if(last.ST!=plc.ST)putchar('D');
	else putchar('R');
}
pii zero(int n){
	pii ans=MP(0,0);
	while(n%2==0){
		ans.ST++;
		n/=2;
	}
	while(n%5==0){
		ans.ND++;
		n/=5;
	} 
	return ans;
}
int main(){
	int n,in;
	int x0,y0;
	bool if0=false;
	scanf("%d",&n);
	rep(i,n)rep(j,n){
		scanf("%d",&in);
		if(in==0){
			mp[i][j]=MP(-1,-1);
			if(if0)continue;
			if0=true;
			x0=i;y0=j;
		}else mp[i][j]=zero(in);
	}
	if(mp[0][0]==MP(-1,-1)||mp[n-1][n-1]==MP(-1,-1)){
		puts("1");
		REPup(k,2,n)putchar('R');
		REPup(k,2,n)putchar('D');
		return 0;
	}
	rep(i,n)rep(j,n)
	ans[0][i][j]=ans[1][i][j]=inf;
	ans[0][0][0]=mp[0][0].ST;
	ans[1][0][0]=mp[0][0].ND;
	rep(i,n)rep(j,n){
		if(mp[i+1][j]!=MP(-1,-1)){
			if(ans[0][i][j]+mp[i+1][j].ST<ans[0][i+1][j]){
				ans[0][i+1][j]=ans[0][i][j]+mp[i+1][j].ST;
				prev[0][i+1][j]=MP(i,j);
			}
			if(ans[1][i][j]+mp[i+1][j].ND<ans[1][i+1][j]){
				ans[1][i+1][j]=ans[1][i][j]+mp[i+1][j].ND;
				prev[1][i+1][j]=MP(i,j);
			}
		}
		if(mp[i][j+1]!=MP(-1,-1)){
			if(ans[0][i][j]+mp[i][j+1].ST<ans[0][i][j+1]){
				ans[0][i][j+1]=ans[0][i][j]+mp[i][j+1].ST;
				prev[0][i][j+1]=MP(i,j);
			}
			if(ans[1][i][j]+mp[i][j+1].ND<ans[1][i][j+1]){
				ans[1][i][j+1]=ans[1][i][j]+mp[i][j+1].ND;
				prev[1][i][j+1]=MP(i,j);
			}
		}
	}
	int x=ans[0][n-1][n-1],y=ans[1][n-1][n-1];
	if(x>1&&y>1&&if0){
		puts("1");
		REPup(k,1,x0)putchar('D');
		REPup(k,1,y0)putchar('R');
		REPup(k,x0+1,n-1)putchar('D');
		REPup(k,y0+1,n-1)putchar('R');
		return 0;
	}
	printf("%d\n",min(x,y));
	print(MP(n-1,n-1),x<y?0:1);
	return 0;
}