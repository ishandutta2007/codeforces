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
map<string,int> code;
bool can[105][105];
int prev[105][105];
vector<string> ans;
string ln[105],nam[105];
void get_sent(int id,string x){
	x.push_back(' ');
	string s2;
	rep(k,x.length()){
		char c=x[k];
		if(isalpha(c)||isdigit(c))s2.push_back(c);
		else{
			if(code.find(s2)!=code.end())can[id][code[s2]]=false;
			s2.clear();
		}
	}
}
bool solve(){
	int n,m;
	string s;
	cin>>n;
	code.clear();
	ans.clear();
	rep(k,n){
		cin>>s;
		nam[k]=s;
		code[s]=k;
	}
	cin>>m;
	cin.ignore();
	rep(k,m){
		getline(cin,s,'\n');
		int pos=s.find_first_of(':');
		ln[k]=s.substr(pos+1);
		s=s.substr(0,pos);
		if(s=="?"){
			rep(p,n)can[k][p]=true;
			get_sent(k,ln[k]);
		}else{
			rep(p,n)can[k][p]=false;
			can[k][code[s]]=true;
		}
	}
	for(int i=1;i<m;i++){
		rep(j,n){
			if(!can[i][j])continue;
			int pre=-1;
			rep(k,n){
				if(k==j)continue;
				if(can[i-1][k]){
					pre=k;
					break;
				}
			}
			if(pre==-1)can[i][j]=false;
			else prev[i][j]=pre;
		}
	}
	rep(k,n)
	if(can[m-1][k]){
		ans.push_back(nam[k]+":"+ln[m-1]);
		int cur=k;
		for(int T=m-2;T>=0;T--){
			cur=prev[T+1][cur];
			ans.push_back(nam[cur]+":"+ln[T]);
		}
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		if(solve()){
			for(int k=ans.size()-1;k>=0;k--)
			cout<<ans[k]<<'\n';
		}else cout<<"Impossible\n";
	}
	return 0;
}