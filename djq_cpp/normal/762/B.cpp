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
multiset<ll> USB,PS2;
bool getT(){
	getchar();
	bool res=getchar()=='U';
	while(getchar()!='\n');
	return res;
}
ll lowest(){
	if(!USB.empty()&&!PS2.empty()){
			ll c=min(*USB.begin(),*PS2.begin());
			if(c==*USB.begin()){
				USB.erase(USB.begin());
				return c;
			}else{
				PS2.erase(PS2.begin());
				return c;
			}
	}else if(USB.empty()){
		if(PS2.empty())return -1ll;
		ll c=*PS2.begin();
		PS2.erase(PS2.begin());
		return c;
	}else{
		ll c=*USB.begin();
		USB.erase(USB.begin());
		return c;
	}
}
ll must(multiset<ll> &S){
	if(S.empty())return -1ll;
	ll c=*S.begin();
	S.erase(S.begin());
	return c;
}
bool addup(ll& a,ll b){
	if(b==-1ll)return false;
	a+=b;
	return true;
}
ll solve(int a,int b,int c,int &s){
	ll ans=0ll;
	while(a--&&addup(ans,must(USB)))s++;
	while(b--&&addup(ans,must(PS2)))s++;
	while(c--&&addup(ans,lowest()))s++;
	return ans;
}
int main(){
	int a,b,c,m,v,s=0;
	scanf("%d%d%d%d",&a,&b,&c,&m);
	rep(k,m){
		scanf("%d",&v);
		if(getT())USB.insert(ll(v));
		else PS2.insert(ll(v));
	}
	ll ans=solve(a,b,c,s);
	printf("%d %I64d",s,ans);
	return 0;
}