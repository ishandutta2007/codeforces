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
vector<int> cur,atk,def;
int in_mid(){
	int ans=0;
	rep(i,atk.size()){
		int j=cur.size()-i-1;
		if(j<0||atk[i]>=cur[j])break;
		ans+=cur[j]-atk[i];
	}
	return ans;
}
int destroyed(){
	multiset<int> S;
	int ans=0;
	rep(k,cur.size())S.insert(cur[k]);
	rep(k,def.size()){
		multiset<int>::iterator it=S.upper_bound(def[k]);
		if(it==S.end())return 0;
		else S.erase(it);
	}
	rep(k,atk.size()){
		multiset<int>::iterator it=S.lower_bound(atk[k]);
		if(it==S.end())return 0;
		else{
			ans+=*it-atk[k];
			S.erase(it);
		}
	}
	while(!S.empty()){
		ans+=*S.begin();
		S.erase(S.begin());
	}
	return ans;
}
char ch[10];
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	rep(k,n){
		scanf("%s%d",ch,&x);
		if(ch[0]=='A')atk.push_back(x);
		else def.push_back(x);
	}
	rep(k,m){
		scanf("%d",&x);
		cur.push_back(x);
	}
	sort(cur.begin(),cur.end());
	sort(atk.begin(),atk.end());
	sort(def.begin(),def.end());
	printf("%d\n",max(in_mid(),destroyed()));
	return 0;
}