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
#include <conio.h>
#include <memory.h>
#include <windows.h>
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
map<string,int>num;
string nam[20];
vector<pii>nw;
int pls[100005];
bool bitfrom(int mask,int bitn){
	return (mask>>bitn)&1;
}
int main(){
	int n,m,ans=0;
	string x,y;
	cin>>n>>m;
	rep(k,n){
		cin>>x;
		nam[k]=x;
		num[x]=k;
	}
	rep(k,m){
		cin>>x>>y;
		nw.push_back(MP(num[x],num[y]));
	}
	for(int mask=1;mask<(1<<n);mask++){
		pls[mask]=mask%2+pls[mask/2];
		bool isok=true;
		rep(k,nw.size())
		if(bitfrom(mask,nw[k].first)&&bitfrom(mask,nw[k].second)){
			isok=false;
			break;
		}
		if(isok&&pls[ans]<pls[mask])ans=mask;
	}
	cout<<pls[ans]<<endl;
	vector<string>names;
	rep(k,n)
	if(bitfrom(ans,k))
	names.push_back(nam[k]);
	sort(names.begin(),names.end());
	rep(k,names.size())
	cout<<names[k]<<endl;
	return 0;
}