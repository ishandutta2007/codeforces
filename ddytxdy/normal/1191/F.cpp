#include<bits/stdc++.h>
#define lowbit(x) x&-x
#define LL long long
using namespace std;
const int N=2e5+50;
int n,c[N],m,f[N],num,b[N];LL ans;
int read(){
	int x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=10*x+c-'0',c=getchar();
	return x;
}
struct node{
	int x,y;
	bool friend operator <(node a,node b){
		return a.y!=b.y?a.y>b.y:a.x<b.x;
	}
}a[N];
void add(int x){for(;x<=m;x+=lowbit(x))f[x]++;}
int ask(int x){
	int ret=0;
	for(;x;x-=lowbit(x))ret+=f[x];
	return ret;
}
bool no(int x){
	return ask(x)-ask(x-1)==0;
}
int main(){
	n=read();
	for(int i=1,x;i<=n;i++){
		x=read();a[i].y=read();a[i].x=c[i]=x;
	}
	sort(c+1,c+n+1);m=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++)a[i].x=lower_bound(c+1,c+m+1,a[i].x)-c;
	sort(a+1,a+n+1);
	for(int i=1,k;i<=n;i++){
		k=i;
		while(k<n&&a[k+1].y==a[k].y)k++;
		for(int j=i;j<=k;j++)if(no(a[j].x))add(a[j].x),num++;
		b[i-1]=0;
		for(int j=i;j<=k;j++)b[j]=ask(a[j].x);
		for(int j=i;j<=k;j++)ans+=1ll*(b[j]-b[j-1])*(num-b[j]+1);
		i=k;
	}
	cout<<ans;
	return 0;
}