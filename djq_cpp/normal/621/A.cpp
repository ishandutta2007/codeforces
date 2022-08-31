#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#define open_in(n) freopen(n,"r",stdin)
#define open_out(n) freopen(n,"w",stdout)
#define debug(x) cout<<#x<<'='<<x<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,m,n) for(int i=(m);i<=(n);i++)
#define FOR(i,m,n,t) for(int i=(m);((t)>0)?(i<=(n)):(i>=(n));i+=t)
#define for_all(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
#define ALL(n) n.begin,n.end
#define SIZE(n) (int)((n).size())
#define ll long long
#define PB push_back
#define MP make_pair
#define IT iterator
const int inf=1e9+7;
const long long linf=1e17+7;
const double eps=1e-9;
using namespace std;
int main(){
	long long n,in,res=0,sodd=linf;
	scanf("%I64d",&n);
	for(int k=0;k<n;k++){
		scanf("%I64d",&in);
		res+=in;
		if(in%2&&in<sodd)sodd=in;
	}
	printf("%I64d",(res%2)?(res-sodd):res);
	return 0;
}