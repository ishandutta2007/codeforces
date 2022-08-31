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
int cnt[15];
struct mat{
	vector<vector<int> > v;
	mat(){
	}
	mat(int n,int val){
		v.resize(n);
		rep(k,n)v[k].resize(n,0);
		rep(k,n)v[k][k]=val;
	}
	mat operator* (const mat& oth)const{
		mat ans(v.size(),0);
		rep(i,v.size())rep(j,v.size())rep(k,v.size())
		ans.v[i][j]=(ans.v[i][j]+ll(v[i][k])*oth.v[k][j]%INF)%INF;
		return ans;
	}
};
int main(){
	int n,b,x,m,c;
	scanf("%d%d%d%d",&n,&b,&m,&x);
	mat ans(x,1),cur(x,0);
	rep(k,n){
		scanf("%d",&c);
		cnt[c]++;
	}
	rep(i,x)rep1(j,9)
	cur.v[(i*10+j)%x][i]+=cnt[j];
	while(b){
		if(b&1)ans=ans*cur;
		cur=cur*cur;
		b>>=1;
	}
	printf("%d\n",ans.v[m][0]);
	return 0;
}