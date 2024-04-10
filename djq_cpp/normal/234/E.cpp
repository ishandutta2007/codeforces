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
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
int n,gps;
int rnd,a,b,c;
vector<string> chp[4],grp[20];
vector<pair<int,string> > allt;
int get_rnd(){
	return rnd=(rnd*a+b)%c;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int rat;string s;
	cin>>n>>rnd>>a>>b>>c;
	rep(k,n){
		cin>>s>>rat;
		allt.push_back(MP(-rat,s));
	}
	sort(allt.begin(),allt.end());
	rep(i,4)rep(j,n/4)chp[i].push_back(allt[i*n/4+j].second);
	rep(i,n/4){
		vector<string> ans;
		rep(j,4){
			int pos=get_rnd()%chp[j].size();
			ans.push_back(chp[j][pos]);
			chp[j].erase(chp[j].begin()+pos);
		}
		cout<<"Group "<<(char)(i+'A')<<':'<<endl;
		rep(k,4)cout<<ans[k]<<endl;
	}
	return 0;
}