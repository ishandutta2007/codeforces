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
int n,co,ans,cnt[128];
char ch[400005];
int main(){
	scanf("%d%s",&n,ch);
	rep(k,n)cnt[ch[k]]++;
	rep(k,128)if(cnt[k]&1)co++;
	if(co!=0){
		ans=co;
		while(n%ans||!((n/ans)&1))ans++;
		co=ans;
		vector<char> ne,nn;
		rep(k,128)if(cnt[k]&1){
			ne.push_back(k);
			cnt[k]--;co--;
		}
		rep(k,128)while(co&&cnt[k]){
			ne.push_back(k);
			cnt[k]--;co--;
		}
		rep(k,128)while(cnt[k]){
			nn.push_back(k);cnt[k]-=2;
		}
		int cl=(n/ans-1)/2;
		printf("%d\n",ans);
		rep(i,ans){
			rep(j,cl)putchar(nn[i*cl+j]);
			putchar(ne[i]);
			for(int j=cl-1;j>=0;j--)putchar(nn[i*cl+j]);
			putchar(' ');
		}
	}else{
		printf("1\n");
		vector<char> nn;
		rep(k,128)while(cnt[k]){
			nn.push_back(k);cnt[k]-=2;
		}
		rep(k,nn.size())putchar(nn[k]);
		for(int k=nn.size()-1;k>=0;k--)putchar(nn[k]);
	}
	return 0;
}