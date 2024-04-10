#include<bits/stdc++.h>
using namespace std;
const int N=5+4e5;
int rev[N],w[N];
bool vis[N];
int solve(int& l,int& r){
	int len=0;
	if(rev[l]==r){
		l++; r--;
		return 0;
	}
	int la=l,lb=rev[l],ra=r,rb=rev[r],ans=w[l]+w[r];
	vis[l]=vis[rev[l]]=vis[r]=vis[rev[r]]=1; len=2;
	int p0=l,p1=r;
	while(1){
		while(vis[p0]&&p0<=r) ++p0;
		while(vis[p1]&&p1>=l) --p1;
		if(p0>=p1) break;
		if(la>p0){ 
			if(rb>p0||ra<rev[p0]) return -1;
			ans+=1-w[p0];
			rb=p0,ra=rev[p0];
			vis[p0]=vis[rev[p0]]=1;
			++len;
			continue;
		}
		if(rb>p0){
			if(la>p0||lb<rev[p0]) return -1;
			ans+=w[p0];
			la=p0,lb=rev[p0];
			vis[p0]=vis[rev[p0]]=1;
			++len;
			continue;
		}
		if(lb<p1){
			if(ra<p1||rb>rev[p1]) return -1;
			ans+=w[p1];
			ra=p1,rb=rev[p1];
			vis[p1]=vis[rev[p1]]=1;
			++len;
			continue;
		}
		if(ra<p1){
			if(lb<p1||la>rev[p1]) return -1;
			ans+=1-w[p1];
			lb=p1; la=rev[p1];
			vis[p1]=vis[rev[p1]]=1;
			++len;
			continue;
		}
		break;
	}
	if(la>ra||lb<rb) return -1;
//	printf("<%d %d %d %d>",la,ra,lb,rb);
	l+=len,r-=len;
//	printf("[%d %d %d %d]",l,r,len,min(ans,len-ans));
	return min(ans,len-ans);
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int a,b; scanf("%d%d",&a,&b);
		rev[a]=b; rev[b]=a; w[a]=0; w[b]=1;
	}
	int l=1,r=n+n,ans=0;
	while(l<=r){
		int k=solve(l,r);
		if(k==-1){
			printf("-1");
			exit(0);
		}else ans+=k;
	}
	printf("%d\n",ans);
	return 0;
}