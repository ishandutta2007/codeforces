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
const int INF=1e8+7;
string S[55];
int least[5][55];
void update(int t,int i,int j,int L){
	least[t][i]=min(least[t][i],min(j,L-j));
}
int main(){
	int n,L;
	cin>>n>>L;
	rep(k,n)cin>>S[k];
	rep(i,5)rep(j,n)least[i][j]=INF;
	rep(i,n)rep(j,L){
		if(isalpha(S[i][j]))update(0,i,j,L);
		if(isdigit(S[i][j]))update(1,i,j,L);
		if(S[i][j]=='&'||S[i][j]=='*'||S[i][j]=='#')update(2,i,j,L);
	}
	int ans=INF;
	rep(i,n)rep(j,n)rep(k,n){
		if(i==j||j==k||i==k)continue;
		int res=least[0][i]+least[1][j]+least[2][k];
		ans=min(ans,res);
	}
	printf("%d",ans);
	return 0;
}