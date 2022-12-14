#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define cl(x,a) memset(x,a,sizeof(x))
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
const int mo = 1e9 + 7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

double aa,bb,cc,dd;
long double l=0,r=1e10,mid,a,b,c,d;
long double f[4],g[4];
int check(){
	f[0]=(a-mid)*(d-mid);
	f[1]=(a-mid)*(d+mid);
	f[2]=(a+mid)*(d-mid);
	f[3]=(a+mid)*(d+mid);
	g[0]=(b-mid)*(c-mid);
	g[1]=(b-mid)*(c+mid);
	g[2]=(b+mid)*(c-mid);
	g[3]=(b+mid)*(c+mid);
	sort(f,f+4);
	sort(g,g+4);
	if(f[3]<g[0] || g[3]<f[0]) return 0;
	return 1;
}
int main(){
	scanf("%lf%lf%lf%lf",&aa,&bb,&cc,&dd);
	a=(long double)aa;
	b=(long double)bb;
	c=(long double)cc;
	d=(long double)dd;
	
	while(l+1e-10<r){
		mid=(l+r)/2.0;
		if(check()) r=mid; else l=mid;
	}
	printf("%.10lf\n",(double)mid);
	return 0;
}