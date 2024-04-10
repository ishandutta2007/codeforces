#include<bits/stdc++.h>
using namespace std;

int n;
int F(int k) {
	cout<<"? "<<k<<endl;
	int x,y;
	cin>>x;
	cout<<"? "<<(k+n/2-1)%n+1<<endl;
	cin>>y;
	return x-y;
}
int main() {
	cin>>n;
	int l=1,r=n,mid,x,y,z;
	if (!(x=F(1)))
		return cout<<"! 1"<<endl,0;
	if (!(y=F(n)))
		return cout<<"! "<<n<<endl,0;
	while (l+1<r) {
		mid=(l+r)>>1;
		z=F(mid);
		if (!z)
			return cout<<"! "<<mid<<endl,0;
		if ((x>0)==(z>0))
			l=mid,x=z;
		else
			r=mid,y=z;
	}
	cout<<"! -1"<<endl;
	return 0;
}/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,l,r,x,y;
int ask(int x) { printf("? %d\n",x);fflush(stdout);int y;scanf("%d",&y);return y; }
int ret(int x) {printf("! %d\n",x);fflush(stdout);exit(0);}
int main() 
{
	scanf("%d",&n);
	int l=2,r=n/2;
	if(n%4==2) ret(-1);
	int x=ask(1),y=ask(1+n/2);
	if(x==y) ret(1);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int a=ask(mid),b=ask(mid+n/2);
		if(a==b) ret(mid);
		if((x<y)^(a<b)) r=mid-1; else l=mid+1;
	}
	ret(-1);
	return 0;
}
*/
/* 
6 
1 2 3 1 4 5
*/