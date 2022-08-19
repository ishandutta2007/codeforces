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
		ans=(char)(n%10+'0')+ans;
		n/=10;
	}while(n);
	return ans;
}
string from_ll(ll n){
	string ans;
	do{
		ans=(char)(n%10+'0')+ans;
		n/=10;
	}while(n);
	return ans;
}
template<typename T>
T power(T num,int times){
	T ans=1,powt=num;
	while(times){
		if(times&1)ans*=powt;
		powt*=powt;
		times>>=1;
	}
	return ans;
}
template<typename T>
T pow_mod(T num,int times,T mod){
	T ans=1,powt=num;
	while(times){
		if(times&1){
			ans*=powt;
			ans%=mod;
		}
		powt*=powt;
		powt%=mod;
		times>>=1;
	}
	return ans;
}
template<typename T>
T gcd(T m,T n){
	return n?gcd(n,m%n):m;
}
map<string,int>num;
int sc[5],mat[5],goal[5],mis[5];
string name[5];
bool cmp(int x,int y){
	if(sc[x]!=sc[y])return sc[x]>sc[y];
	if(goal[x]-mis[x]!=goal[y]-mis[y])return goal[x]-mis[x]>goal[y]-mis[y];
	if(goal[x]!=goal[y])return goal[x]>goal[y];
	return name[x]<name[y];
}
int main(){
	string sa,sb;
	int x,y,a,b,berl,less,ns=0;
	rep(k,5){
		getline(cin,sa,' ');
		getline(cin,sb,' ');
		scanf("%d:%d",&x,&y);
		if(!num[sa]){
			num[sa]=(++ns);
			name[ns]=sa;
		}
		if(!num[sb]){
			num[sb]=(++ns);
			name[ns]=sb;
		}
		a=num[sa];b=num[sb];
		sc[a]+=x>y?3:(x<y?0:1);
		sc[b]+=x<y?3:(x>y?0:1);
		goal[a]+=x;goal[b]+=y;
		mis[a]+=y;mis[b]+=x;
		mat[a]++;mat[b]++;
		getchar();
	}
	map<string,int>::iterator it=num.begin();
	REPup(k,1,4){
		if(it->first=="BERLAND")berl=it->second;
		else if(mat[it->second]==2)less=it->second;
		it++;
	}
	sc[berl]+=3;
	REPup(i,1,40)rep(j,40-i){
		int k=i+j;
		goal[berl]+=k;goal[less]+=j;
		mis[berl]+=j;mis[less]+=k;
		int before=0;
		REPup(f,1,4){
			if(f==berl)continue;
			if(cmp(berl,f))before++;
		}
		if(before>1){
			printf("%d:%d",k,j);
			return 0;
		}
		goal[berl]-=k;goal[less]-=j;
		mis[berl]-=j;mis[less]-=k;
	}
	printf("IMPOSSIBLE");
	return 0;
}