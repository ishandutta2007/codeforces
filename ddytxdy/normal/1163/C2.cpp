#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1010;
const double eps=1e-10;
struct node{
	double k,b;
	bool friend operator <(node x,node y){
		return abs(x.k-y.k)>eps?(x.k<y.k):(x.b<y.b);
	}
}l[N*N];
int n,x[N],y[N],n1,num,n2,a[N*N],now,num1;bool vis[20050];LL ans,ans1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(x[j]==x[i]){
				if(!vis[x[j]+10000])n1++;
				vis[x[j]+10000]=1;
			}
			else l[++num].k=1.0*(y[j]-y[i])/(x[j]-x[i]),l[num].b=y[j]-x[j]*l[num].k;
	sort(l+1,l+num+1);
	l[0].k=-1e18;
	for(int i=1;i<=num;i++){
		if(abs(l[i].k-l[i-1].k)>eps)n2++,a[++num1]=1;
		else if(abs(l[i].b-l[i-1].b)>eps)n2++,a[num1]++;
	}
	ans=1ll*n2*n1;
	for(int i=1;i<=n2;i++)ans1+=1ll*a[i]*(n2-a[i]);
	cout<<ans+ans1/2;
	return 0;
}