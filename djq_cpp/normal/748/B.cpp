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
#define chars(i) for(char i='a';i<='z';i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
char TO[128],S1[1005],S2[1005];
bool geted[128];
bool solve(int L){
	chars(k)TO[k]=k,geted[k]=false;
	rep(p,L){
		char c1=S1[p],c2=S2[p];
		if(c1==c2){
			geted[c1]=true;
			if(TO[c1]!=c1)return false;
			continue;
		}
		if(TO[c1]==c1&&TO[c2]==c2){
			if(geted[c1]||geted[c2])return false;
			TO[c1]=c2;
			TO[c2]=c1;
			continue;
		}else if(TO[c1]==c2&&TO[c2]==c1)continue;
		return false;
	}
	return true;
}
int main(){
	gets(S1);
	gets(S2);
	int L=strlen(S1);
	if(solve(L)){
		vector<pair<char,char> > ans;
		chars(k)if(TO[k]!=k){
			ans.push_back(MP(k,TO[k]));
			TO[TO[k]]=TO[k];
			TO[k]=k;
		}
		printf("%d\n",ans.size());
		rep(k,ans.size())
		printf("%c %c\n",ans[k].first,ans[k].second);
	}else printf("-1");
	return 0;
}