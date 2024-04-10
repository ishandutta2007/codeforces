#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e3+4;
struct node{
	int x,id;
}a[N];
int n;
inline bool comp(const node &e,const node &y){
	return e.x<y.x;
}
long long ans=0;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].x=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1,comp);
	for(int i=n;i;i--){
		ans+=(long long)(n-i)*a[i].x+1;
	}
	cout<<ans<<endl;
	for(int i=n;i;i--)
		printf("%d ",a[i].id);
	return (0-0);
}