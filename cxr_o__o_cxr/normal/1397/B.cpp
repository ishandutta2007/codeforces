#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,a[N],ans=1,mn,b[N];
signed main(){
	int ygg=clock();
	n=read();
	for(int i=0;i<n;i++){
		a[i]=read();
		mn+=a[i];
	}
	mn-=n;
	sort(a,a+n);
	for(int t=2,lg,x;;t++){
		lg=0;
		x=1e14;
		while(x&&lg<n){lg++;x/=t;}
		if(lg<n)break;
		b[0]=1;
		x=abs(b[0]-a[0]);
		for(int i=1;i<n;i++){
			b[i]=b[i-1]*t;
			x+=abs(b[i]-a[i]);
		}
		if(x<mn){mn=x;ans=t;}
		if((double)(clock()-ygg)/CLOCKS_PER_SEC>0.8)break;
	}
	cout<<mn<<"\n";
	return (0-0);
}