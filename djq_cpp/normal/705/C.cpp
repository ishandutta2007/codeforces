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
const int inf=1e9+7;
int num[524288],n,S;
vector<int> have[300005];
bool Read[300005];
vector<int> noti;
int main(){
	int n,m,tmp,x,sum=0,rdd=0;
	scanf("%d%d",&n,&m);
	rep(k,m){
		scanf("%d%d",&tmp,&x);
		if(tmp==1){
			have[x].push_back(noti.size());
			sum++;
			noti.push_back(x);
		}else if(tmp==2){
			rep(k,have[x].size()){
				if(!Read[have[x][k]])sum--;
				Read[have[x][k]]=true;
			}
			have[x].clear();
		}else{
			x=min(x,int(noti.size()));
			for(int k=rdd;k<x;k++)
			if(!Read[k]){
				Read[k]=true;
				sum--;
			}
			rdd=max(rdd,x);
		}
		printf("%d\n",sum);
	}
	return 0;
}