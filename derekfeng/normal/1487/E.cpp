#include<bits/stdc++.h>
using namespace std;
int n[4];
int a[4][150004];
int dat[600004];
void built(int *a,int l,int r,int id){
	if(l==r){
		dat[id]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	built(a,l,mid,id<<1),built(a,mid+1,r,id<<1|1);
	dat[id]=min(dat[id<<1],dat[id<<1|1]);
}
int got(int l,int r,int id,int a,int b){
	if(r<a||b<l)return 1e9;
	if(a<=l&&r<=b)return dat[id];
	int mid=(l+r)>>1;
	return min(got(l,mid,id<<1,a,b),got(mid+1,r,id<<1|1,a,b));
}
vector<int>g[150004];
int m,ans[150004];;
int main(){
	for(int i=0;i<4;i++)scanf("%d",&n[i]);
	for(int i=0;i<4;i++)for(int j=0;j<n[i];j++)scanf("%d",&a[i][j]);
	for(int i=0;i<n[0];i++)ans[i]=a[0][i];
	for(int i=0;i<3;i++){
		scanf("%d",&m);
		for(int j=0;j<n[i+1];j++)g[j].clear();
		for(int j=0;j<m;j++){
			int u,v;scanf("%d%d",&u,&v);
			g[v-1].push_back(u-1);
		}
		built(ans,0,n[i]-1,1);
		for(int j=0;j<n[i+1];j++){
			g[j].push_back(-1),g[j].push_back(n[i]);
			sort(g[j].begin(),g[j].end());
			ans[j]=1e9;
			for(int k=1;k<g[j].size();k++){
				int l=g[j][k-1],r=g[j][k];
				ans[j]=min(ans[j],got(0,n[i]-1,1,l+1,r-1));
			}
			ans[j]+=a[i+1][j];
		}
	}
	int res=1e9;
	for(int i=0;i<n[3];i++)res=min(res,ans[i]);
	if(res<1e9)printf("%d",res);
	else puts("-1");
}