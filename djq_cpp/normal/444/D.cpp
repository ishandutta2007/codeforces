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
vector<int> hv[1000005];
int tohash(string S){
	int bs=1,res=0;
	rep(k,S.length()){
		res+=(S[k]-96)*bs;
		bs*=27;
	}
	return res;
}
string ori;
map<pii,int> ans;
int getans(int a,int b,int la,int lb){
	if(hv[a].size()>hv[b].size()){
		swap(a,b);
		swap(la,lb);
	}
	int ans=INF;
	rep(i,hv[a].size()){
		int j=lower_bound(hv[b].begin(),hv[b].end(),hv[a][i])-hv[b].begin();
		if(j<hv[b].size())ans=min(ans,max(la,hv[b][j]-hv[a][i]+lb));
		if(j>0)ans=min(ans,max(lb,hv[a][i]-hv[b][j-1]+la));
	}
	return ans==INF?-1:ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>ori;
	rep(i,ori.size())rep1(j,4)
	hv[tohash(ori.substr(i,j))].push_back(i);
	int q,a,b;
	cin>>q;
	rep(k,q){
		string s1,s2;
		cin>>s1>>s2;
		a=tohash(s1);b=tohash(s2);
		if(ans.find(MP(a,b))==ans.end())ans[MP(a,b)]=getans(a,b,s1.length(),s2.length());
		cout<<ans[MP(a,b)]<<'\n';
	}
	return 0;
}