#include<cstdio>
#include<vector>
const int N=4003,L=10003;
int n,l,m,ans[L+L],dp0[L][N],dp1[N];
struct item{int v,w;};
std::vector<item>b[L+L];
struct query{int m,p;};
std::vector<query>q[L+L];
int main(){
	item tmp;int x,y;
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
	  scanf("%d%d%d",&tmp.w,&tmp.v,&x),b[x].push_back(tmp);
	scanf("%d",&m);
	for(int j=1;j<=m;j++)
	  scanf("%d%d",&x,&y),q[x].push_back((query){y,j});
	for(int i=0;i<L+L;i+=l){
	  for(int p=0;p<N;p++)dp1[p]=0;
	  for(int j=1;j<=l&&i+j<L+L;j++){
		for(int k=0;k<b[i+j].size();k++)
		  for(int p=N-1;p>=b[i+j][k].w;p--)
			dp1[p]=std::max(dp1[p],dp1[p-b[i+j][k].w]+b[i+j][k].v);
		for(int k=0;k<q[i+j].size();k++)
		  for(int p=0;p<=q[i+j][k].m;p++)
			ans[q[i+j][k].p]=std::max(ans[q[i+j][k].p],dp1[p]+dp0[j+1][q[i+j][k].m-p]);
	  }
	  if(i+l<L+L)for(int j=l;j>=1;j--){
		for(int p=N-1;p>=0;p--)
		  dp0[j][p]=dp0[j+1][p];
		for(int k=0;k<b[i+j].size();k++)
		  for(int p=N-1;p>=b[i+j][k].w;p--)
			dp0[j][p]=std::max(dp0[j][p],dp0[j][p-b[i+j][k].w]+b[i+j][k].v);
	  }
	}
	for(int j=1;j<=m;j++)printf("%d\n",ans[j]);
	return 0;
}