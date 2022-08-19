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
#define open_in(n) freopen(n,"r",stdin)
#define open_out(n) freopen(n,"w",stdout)
#define debug(x) cerr<<#x<<'='<<x<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define REPup(i,m,n) for(int i=(m);i<=(n);i++)
#define REPdn(i,m,n) for(int i=(m);i>=(n);i--)
#define FOR(i,m,n,t) for(int i=(m);((t)>0)?(i<=(n)):(i>=(n));i+=t)
#define for_all(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
#define ALL(n) n.begin,n.end
#define SIZE(n) (int)((n).size())
#define PB push_back
#define MP make_pair
#define IT iterator
#define ST first
#define ND second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf=1e9+7;
const long long linf=1e17+7;
const double eps=1e-9;
double diagonal(double x,double y){return sqrt((x)*(x)+(y)*(y));}
int main(){
	ll n,m,a,i,k;
	scanf("%I64d%I64d%I64d",&n,&m,&a);
	if(n%a)
	i=ll(n/a)+1;
	else
	i=n/a;
	if(m%a)
	k=ll(m/a)+1;
	else
	k=m/a;
	printf("%I64d",i*k);
	
	return 0;
}