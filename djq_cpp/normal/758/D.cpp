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
string num;
vector<int> ans;
int TONUM(string s){
	int ans=0;
	rep(k,s.length())
	ans=ans*10+s[k]-'0';
	return ans;
}
bool smaller(string S,int num){
	if(S.length()>=10)return false;
	return TONUM(S)<num;
}
int main(){
	int B;
	cin>>B>>num;
	for(int k=num.size()-1;k>=0;){
		string cur,rc;
		int j=k,rj;
		while(smaller(cur,B)){
			if(cur.length()<=1||cur[0]!='0'){
				rj=j;
				rc=cur;
			}
			if(j<0)break;
			cur=num[j]+cur;
			j--;
		}
		ans.push_back(TONUM(rc));
		k=rj;
	}
	ll res=0ll;
	for(int k=ans.size()-1;k>=0;k--)
	res=res*ll(B)+ll(ans[k]);
	printf("%I64d",res);
	return 0;
}