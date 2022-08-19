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
struct poly{
	vector<int> v;
	poly(int sz=0){
		v.resize(sz,0);
	}
	poly(const poly& oth){
		v=oth.v;
	}
	poly operator+(const poly& oth){
		poly ans(max(v.size(),oth.v.size()));
		rep(k,v.size())ans.v[k]+=v[k];
		rep(k,oth.v.size())ans.v[k]+=oth.v[k];
		return ans;
	}
	poly mul_x(){
		poly ans;
		ans=*this;
		ans.v.insert(ans.v.begin(),0);
		return ans;
	}
	poly mul_inv(){
		poly ans;
		ans=*this;
		rep(k,ans.v.size())ans.v[k]=-ans.v[k];
		return ans;
	}
	void output(){
		printf("%d\n",v.size()-1);
		rep(k,v.size())printf("%d ",v[k]);putchar('\n');
	}
};
poly x(1),y(1);
int main(){
	x.v[0]=1;
	y.v[0]=0;
	int n;
	scanf("%d",&n);
	rep(k,n){
		y=x.mul_x()+y;
		rep(k,y.v.size())if(y.v[k]<-1||y.v[k]>1){
			y=x.mul_x()+x.mul_x()+y.mul_inv();
			break;
		}
		swap(x,y);
	}
	x.output();
	y.output();
	return 0;
}