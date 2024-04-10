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
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
struct point{
	int x,y;
}p[3005],st[3005],a[3005];
int n,v[3005],m;

bool cmp(const point&a, const point&b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
double dist(const point &a,const point &b){
	return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}
double cross(const point&o, const point &a,const point &b){
	return 1.0*(a.x-o.x)*(b.y-o.y)-1.0*(a.y-o.y)*(b.x-o.x);
}
double work(){
	if(!m) return 0;
	if(m==1) return 0;
	if(m==2) return dist(a[0],a[1]);
	int top=0;
	for(int i=0;i<m;i++){
		while(top>=2&&cross(st[top-2],st[top-1],a[i])<0) top--;
		st[top++]=a[i];
	}
	int t=top+1;
	for(int i=m-2;~i;i--){
		while(top>=t&&cross(st[top-2],st[top-1],a[i])<0) top--;
		st[top++]=a[i];
	}
	double ret=0,d1,d2;
	st[top]=st[0];
	int k=1;
//	for(int i=0;i<top;i++) for(int j=i+1;j<top;j++) ret=max(ret,dist(st[i],st[j]));
//	return ret;
	for(int i=0;i<top;i++){
		while(cross(st[i],st[i+1],st[k])<cross(st[i],st[i+1],st[k+1])) k=(k+1)%top;
		d1=dist(st[i],st[k]);
		d2=dist(st[i+1],st[k]);
		ret=max(ret,max(d1,d2));
	}
	return ret;
}

int check(double mid){
	for(int i=1;i<=n;i++){
		m=0;
		for(int j=1;j<=n;j++) if(dist(p[i],p[j])>2.0*mid) a[m++]=p[j];
		if(work()>2.0*mid) return 1;
	}
	return 0;
}
int main(){
//	freopen("data.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
//	for(int i=1;i<=n;i++) cout << p[i].x <<" "<< p[i].y << endl;
	double l=0,r=2e4,mid;
	while(l+1e-6<r){
		mid=(l+r)/2.0;
		if(check(mid)) l=mid; else r=mid;
	}
	printf("%.10lf\n",0.5*(l+r));
	return 0;
}