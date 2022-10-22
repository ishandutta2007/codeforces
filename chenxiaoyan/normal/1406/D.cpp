/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=100000;
int n;
int a[N+1];
int qu;
int d[N+1];
int calc(int now,int x){
	int res=inf;
	for(int i=now-3;i<=now+3;i++)res=min(res,max(i+x,a[1]-i));
	return res;
}
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
	int x=0;
	for(int i=1;i<n;i++)if(d[i]>0)x+=d[i];
	cout<<calc(a[1]-x>>1,x)<<"\n";
	cin>>qu;
	while(qu--){
		int l,r,v;
		scanf("%lld%lld%lld",&l,&r,&v);
		if(l==1)a[1]+=v;
		if(l-1&&d[l-1]>0)x-=d[l-1];
		if(r<n&&d[r]>0)x-=d[r];
		d[l-1]+=v,d[r]-=v;
		if(l-1&&d[l-1]>0)x+=d[l-1];
		if(r<n&&d[r]>0)x+=d[r];
		printf("%lld\n",calc(a[1]-x>>1,x));
	}
}
signed main(){
	int testnum=1;
//	cin>>testnum;
	while(testnum--)mian();
	return 0;
}