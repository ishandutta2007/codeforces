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
string sc,ap;
int main(){
	int n,t,id;
	cin>>n>>t>>sc;
	for(id=0;id<n;id++)if(sc[id]=='.')break;
	if(id==n){
		cout<<sc;
		return 0;
	}
	ap=sc.substr(id+1);
	sc=sc.substr(0,id);
	int lst=0;
	pii fa=MP(-1,-1);
	bool have=false;
	rep(k,ap.size()){
		if(ap[k]<='3')have=false;
		else{
			if(!have){
				have=true;
				lst=k;
			}
			if(ap[k]>='5'){
				fa=MP(lst,k);
				break;
			}
		}
	}
	if(!have)cout<<sc<<'.'<<ap;
	else{
		id=fa.second;
		while(t--){
			ap[id--]='0';
			if(id<fa.first)break;
		}
		if(id<0){
			id=sc.length()-1;
			sc[id]++;
			while(sc[id]>'9'){
				sc[id]='0';
				if(id==0){
					sc='1'+sc;
					break;
				}
				id--;
				sc[id]++;
			}
			cout<<sc;
		}else{
			ap[id]++;
			cout<<sc<<'.';
			for(int k=0;k<=id;k++)cout<<ap[k];
		}
	}
}