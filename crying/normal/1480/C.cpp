#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
typedef double db;
const int MAXN=1e5+10,INF=2e9;
int n,a[MAXN];
int req(int x){
	if(a[x]!=INF)return a[x];
	printf("? %d\n",x);fflush(stdout);
	scanf("%d",&a[x]);
	return a[x];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)a[i]=INF;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		int x=req(mid),y=req(mid+1);
		if(x<y)r=mid;
		else l=mid+1;
	}
	printf("! %d",l);
	return 0;
}