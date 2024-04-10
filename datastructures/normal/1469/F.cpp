#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int n,k,a[200005],_a[200005],ch[1000005],val[1000005]; 
inline void add(register int l,register int r){
	ch[l]++,ch[r+1]--;
	return;
}
inline bool check(register int maxn){
	memset(ch,0,sizeof(ch));
	memset(val,0,sizeof(val));
	for (register int i=1;i<=n;i++)a[i]=_a[i];
	register int num=1,now=n,i=0;
	val[0]=1;
	while(i<=maxn){
		if (val[i]==0){
			ch[i+1]+=ch[i];
			val[i+1]=ch[i+1];
			i++;
			continue;
		}
		a[now]=min(a[now],(maxn-i)*2-1);
		if (a[now]<=2||now==0)break;
		val[i]--;
		add(i+2,i+1+a[now]/2),add(i+2,i+1+(a[now]-1)/2);
		num+=a[now]-2,--now;
	}
	return num>=k;
}
signed main(){
	cin>>n>>k;
	for (register int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (register int i=1;i<=n;i++)_a[i]=a[i];
	register int l=1,r=1000000,ans=-1;
	while(l<=r){
		register int mid=(l+r)/2;
		if (check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl; 
	return 0;
}