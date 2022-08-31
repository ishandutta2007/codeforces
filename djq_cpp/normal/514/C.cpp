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
const int INF=1e9+7,CUT=150;
vector<string> data[600005];
vector<pair<string,int> > query[600005];
bool ans[300005];
bool canfind(vector<string> &v,string &S){
	int pos=lower_bound(v.begin(),v.end(),S)-v.begin();
	return pos<v.size()&&v[pos]==S;
}
bool check_type1(int L,string &S){
	rep(k,L){
		for(char z='a';z<='c';z++){
			if(S[k]==z)continue;
			char tmp=S[k];
			S[k]=z;
			if(canfind(data[L],S))return true;
			S[k]=tmp;
		}
	}
	return false;
}
int diff(string &S1,string &S2){
	int ans=0;
	rep(k,S1.length())
	if(S1[k]!=S2[k])ans++;
	return ans;
}
bool check_type2(int L,string &S){
	rep(k,data[L].size())
	if(diff(data[L][k],S)==1)return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	int n,q,MAXL=0;
	string S;
	cin>>n>>q;
	rep(k,n){
		cin>>S;
		data[S.length()].push_back(S);
	}
	rep(k,q){
		cin>>S;
		query[S.length()].push_back(MP(S,k));
		MAXL=max(MAXL,int(S.length()));
	}
	for(int i=1;i<CUT;i++){
		sort(data[i].begin(),data[i].end());
		rep(j,query[i].size())
		ans[query[i][j].second]=check_type1(i,query[i][j].first); 
	}
	for(int i=CUT;i<=MAXL;i++){
		rep(j,query[i].size())
		ans[query[i][j].second]=check_type2(i,query[i][j].first);
	} 
	rep(k,q)if(ans[k])cout<<"YES\n";else cout<<"NO\n";
	return 0;
}