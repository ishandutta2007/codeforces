/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N=200000;
int n;
int a[N+1],b[N+1];
vector<pair<int,pair<int,int> > > nei[N+1];
int cnt[N+1];
bool vis[N+1];
vector<int> zero,one;
int st,to;
void dfs(int x){// 
	vis[x]=true;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i].X,z=nei[x][i].Y.X,xx=nei[x][i].Y.Y;
		if(!vis[y]){
			if(x==st)to=y;
			dfs(y);
			if(xx)one.pb(z);else zero.pb(z);
		}
	}
}
void mian(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cnt[i]=0,nei[i].clear(),vis[i]=false;
	for(int i=1;i<=n;i++)scanf("%d",a+i),cnt[a[i]]++;
	for(int i=1;i<=n;i++)scanf("%d",b+i),cnt[b[i]]++;
	for(int i=1;i<=n;i++)if(cnt[i]!=2)return puts("-1"),void();// 
	for(int i=1;i<=n;i++)nei[a[i]].pb(mp(b[i],mp(i,1))),nei[b[i]].pb(mp(a[i],mp(i,0)));// 
	vector<int> ans;
	for(int i=1;i<=n;i++)if(!vis[i]){
		one.clear(),zero.clear(),st=i,dfs(i);
		if(one.empty()&&zero.empty())continue;//1 
		if(nei[st][0].X==nei[st][1].X){//2 
			if(nei[st][0].Y.Y==nei[st][1].Y.Y)ans.pb(nei[st][0].Y.X);
			continue;
		}
		int id=nei[st][0].X==to?1:0;
		if(nei[st][id].Y.Y)zero.pb(nei[st][id].Y.X);else one.pb(nei[st][id].Y.X);
		if(one.size()<zero.size())for(int i=0;i<one.size();i++)ans.pb(one[i]);
		else for(int i=0;i<zero.size();i++)ans.pb(zero[i]);// 
	}
	printf("%d\n",int(ans.size()));
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}