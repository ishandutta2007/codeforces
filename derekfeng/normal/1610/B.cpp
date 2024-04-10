#include<bits/stdc++.h>
using namespace std;
int T,n,a[200004],b[200004],m;
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	bool ok=1;
	for(int i=1;i<=n;i++)if(a[i]!=a[n-i+1])ok=0;
	if(ok){
		puts("YES");
		return;
	}
	int x=a[1];
	m=0,ok=1;
	for(int i=1;i<=n;i++)if(a[i]!=x)b[++m]=a[i];
	for(int i=1;i<=m;i++)if(b[i]!=b[m-i+1])ok=0;
	if(ok){
		puts("YES");
		return;
	}
	int lst,y1,y2;
	for(int i=n;i;i--)if(a[i]==x){lst=i;break;}
	if(lst<n)y1=a[lst+1],y2=a[lst+1];
	else{
		for(int l=1,r=n;l<r;l++,r--)if(a[l]!=a[r]){
			y1=a[l],y2=a[r];
			break;
		}
	}
	m=0,ok=1;
	for(int i=1;i<=n;i++)if(a[i]!=y1)b[++m]=a[i];
	for(int i=1;i<=m;i++)if(b[i]!=b[m-i+1])ok=0;
	if(ok){
		puts("YES");
		return;
	}
	m=0,ok=1;
	for(int i=1;i<=n;i++)if(a[i]!=y2)b[++m]=a[i];
	for(int i=1;i<=m;i++)if(b[i]!=b[m-i+1])ok=0;
	if(ok){
		puts("YES");
		return;
	}
	puts("NO");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}