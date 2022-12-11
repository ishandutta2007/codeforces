#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace ZBK{
#define LL long long
const int N=2e5+50;
int n,g[N],num,ans[N];LL f[N];
struct node{int x,id;bool friend operator <(node a,node b){return a.x<b.x;}}a[N];
void main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+n+1);
	memset(f,0x3f,sizeof(f));f[0]=0;
	for(int i=3;i<=n;i++){
		for(int j=max(0,i-5);j<=i-3;j++){
			int mn=1e9,mx=0;
			for(int k=j+1;k<=i;k++)mn=min(mn,a[k].x),mx=max(mx,a[k].x);
			if(f[j]+mx-mn<f[i])f[i]=f[j]+mx-mn,g[i]=j;
		}
	}
	int p=n;
	while(p){
		num++;
		for(int i=g[p]+1;i<=p;i++)ans[a[i].id]=num;
		p=g[p];
	}
	printf("%I64d %d\n",f[n],num);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}
}
int main(){ZBK::main();return 0;}