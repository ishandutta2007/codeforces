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
int num[10],dep,to;
string ans[10];
string valnam(int cur){
	return string("e")+char(cur+'a')+'x';
}
void getmul(int cur,int from,int d){
	ans[cur]=string("lea ")+valnam(cur)+", ["+char(d+'0')+'*'+valnam(from)+']';
}
void getadd(int cur,int fc,int fnc,int d){
	ans[cur]=string("lea ")+valnam(cur)+", ["+valnam(fnc)+" + "+char(d+'0')+'*'+valnam(fc)+']';
}
bool dfs(int cur){
	if(num[cur-1]==to)return true;
	if(num[cur-1]>to)return false;
	if(cur>dep)return false;
	rep(i,cur)rep1(j,3){
		num[cur]=num[i]<<j;
		if(num[cur]>num[cur-1]){
			getmul(cur,i,1<<j);
			if(dfs(cur+1))return true;
		}
	}
	rep(i,cur)rep(j,cur)rep(k,4){
		if(k==0&&i>=j)continue;
		num[cur]=(num[i]<<k)+num[j];
		if(num[cur]>num[cur-1]){
			getadd(cur,i,j,1<<k);
			if(dfs(cur+1))return true;
		}
	}
	return false;
}
int main(){
	scanf("%d",&to);
	num[0]=1;
	for(;!dfs(1);dep++);
	cout<<dep<<'\n';
	rep1(k,dep)cout<<ans[k]<<'\n';
	return 0;
}