#include <iostream>
#include <cstdio>
#define inf 1000000000
using namespace std;
int n,a[200005],b[200005];
int c[200005],d[200005],pre[200005],suf[200005];
int ans;
int calc(int l,int r){
	int v0=inf,v1=inf,s=0;
	for (int i=l;i<=r;i++){
		if (c[i]>v0&&c[i]>v1)return -1;
		if (v0<v1){
			if (c[i]<v0){
				if (d[i]==1)s++;
				v0=c[i];
			}
			else{
				if (d[i]==0)s++;
				v1=c[i];
			}
		}
		else{
			if (c[i]<v1){
				if (d[i]==0)s++;
				v1=c[i];
			}
			else{
				if (d[i]==1)s++;
				v0=c[i];
			}
		}
	}
	return min(s,r-l+1-s);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]<=n&&b[i]<=n){
			puts("-1");
			return 0;
		}
		if (a[i]>n&&b[i]>n){
			puts("-1");
			return 0;
		}
		if (a[i]<=n){
			c[a[i]]=b[i]-n;
			d[a[i]]=0;
		}
		if (b[i]<=n){
			c[b[i]]=a[i]-n;
			d[b[i]]=1;
		}
	}
	pre[0]=inf;
	for (int i=1;i<=n;i++)pre[i]=min(pre[i-1],c[i]);
	for (int i=n;i>=1;i--)suf[i]=max(suf[i+1],c[i]);
	int last=0;
	for (int i=1;i<=n;i++){
		if (pre[i]>suf[i+1]){
			int qwq=calc(last+1,i);
			if (qwq==-1){
				puts("-1");
				return 0;
			}
			ans+=qwq;
			last=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}