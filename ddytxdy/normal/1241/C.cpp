#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int t,n,p[N],x,a,y,b,c[N],d[N];LL k,now;
bool cmp(int x,int y){return x>y;}
bool check(int x){
	memcpy(d,c,sizeof(c));
	sort(d+1,d+x+1,cmp);
	LL now=0;
	for(int i=1;i<=x;i++)now+=p[i]/100*d[i];
	return now>=k;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	sort(p+1,p+n+1,cmp);
	scanf("%d%d%d%d",&x,&a,&y,&b);cin>>k;
	for(int i=1;i*a<=n;i++)c[i*a]+=x;
	for(int i=1;i*b<=n;i++)c[i*b]+=y;
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)c[i]=0;
}
int main(){
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}