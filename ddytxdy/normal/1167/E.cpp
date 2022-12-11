#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1e6+50;
int n,x,l[N],r[N],y,lim,a[N],limm,minn=1e9,b[N],z;LL ans;
int main(){
//	freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&y);
		if(!l[y])l[y]=i;
		r[y]=i;
	}
//	for(int i=1;i<=x;i++)printf("%d %d\n",l[i],r[i]);
	for(int i=1;i<=x;i++)a[l[i]]=i;
	for(int i=2;i<=n;i++){
		a[i]=max(a[i],a[i-1]);
	}
	int minn=1e9;
	for(int i=x;i;i--){
		if(r[i]>minn){
			lim=i;break;
		}
		if(l[i])minn=min(l[i],minn);
	}
//	for(int i=2;i<=n;i++)
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
//	cout<<lim<<endl;
	lim=max(lim,1);
	for(int i=1;i<=x;i++){
//		cout<<max(lim,limm)<<" ";
//		cout<<i<<" "<<minn<<endl;
//		if(i>minn)break;
		ans+=x-max(i,max(lim,limm))+1;
		if(l[i]){
			if(l[i]<z)break;z=max(z,r[i]);
			limm=max(limm,a[r[i]]);
		}
	}
	cout<<ans;
	return 0;
}
//8 5
//4 1 1 4 5 2 4 3