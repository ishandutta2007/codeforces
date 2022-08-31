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
int n,nxt[1000000][10],have[1000000],cnt=1;
string cd[70005];
void INSERT(int id,string S){
	int cur=0;
	rep(k,S.length()){
		if(nxt[cur][S[k]-'0']==-1)nxt[cur][S[k]-'0']=cnt++;
		cur=nxt[cur][S[k]-'0'];
		if(have[cur]==-1)have[cur]=id;
		else if(have[cur]!=id)have[cur]=-2;
	}
}
int main(){
	memset(have,-1,sizeof(have));
	memset(nxt,-1,sizeof(nxt));
	scanf("%d",&n);
	rep(k,n){
		cin>>cd[k];
		rep(j,cd[k].size())INSERT(k,cd[k].substr(j));
	}
	rep(i,n){
		string ans=cd[i];
		rep(j,cd[i].length()){
			string S=cd[i].substr(j);
			int cur=0;
			rep(k,S.length()){
				cur=nxt[cur][S[k]-'0'];
				if(have[cur]!=-2){
					if(ans.length()>k)ans=S.substr(0,k+1);
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}