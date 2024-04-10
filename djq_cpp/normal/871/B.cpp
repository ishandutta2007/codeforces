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
int a[5005],b[5005],ca[5005],cb[5005],ans[5005];
bool check(int n){
	rep(k,n)if(cb[k]>=n||ca[cb[k]]!=k)return false;
	rep(k,n)ans[k]=ca[k];
	return true;
}
int main(){
	int n,cnt=0;
	scanf("%d",&n);
	rep(k,n){
		cout<<"? 0 "<<k<<'\n'<<flush;
		cin>>b[k];
	}
	rep(k,n){
		if(k==0)continue;
		cout<<"? "<<k<<" 0\n"<<flush;
		cin>>a[k];
		a[k]^=b[0];
	}
	rep(i,8191){
		rep(j,n)ca[j]=a[j]^i;
		rep(j,n)cb[j]=b[j]^i;
		if(check(n))cnt++;
	}
	cout<<"!\n"<<cnt<<'\n';
	rep(k,n)cout<<ans[k]<<' ';cout<<flush; 
	return 0;
}