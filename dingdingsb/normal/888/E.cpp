#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000+10],ans;
int sum[2][1000000],cnt[2];
inline void dfs(int now,int lst,int val,int type){
	if(now>lst){
		sum[type][++cnt[type]]=val;
		return;
	}dfs(now+1,lst,val,type);
	dfs(now+1,lst,(val+a[now])%m,type);
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,n>>1,0,0);
	dfs((n>>1)+1,n,0,1);
	sort(sum[0]+1,sum[0]+cnt[0]+1);
	sort(sum[1]+1,sum[1]+cnt[1]+1);
	for(int i=1;i<=cnt[0];i++){
		int tl=1,tr=cnt[1],p=-1;
		while(tl<=tr){
			int mid=tl+tr>>1;
			if(sum[0][i]+sum[1][mid]>=m)
				tr=mid-1;
			else tl=mid+1,p=mid;
		}
		if(p==-1)ans=max(ans,sum[0][i]+sum[1][cnt[1]]);
		else ans=max(ans,sum[0][i]+sum[1][p]);
	} cout<<ans;
}