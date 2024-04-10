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
const int INF=1e9+7,MOD=1000003;
int dp[1005][2005],rsum[2005];
vector<int> a_s;
string S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>S;
	int cur=0,cnt=0;
	rep(k,S.length()){
		if(S[k]<'0'||S[k]>'9')cur++;
		else if(cur){
			a_s.push_back(cur);
			cur=0;
		}
		if((k==0||S[k-1]<'0'||S[k-1]>'9')&&(S[k]=='*'||S[k]=='/')){
			cout<<0<<endl;
			return 0;
		}
	}
	if(cur){
		cout<<0<<endl;
		return 0;
	}
	dp[0][0]=1;
	rep(i,a_s.size()){
		int cc=a_s[i];
		rsum[0]=dp[i][0];rep1(j,cnt)rsum[j]=(rsum[j-1]+dp[i][j])%MOD;
		for(int j=cnt+cc;j>=0;j--)
		dp[i+1][j]=(j<=cc?rsum[cnt]:(rsum[cnt]-rsum[j-cc-1]+MOD)%MOD);
		cnt+=cc;
	}
	cout<<dp[a_s.size()][0]<<endl;
	return 0;
}