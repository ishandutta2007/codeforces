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
int l[100005],r[100005],prime,n;
int range_div(int L,int R,int div){
	return (int)(R/div)-(int)((L-1)/div);
}
int not_div(int L,int R,int div){
	return (R-L+1)-range_div(L,R,div);
}
double neighboor(int k){
	int fst=not_div(l[k],r[k],prime);
	int snd=not_div(l[(k+1)%n],r[(k+1)%n],prime);
	double x=(double)fst/(double)(r[k]-l[k]+1),y=(double)snd/(double)(r[(k+1)%n]-l[(k+1)%n]+1);
	return ((double)(1)-x*y)*(double)2000;
}
int main(){
	double ans=0;
	scanf("%d%d",&n,&prime);
	rep(k,n)scanf("%d%d",&l[k],&r[k]);
	rep(k,n)ans+=neighboor(k);
	printf("%lf",ans);
	return 0;
}