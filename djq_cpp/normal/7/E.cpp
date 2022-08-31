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
string prior="+-*/";
map<string,int> prio;
// -1: suspicious
// 0: no operations
// 1: only */
// 2: have got +-
int parse(string S){
	int pos=0;
	while((pos=S.find(' '))!=-1)S.erase(S.begin()+pos);
	S="("+S+")";
	pos=1;
	int qcnt=0,res=0;
	while(pos<S.length()){
		if(S[pos]=='(')qcnt++;
		if(S[pos]==')')qcnt--;
		if(qcnt==0){
			if(S[pos]=='+'||S[pos]=='-')res=max(res,2);
			if(S[pos]=='*'||S[pos]=='/')res=max(res,1);
		}
		if(isalpha(S[pos])){
			char cl=S[pos-1];
			string cs;
			while(isalpha(S[pos])){
				cs.push_back(S[pos]);
				pos++;
			}
			char cr=S[pos];
			int pri=prio[cs];
			if(pri==-1)return -1;
			if(cl=='/'&&pri>=1||cl=='*'&&pri>=2)return -1;
			if(cr=='/'&&pri>=2||cr=='*'&&pri>=2)return -1;
			if(cl=='-'&&pri>=2)return -1;
			if(qcnt==0)res=max(res,pri);
		}else pos++;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string S1,S2;
	cin>>n;
	rep(k,n){
		cin>>S1;
		if(S1=="#")cin>>S1;
		cin>>S1;
		getline(cin,S2,'\n');
		prio[S1]=parse(S2);
	}
	getline(cin,S2,'\n');
	cout<<((parse(S2)==-1)?"Suspicious":"OK");
	return 0;
}