#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <random>
#include <ctime>
#define inf 2000000000
using namespace std;
mt19937 rnd(time(NULL));
int n,a[1000005],b[1000005],c[1000005],d[1000005];
int ansx,ansy;
void work(int l,int r,int xl,int xr,int yl,int yr){
	if (xl>xr||yl>yr)return;
	if (l==r){
		ansx=xl,ansy=yl;
		return;
	}
	int mid=(l+r)/2;
	int pl=xl,pr=xr,ql=yl,qr=yr;
	for (int i=l;i<=mid;i++)pl=max(pl,a[i]),ql=max(ql,b[i]),pr=min(pr,c[i]),qr=min(qr,d[i]);
	work(mid+1,r,pl,pr,ql,qr);
	pl=xl,pr=xr,ql=yl,qr=yr;
	for (int i=mid+1;i<=r;i++)pl=max(pl,a[i]),ql=max(ql,b[i]),pr=min(pr,c[i]),qr=min(qr,d[i]);
	work(l,mid,pl,pr,ql,qr);
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	work(1,n,-inf,inf,-inf,inf);
	cout<<ansx<<' '<<ansy<<endl;
	return 0;
}