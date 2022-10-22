#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n;
int a[N+1],b[N+1];
int main(){
	scanf("%d",&n);
	int cpy=n;
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[i]=a[i];
	sort(a+1,a+n+1);n=unique(a+1,a+n+1)-1-a;
	if(n<cpy)return puts("NO")&0;
	for(int i=1;i<=n;i++)b[i]=lower_bound(a+1,a+n+1,b[i])-a;
	int mx=0,mxid;
	for(int i=1;i<=n;i++)if(b[i]>mx)mx=b[i],mxid=i;
	int l=mxid,r=mxid,now=mx;
	while(l>1||r<n){
		if(l>1)
			if(b[l-1]==now-1){l--;now--;continue;}
		if(r<n)
			if(b[r+1]==now-1){r++;now--;continue;}
		return puts("NO")&0;
	}
	puts("YES");
	return 0;
}