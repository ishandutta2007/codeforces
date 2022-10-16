#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 1000000007
#define int long long
using namespace std;
int n,k,a[1000005],lg_2[1000005],st[1000005][21];
int ask(int l,int r){
	if (l>r)return 0;
	int w=lg_2[r-l+1];
	return max(st[l][w],st[r-(1<<w)+1][w]);
}
int tail,val[1000005],cnt[1000005],sval[1000005],scnt[1000005];
int ans[1000005],sum;
void ins(int x,int y){
	while(tail&&val[tail]<=x)y+=cnt[tail],tail--;
	++tail;
	val[tail]=x,cnt[tail]=y;
	sval[tail]=sval[tail-1]+x*y;
	scnt[tail]=scnt[tail-1]+y;
	return;
}
signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=2;i<=n;i++)
		if (i==(i&(-i)))lg_2[i]=lg_2[i-1]+1;
		else lg_2[i]=lg_2[i-1];
	for (int i=1;i<=n;i++)st[i][0]=a[i];
	for (int i=1;i<=20;i++)
		for (int j=1;j+(1<<i)-1<=n;j++)
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for (int i=n;i>=n-k+2&&i>=1;i--){
		tail=0;
		for (int j=i;j>=1;j-=k-1){
			if (j+(k-1)>n)continue;
			ins(ask(j+1,min(j+(k-1),n)),1);
			int l=1,r=tail,pos=tail+1;
			while(l<=r){
				int mid=(l+r)/2;
				if (val[mid]<=a[j])pos=mid,r=mid-1;
				else l=mid+1;
			}
			ans[j]=a[j]*(scnt[tail]-scnt[pos-1])+sval[pos-1];
			ans[j]%=mod;
		}
	}
	for (int i=1;i<=n;i++)sum+=ans[i],sum%=mod;
	cout<<sum<<endl;
	return 0;
}