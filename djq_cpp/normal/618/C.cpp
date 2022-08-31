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
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<=n;i++)
#define ALL(n) n.begin,n.end
#define SIZE(n) (int)(n.size())
#define ll long long
#define PB push_back
#define MP make_pair
#define IT iterator
#define pii pair<int,int>
#define ST first
#define ND second
const int inf=1e9+7;
const double eps=1e-9;
template<typename T>T max(T a,T b){return a>b?a:b;}
template<typename T>T min(T a,T b){return a<b?a:b;}
template<typename T>T abs(T n){return n>(T)(0)?n:-n;}
template<typename T>void swap(T a,T b){T t=a;a=b;b=t;}
using namespace std;
bool line(pii a,pii b,pii c){
	long long x=(long long)(a.ST-b.ST)*(long long)(b.ND-c.ND);
	long long y=(long long)(c.ST-b.ST)*(long long)(b.ND-a.ND);
	return x==y;
}
pair<pii,int> poi[200005];
int main(){
	int n;
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		scanf("%d%d",&poi[k].ST.ST,&poi[k].ST.ND);
		poi[k].ND=k+1;
	}
	sort(poi,poi+n);
	for(int k=0;k+2<n;k++)
	if(!line(poi[k].ST,poi[k+1].ST,poi[k+2].ST)){
		printf("%d %d %d",poi[k].ND,poi[k+1].ND,poi[k+2].ND);
		return 0;
	}
	printf("%d",line(MP(1,1),MP(2,2),MP(5,-1)));
	return 0;
}