#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
struct node{
	int l,r;
}a[10005];
inline bool cmp(node a,node b){
	return a.l+a.r<b.l+b.r;
}
int n,m,k,pre[2005][2005],suf[2005][2005],ans;
inline int calc(int l1,int r1,int l2,int r2){
	return max(0ll,min(r1,r2)-max(l1,l2)+1);
}
signed main(){
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)cin>>a[i].l>>a[i].r;
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=n-k+1;i++){
		for (int j=1;j<=m;j++)
			pre[i][j]=pre[i][j-1]+calc(i,i+k-1,a[j].l,a[j].r);
		for (int j=m;j>=1;j--)
			suf[i][j]=suf[i][j+1]+calc(i,i+k-1,a[j].l,a[j].r);
	}
	for (int i=1;i<=n-k+1;i++){
		int now=0;
		for (int j=i;j<=n-k+1;j++){
			while(((2*j+k-1)-(a[now].l+a[now].r))>=((a[now].l+a[now].r)-(2*i+k-1))&&now<=m)now++;
			ans=max(ans,pre[i][now-1]+suf[j][now]); 
		}
	}
	cout<<ans<<endl;
	return 0;
}