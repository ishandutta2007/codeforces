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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
ll dp[10],base[10];
string num;
pair<int,string> Q[100005];
string getstr(char endc){
	char c;
	string S;
	while((c=getchar())!=endc&&c!=EOF)S.push_back(c);
	return S;
}
int getnum(char endc){
	char c;
	int S=0;
	while((c=getchar())!=endc&&c!=EOF)S=S*10+(c-'0');
	return S;
}
int main(){
	int n,q;
	num=getstr('\n');
	n=num.length();
	rep(i,n)num[i]-='0';
	q=getnum('\n');
	for(int i=q;i>0;i--){
		Q[i].first=getnum('-');
		getchar();
		Q[i].second=getstr('\n');
		rep(j,Q[i].second.length())Q[i].second[j]-='0';
	}
	rep(k,10)dp[k]=ll(k);
	rep(k,10)base[k]=10LL;
	rep1(i,q){
		ll cur=0LL,B=1LL;
		for(int j=Q[i].second.length()-1;j>=0;j--){
			cur=(cur+dp[Q[i].second[j]]*B)%INF;
			B=(B*base[Q[i].second[j]])%INF;
		}
		dp[Q[i].first]=cur;
		base[Q[i].first]=B;
	}
	ll cur=0LL,B=1LL;
	for(int j=num.length()-1;j>=0;j--){
		cur=(cur+dp[num[j]]*B)%INF;
		B=(B*base[num[j]])%INF;
	}
	printf("%I64d",cur);
	return 0;
}