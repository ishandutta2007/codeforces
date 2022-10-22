/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=2000;
int n,m,a,b;
int v[N+1];
vector<pair<int,int> > nei[N+1];
int dis1[N+1],dis2[N+1];
bool vis[N+1];
void dijkstra(int x,int dis[]){
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[x]=0;
	memset(vis,0,sizeof(vis));
	while(true){
		pair<int,int> mn(inf,0);
		for(int j=1;j<=n;j++)if(!vis[j])mn=min(mn,mp(dis[j],j));
		int y=mn.Y;
		if(!y)break;
		vis[y]=true;
		for(int j=0;j<nei[y].size();j++){
			int z=nei[y][j].X,len=nei[y][j].Y;
			dis[z]=min(dis[z],dis[y]+len);
		}
	}
//	printf("dis=");for(int i=1;i<=n;i++)cout<<dis[i]<<" ";puts("");
}
vector<int> nums1,nums2;
vector<int> hav1[N+1],hav2[N+1];
void discrete(vector<int> &nums,int dis[],vector<int> hav[]){
	nums.pb(-1);
	for(int i=1;i<=n;i++)nums.pb(dis[i]);
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=n;i++)hav[dis[i]=lower_bound(nums.begin(),nums.end(),dis[i])-nums.begin()].pb(i);
}
int Cnt1[N+1][N+1],Sum1[N+1][N+1],Cnt2[N+1][N+1];
int now1[N+1],now2[N+1],mx1[N+1],mn2[N+1];
int dp1[N+1][N+1],dp2[N+1][N+1];
signed main(){
	cin>>n>>m>>a>>b;
	int sum=0;
	for(int i=1;i<=n;i++)cin>>v[i],sum+=v[i];
	while(m--){
		int x,y,z;
		cin>>x>>y>>z;
		nei[x].pb(mp(y,z));nei[y].pb(mp(x,z));
	}
	dijkstra(a,dis1);dijkstra(b,dis2);
	discrete(nums1,dis1,hav1);discrete(nums2,dis2,hav2);
	for(int i=1;i<nums1.size();i++)for(int j=0;j<nums2.size();j++){
		Cnt1[i][j]=Cnt1[i-1][j];Sum1[i][j]=Sum1[i-1][j];
		for(int k=0;k<hav1[i].size();k++){
			bool ok=dis2[hav1[i][k]]>j;
			Cnt1[i][j]+=ok;Sum1[i][j]+=ok*v[hav1[i][k]];
		}
	}
	for(int i=1;i<nums2.size();i++)for(int j=0;j<nums1.size();j++){
		Cnt2[i][j]=Cnt2[i-1][j];
		for(int k=0;k<hav2[i].size();k++)Cnt2[i][j]+=dis1[hav2[i][k]]>j;
	}
	for(int i=0;i<=n;i++)now1[i]=nums1.size(),now2[i]=nums2.size(),mx1[i]=-inf,mn2[i]=inf;
	for(int i=nums1.size()-1;~i;i--)for(int j=nums2.size()-1;~j;j--){
		while(now1[j]&&Cnt1[now1[j]-1][j]>Cnt1[i][j])now1[j]--,mx1[j]=max(mx1[j],dp2[now1[j]][j]+Sum1[now1[j]][j]);
		dp1[i][j]=mx1[j]>-inf?mx1[j]-Sum1[i][j]:0;
		while(now2[i]&&Cnt2[now2[i]-1][i]>Cnt2[j][i])now2[i]--,mn2[i]=min(mn2[i],dp1[i][now2[i]]);
		dp2[i][j]=mn2[i]<inf?mn2[i]:0;
//		printf("dp1[%lld][%lld]=%lld dp2[%lld][%lld]=%lld\n",i,j,dp1[i][j],i,j,dp2[i][j]);
	}
	int ans=dp1[0][0];
	puts(ans<sum-ans?"Cry":ans==sum-ans?"Flowers":"Break a heart");
	return 0;
}
/*1
4 4
1 2
3 2 5 -11
1 4 2
3 4 2
3 1 5
3 2 1
*/
/*2
5 4
1 2
2 2 -5 -4 6
1 2 4
2 3 5
2 4 2
4 5 2
*/
/*3
2 1
1 2
-5 -5
1 2 10
*/