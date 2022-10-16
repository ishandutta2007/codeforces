#include <iostream>
#include <cstdio>
#define int unsigned long long
using namespace std;
int n,m,q,g;
struct node{
	int x,y;
}s,e;
int gcd(int n,int m){
	if (m==0)return n;
	return gcd(m,n%m);
}
void swp(int &a,int &b){
	int t=a;
	a=b;
	b=t;
	return;
}
void swp2(node &x,node &y){
	node t=x;
	x=y;
	y=t;
	return;
}
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>n>>m>>q;
	g=gcd(n,m);
	while(q--){
		cin>>s.x>>s.y>>e.x>>e.y;
		if (s.x!=e.x){
			if (s.x==2)swp2(s,e);
			int w=(s.y-1)/(n/g)+1;
			int a=w*(m/g),b=e.y;
			if (a>b)swp(a,b);
			int t=(a-1)/(m/g)+1;
			t*=m/g;
			if (t<b)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		if (s.x==e.x&&s.x==1){
			int a=s.y,b=e.y;
			if (a>b)swp(a,b);
			int t=(a-1)/(n/g)+1;
			t*=n/g;
			if (t<b)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		if (s.x==e.x&&s.x==2){
			int a=s.y,b=e.y;
			if (a>b)swp(a,b);
			int t=(a-1)/(m/g)+1;
			t*=m/g;
			if (t<b)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}