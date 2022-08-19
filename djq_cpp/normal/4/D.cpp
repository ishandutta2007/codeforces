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
vector<pair<pii,int> > ob;
int dp[5005],prev[5005];
int main(){
	int n,wp,hp;
	scanf("%d%d%d",&n,&wp,&hp);
	rep(k,n){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>wp&&y>hp)ob.push_back(MP(MP(x,y),k+1));
		prev[k]=-1;
	}
	if(ob.empty()){
		putchar('0');
		return 0;
	}
	n=ob.size();
	rep(k,n)dp[k]=1;
	sort(ob.begin(),ob.end());
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++)
		if(ob[i].ST.ST!=ob[j].ST.ST&&ob[j].ST.ND<ob[i].ST.ND&&dp[j]+1>dp[i]){
			prev[i]=j;
			dp[i]=dp[j]+1;
		}
	}
	int ans=0;
	for(int k=0;k<n;k++)
	if(dp[k]>dp[ans])ans=k;
	printf("%d\n",dp[ans]);
	stack<int>st;
	while(ans!=-1){
		st.push(ob[ans].ND);
		ans=prev[ans];
	}
	while(!st.empty()){
		printf("%d ",st.top());
		st.pop();
	}
	return 0;
}