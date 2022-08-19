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
const string P="auBlbsr";
string S;
vector<int> pos[128];
int cur[128];
int getnext(int c,bool &have){
	if(cur[c]+1>=int(pos[c].size()))have=false;
	else cur[c]++;
}
int main(){
	memset(cur,-1,sizeof(cur));
	int ans=INF;
	ios::sync_with_stdio(false);
	cin>>S;
	rep(i,S.size())pos[S[i]].push_back(i);
	rep(k,P.size()){
		if(k<=1)ans=min(ans,int(pos[P[k]].size())>>1);
		else ans=min(ans,int(pos[P[k]].size()));
	}
	cout<<ans;
	return 0;
}