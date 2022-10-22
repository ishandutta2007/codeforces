#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d,m,x,y;
ll res,a[100100],b[100100];
int main(){
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);
		if(t>m)a[++x]=t;
		else b[++y]=t;
	}
	d++;
	sort(a+1,a+x+1),reverse(a+1,a+x+1);
	sort(b+1,b+y+1),reverse(b+1,b+y+1);
//	for(int i=1;i<=x;i++)printf("%d ",a[i]);puts("");
//	for(int i=1;i<=y;i++)printf("%d ",b[i]);puts("");
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=n;i++)b[i]+=b[i-1];
	for(int i=0,t;i<=y;i++){
		if(!((n-i)%d))t=(n-i)/d;
		else t=(n-i)/d+1;
		res=max(res,b[i]+a[t]);
	}
	printf("%I64d\n",res);
	return 0;
}