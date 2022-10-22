#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,mid;
long long a[1000010],ch[1000010],s[1000010],ql,qr;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i)ch[i]=a[i+1]-a[i];
	ch[n]=1e18,sort(ch+1,ch+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+ch[i];
	scanf("%d",&q);
	while(q--){
		scanf("%I64d%I64d",&ql,&qr);
		qr-=ql-1,l=1,r=n;
		while(l<r)mid=l+r>>1,ch[mid]<qr?l=mid+1:r=mid;
		printf("%I64d ",s[l-1]+(n-l+1)*qr);
	}
	return 0;
}