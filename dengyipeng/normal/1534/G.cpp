#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 800005
#define ll long long
using namespace std;

int n,i,j,k;
struct node{ll x,y;} a[maxn];
int cmp(node a,node b){return a.x<b.x;}

priority_queue<ll,vector<ll>,less<ll> > p;
priority_queue<ll,vector<ll>,greater<ll> > q;

int read(){
	int x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main(){
	n=read();
	for(i=1;i<=n;i++) {
		int x=read(),y=read();
		a[i].x=x+y,a[i].y=x-y;
	}	
	sort(a+1,a+1+n,cmp);
	p.push(0),q.push(0);
	ll ans=0;
	for(i=1;i<=n;i++){
		ll x=a[i].x,y=a[i].y,L=p.top()-x,R=q.top()+x;
		if (L<=y&&y<=R) p.push(y+x),q.push(y-x); else
		if (y>R) p.push(R+x),q.pop(),q.push(y-x),q.push(y-x),ans+=abs(R-y); else 
		if (y<L) q.push(L-x),p.pop(),p.push(y+x),p.push(y+x),ans+=abs(L-y);
	}
	printf("%lld\n",ans/2);
}